#include "NotificationBox.h"

#include <QHBoxLayout>
#include <QLabel>

#include "../../Utils/RenderSvg.h"
#include "../../Utils/WidgetsEffects.h"

NotificationBox::NotificationBox(const QString& title,
                                 const QString& text,
                                 const QString& time,
                                 QWidget* parent) : QWidgetFix(parent), title(title), text(text) {
    WidgetsEffects::ApplyShadow(this, 6, 0, 1, QColor("#b5b5b5"));

    setFixedHeight(60);
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->setSpacing(25);

    icon = new QLabel();
    icon->setPixmap(renderSVG(":assets/icons/mail_unread.svg", QSize(40, 40)));
    icon->setFixedSize(40, 40);
    mainLayout->addWidget(icon);

    QVBoxLayout* labelLayout = new QVBoxLayout();
    labelLayout->setSpacing(0);

    QLabel* titleLabel = new QLabel(title);
    titleLabel->setWordWrap(true);
    titleLabel->setObjectName("notification-title");

    QLabel* textLabel = new QLabel();
    QFontMetrics metrics(textLabel->font());
    QString elidedText = metrics.elidedText(text, Qt::ElideRight, textLabel->width());
    textLabel->setAlignment(Qt::AlignVCenter);
    textLabel->setWordWrap(true);
    textLabel->setText(elidedText);
    textLabel->setObjectName("thin");

    labelLayout->addWidget(titleLabel);
    labelLayout->addWidget(textLabel);

    mainLayout->addLayout(labelLayout, 1);

    QLabel* timeLabel = new QLabel(time);
    timeLabel->setObjectName("thin");
    timeLabel->setAlignment(Qt::AlignCenter);

    mainLayout->addWidget(timeLabel);
}

void NotificationBox::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        setObjectName("read");
        icon->setPixmap(renderSVG(":assets/icons/mail_read.svg", QSize(40, 40)));
        style()->unpolish(this);
        style()->polish(this);
        emit pressed(title, text);
    }
}
