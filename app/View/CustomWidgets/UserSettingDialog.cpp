#include "UserSettingDialog.h"

#include <QDialogButtonBox>
#include <QFormLayout>
#include <QVBoxLayout>

bool UserSettingDialog::ValidateInput() const {
    bool valid = !userInput->text().isEmpty() && !mailInput->text().isEmpty();
    if (!valid) {
        userInput->setStyleSheet("border: 2px solid red");
        mailInput->setStyleSheet("border: 2px solid red");
    }
    return valid;
}

void UserSettingDialog::UpdateInputContent() {
    userInput->setStyleSheet("");
    mailInput->setStyleSheet("");
}

UserSettingDialog::UserSettingDialog(QWidget* parent) : QDialog(parent) {
    setWindowTitle("Insert your info");
    setMinimumWidth(450);
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);

    QFormLayout* layout = new QFormLayout(this);

    QDialogButtonBox* btns = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal);

    userInput = new QLineEdit();
    userInput->setMaxLength(12);

    mailInput = new QLineEdit();

    layout->addRow("Username:", userInput);
    layout->addRow("Mail:", mailInput);

    QWidget* container = new QWidget();
    QVBoxLayout* radioLay = new QVBoxLayout(container);

    QRadioButton* option1 = new QRadioButton("GrassCaffe");
    option1->setChecked(true);
    QRadioButton* option2 = new QRadioButton("BoringTan");

    palettes << option1 << option2;

    radioLay->addWidget(option1);
    radioLay->addWidget(option2);

    layout->addRow("Palette:", container);
    layout->addWidget(btns);

    connect(btns, &QDialogButtonBox::accepted, this, [&]() -> void { if (ValidateInput() ) emit accept(); });
    connect(btns, &QDialogButtonBox::rejected, this, &UserSettingDialog::reject);
}

const UserSettingDialog::NewValues UserSettingDialog::GetValues(bool& ok) {
    UpdateInputContent();

    UserSettingDialog::NewValues values;
    ok = exec();

    QString user = userInput->text();
    QString email = mailInput->text();

    if (ok) {
        values.name = user;
        values.mail = email;
        int palette = 0;
        for (int i = 0; i < palettes.size(); i++) {
            if (palettes[i]->isChecked()) {
                palette = i;
                break;
            }
        }
        values.palette = palette;
    }

    return values;
}

UserSettingDialog::NewValues::NewValues() {
}

void UserSettingDialog::SetNameInputText(const QString& name) {
    userInput->setText(name);
}

void UserSettingDialog::SetMailInputText(const QString& email) {
    mailInput->setText(email);
}

void UserSettingDialog::SetPaletteInput(const int palette) {
    palettes[palette]->setChecked(true);
}
