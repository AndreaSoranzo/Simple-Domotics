#ifndef UserSettingDialog_H
#define UserSettingDialog_H

#include <QDialog>
#include <QLineEdit>
#include <QList>
#include <QRadioButton>
#include <QString>

class UserSettingDialog : public QDialog {
    Q_OBJECT
   private:
    QLineEdit* userInput;
    QLineEdit* mailInput;
    QList<QRadioButton*> palettes;

    bool ValidateInput() const;
    void UpdateInputContent();

   public:
    struct NewValues {
        QString name;
        QString mail;
        int palette;
        NewValues();
    };
    explicit UserSettingDialog(QWidget* parent = 0);

    void SetNameInputText(const QString& name);
    void SetMailInputText(const QString& email);
    void SetPaletteInput(const int palette);

    const NewValues GetValues(bool& ok);
};

#endif  // !UserSettingDialog_H