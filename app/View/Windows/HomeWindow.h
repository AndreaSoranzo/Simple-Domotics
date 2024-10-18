#ifndef HomeWindow_H
#define HomeWindow_H

#include <QLabel>
#include <QString>
#include <QWidget>

#include "../../Observers/IUserInfoObserver.h"
#include "../CustomWidgets/UserSettingDialog.h"
#include "GenericWindow/AbstractWindow.h"

class HomeWindow : public AbstractWindow, public IUserInfoObserver {
    Q_OBJECT
   private:
    QLabel* greatingsLabel;

    void
    UpdateScreen(const QString& user);

   public:
    explicit HomeWindow(QWidget* parent = 0);
    void Notify(const std::string& name, const std::string& mail, int) override;
    void RevertToDefaultState() override;

   signals:
    void OnOpenUserSettings(bool isAtStart = false);
};

#endif  // !HomeWindow_H