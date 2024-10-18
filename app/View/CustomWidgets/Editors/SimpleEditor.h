#ifndef SimpleEditor_H
#define SimpleEditor_H

#include <QFormLayout>
#include <QLineEdit>
#include <QString>
#include <QTextEdit>
#include <QWidget>

class SimpleEditor : public QWidget {
    Q_OBJECT
   protected:
    bool isChanged;

    QLineEdit* nameInput;
    QLineEdit* brandInput;
    QTextEdit* infoInput;

    QFormLayout* formLayout;

   public:
    SimpleEditor(const QString& name, const QString& brand, const QString& moreInfo, QWidget* parent = 0);

    void AddFormRow(const QString& name, QWidget* widget);

    const QString GetName() const;
    const QString GetBrand() const;
    const QString GetInfo() const;

    bool IsChanged() const;
};

#endif  // !SimpleEditor_H