#include "SensorListBox.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "../../Utils/RenderSvg.h"

SensorListBox::SensorListBox(unsigned int id, const QString& iconPath, const QString& name, const QString& type, QWidget* parent) : AbstractSensorBox(id, parent) {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    QHBoxLayout* contentLay = new QHBoxLayout(this);
    contentLay->setSpacing(20);
    contentLay->setContentsMargins(10, 5, 10, 5);

    QLabel* sensorIcon = new QLabel();
    sensorIcon->setAlignment(Qt::AlignHCenter);
    sensorIcon->setPixmap(renderSVG(iconPath, QSize(80, 80)));
    sensorIcon->setFixedSize(80, 80);

    QLabel* sensorName = new QLabel(name);
    sensorName->setAlignment(Qt::AlignCenter);
    sensorName->setObjectName("card-list-name");
    QLabel* tapLabel = new QLabel("Tap for more info");
    tapLabel->setAlignment(Qt::AlignCenter);
    tapLabel->setObjectName("card-list-tap");
    QLabel* typeLabel = new QLabel(type);
    typeLabel->setAlignment(Qt::AlignCenter);
    typeLabel->setObjectName("card-list-type");

    QVBoxLayout* btnLay = new QVBoxLayout();
    btnLay->setSpacing(5);
    btnLay->setAlignment(Qt::AlignCenter);

    editBtn->setObjectName("editBtn");
    editBtn->setFixedSize(35, 35);
    deleteBtn->setObjectName("deleteBtn");
    deleteBtn->setFixedSize(35, 35);

    btnLay->addWidget(editBtn);
    btnLay->addWidget(deleteBtn);

    contentLay->addWidget(sensorIcon);
    contentLay->addWidget(sensorName);
    contentLay->addWidget(tapLabel);
    contentLay->addStretch();
    contentLay->addWidget(typeLabel);
    contentLay->addLayout(btnLay);
}
