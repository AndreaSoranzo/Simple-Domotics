#include "SearchPanel.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "../../../Utils/TypeHelper.h"

SearchPanel::SearchPanel(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* searchInputLay = new QVBoxLayout(this);

    QHBoxLayout* inputLay = new QHBoxLayout();

    QLabel* searchTitle = new QLabel("Search");
    searchTitle->setObjectName("subtitle");
    searchInput = new QLineEdit();
    perfectMatch = new QCheckBox("Match");
    typeFilter = new QComboBox();

    typeFilter->addItem("");
    for (const std::string& sensorName : TypeHelper::GetAllSensorNames()) {
        typeFilter->addItem(QString::fromStdString(sensorName));
    }

    inputLay->addWidget(searchInput, 2);
    inputLay->addWidget(perfectMatch);
    inputLay->addWidget(typeFilter, 1);

    resultsLabel = new QLabel();

    searchInputLay->addWidget(searchTitle);
    searchInputLay->addLayout(inputLay);
    searchInputLay->addWidget(resultsLabel);

    connect(this, &SearchPanel::TriggerSearch, this, [&]() -> void { emit OnSearch(searchInput->text(), typeFilter->currentText(), perfectMatch->isChecked()); });

    connect(searchInput, &QLineEdit::textChanged, this, [&]() -> void { emit OnSearch(searchInput->text(), typeFilter->currentText(), perfectMatch->isChecked()); });
    connect(perfectMatch, &QCheckBox::stateChanged, this, [&]() -> void {
        if (!searchInput->text().isEmpty()) {
            emit OnSearch(searchInput->text(), typeFilter->currentText(), perfectMatch->isChecked());
        }
    });
    connect(typeFilter, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [&]() -> void { emit OnSearch(searchInput->text(), typeFilter->currentText(), perfectMatch->isChecked()); });
}

void SearchPanel::ClearInput() {
    searchInput->setText("");
    perfectMatch->setChecked(false);
    typeFilter->setCurrentIndex(0);
}

void SearchPanel::UpdateResults(unsigned int number) {
    resultsLabel->setText("Results : " + QString::number(number));
}
