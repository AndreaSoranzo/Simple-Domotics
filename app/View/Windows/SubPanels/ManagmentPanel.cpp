#include "ManagmentPanel.h"

#include <QFileDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

void ManagmentPanel::UpdateLayout() {
    int panelHeight = height();
    int colums = panelHeight < 530 ? configurationBtns.size() : 1;
    // dont need to remove the items first because  the ownership belongs to the same layout and the widgets don't change
    for (int i = 0; i < configurationBtns.size(); i++) {
        btnLayout->addWidget(configurationBtns[i], i / colums, i % colums);
    }
}

QWidget* ManagmentPanel::CreateButton(const QString& text, const QString& iconPath, int width, int height, void (ManagmentPanel::*slot)()) const {
    QWidget* content = new QWidget();
    QVBoxLayout* buttonAddLayout = new QVBoxLayout(content);
    buttonAddLayout->setAlignment(Qt::AlignCenter);

    QPushButton* btn = new QPushButton();
    btn->setObjectName("configBtn");
    btn->setFocusPolicy(Qt::NoFocus);
    btn->setIcon(QIcon(iconPath));
    btn->setIconSize(QSize(width - 50, width - 50));
    btn->setFixedSize(width, height);
    QLabel* addLabel = new QLabel(text);
    addLabel->setAlignment(Qt::AlignCenter);

    buttonAddLayout->addWidget(btn, 0, Qt::AlignCenter);
    buttonAddLayout->addWidget(addLabel);

    connect(btn, &QPushButton::clicked, this, slot);

    return content;
}

ManagmentPanel::ManagmentPanel(QWidget* parent) : QWidgetFix(parent) {
    QHBoxLayout* contentLayout = new QHBoxLayout(this);

    btnLayout = new QGridLayout();
    btnLayout->setSpacing(10);

    QWidget* addBtn = CreateButton("Add Sensor", ":assets/icons/add_sensor.svg", 200, 200, &ManagmentPanel::OnAddSensor);
    QWidget* saveBtn = CreateButton("Save Configuration", ":assets/icons/save.svg", 170, 170, &ManagmentPanel::SaveJson);
    QWidget* openBtn = CreateButton("Load Configuration", ":assets/icons/load.svg", 170, 170, &ManagmentPanel::OpenJson);

    configurationBtns.append(saveBtn);
    configurationBtns.append(openBtn);

    btnLayout->addWidget(saveBtn, 0, 0);
    btnLayout->addWidget(openBtn, 1, 0);

    QWidget* lineSeparator = new QWidget();
    lineSeparator->setObjectName("lineSeparator");
    lineSeparator->setFixedSize(5, 300);

    contentLayout->addWidget(addBtn);
    contentLayout->addWidget(lineSeparator);
    contentLayout->addLayout(btnLayout);

    UpdateLayout();
}

void ManagmentPanel::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);
    UpdateLayout();
}

void ManagmentPanel::OpenJson() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open Json", "./", "JSON files (*.json)");
    if (!fileName.isEmpty()) {
        emit OnLoad(fileName);
    }
}

void ManagmentPanel::SaveJson() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save sensors", "./", "JSON files (*.json)");
    if (!fileName.isEmpty()) {
        // add/force extension
        int dotPos = fileName.indexOf(".");
        if (dotPos != -1) {
            fileName = fileName.mid(0, dotPos) + ".json";
        } else {
            fileName += ".json";
        }
        emit OnSave(fileName);
    }
}
