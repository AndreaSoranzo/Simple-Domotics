#ifndef Header_H
#define Header_H

#include <QLabel>
#include <QString>
#include <QWidget>

class Header : public QWidget {
   private:
    QLabel* greatingsLabel;

   public:
    explicit Header(const QString& description, QWidget* parent = 0);
    void UpdateUser(const QString& user);
};

#endif  // !Header_H