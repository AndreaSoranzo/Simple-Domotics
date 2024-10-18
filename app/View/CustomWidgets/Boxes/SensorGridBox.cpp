#include "SensorGridBox.h"

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

#include "../../Utils/RenderSvg.h"

SensorGridBox::SensorGridBox(unsigned int id, const QString& iconPath, const QString& name, const QString& brand, QWidget* parent) : AbstractSensorBox(id, parent) {
    setFixedSize(220, 220);

    QGridLayout* contentLay = new QGridLayout(this);

    editBtn->setObjectName("editBtn");
    editBtn->setFixedSize(40, 40);
    deleteBtn->setObjectName("deleteBtn");
    deleteBtn->setFixedSize(40, 40);

    QLabel* sensorIcon = new QLabel();
    sensorIcon->setAlignment(Qt::AlignHCenter);
    sensorIcon->setPixmap(renderSVG(iconPath, QSize(110, 110)));
    sensorIcon->setFixedSize(110, 110);

    QVBoxLayout* infoLay = new QVBoxLayout();
    infoLay->setSpacing(5);

    QLabel* sensorName = new QLabel(name);
    sensorName->setAlignment(Qt::AlignCenter);
    sensorName->setObjectName("card-grid-name");
    QLabel* tapLabel = new QLabel("Tap for more info");
    tapLabel->setAlignment(Qt::AlignCenter);
    tapLabel->setObjectName("card-grid-tap");
    QLabel* brandLabel = new QLabel(brand);
    brandLabel->setAlignment(Qt::AlignCenter);
    brandLabel->setObjectName("card-grid-type");

    infoLay->addWidget(sensorName);
    infoLay->addWidget(tapLabel);
    infoLay->addWidget(brandLabel);

    contentLay->setRowStretch(0, 10);

    contentLay->addWidget(editBtn, 0, 0, Qt::AlignTop);
    contentLay->addWidget(sensorIcon, 0, 1, Qt::AlignBottom | Qt::AlignCenter);
    contentLay->addWidget(deleteBtn, 0, 2, Qt::AlignTop);
    contentLay->addLayout(infoLay, 1, 0, 1, 3, Qt::AlignCenter);
};
