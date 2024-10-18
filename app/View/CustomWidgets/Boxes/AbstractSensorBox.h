#ifndef AbstractSensorBox_H
#define AbstractSensorBox_H

#include <QMouseEvent>
#include <QPixmap>
#include <QPushButton>

#include "../../Utils/QWidgetFix.h"

class AbstractSensorBox : public QWidgetFix {
    Q_OBJECT
   private:
    unsigned int id;

   protected:
    QPushButton* deleteBtn;
    QPushButton* editBtn;

   protected:
    void mousePressEvent(QMouseEvent* event) override;
    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;

   public:
    explicit AbstractSensorBox(unsigned int id, QWidget* parent = 0);
    const QPushButton* GetEditButton() const;
    const QPushButton* GetDeleteButton() const;

   signals:
    void pressed();
};

#endif  // !AbstractSensorBox_H