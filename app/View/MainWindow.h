#ifndef MainWindow_H
#define MainWindow_H

#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QStackedLayout>

#include "../Observers/IUserInfoObserver.h"
#include "Windows/HomeWindow.h"
#include "Windows/ManagmentWindow.h"
#include "Windows/NotificationWindow.h"
#include "Windows/SensorsWindow.h"

class MainWindow : public QMainWindow, public IUserInfoObserver {
    Q_OBJECT
   private:
    bool changeWithoutSave;

    HomeWindow* home;
    SensorsWindow* sensors;
    NotificationWindow* notifications;
    ManagmentWindow* managment;

    QApplication& app;
    QStackedLayout* stackLayout;
    QLabel* statusLabel;
    QPushButton* homeBtn;
    QPushButton* listButton;
    QPushButton* notificationButton;
    QPushButton* addButton;

    UserSettingDialog* dialog;

    QPushButton* CreatePanelButton(const std::string& toolTip, const std::string& path) const;
    void ChangePanel(int idx);

   protected:
    void closeEvent(QCloseEvent* event) override;

   public:
    explicit MainWindow(QApplication* app, QWidget* parent = nullptr);

    HomeWindow* GetHomeWindow() const;
    SensorsWindow* GetSensorWindow() const;
    NotificationWindow* GetNotificationWindow() const;
    ManagmentWindow* GetManagmentWindow() const;

    void Notify(const std::string&, const std::string&, int palette) override;

    void LoadMsg(bool ok) const;
    void SaveMsg(bool ok) const;

   signals:
    void OnUpdateSettings(const QString& name, const QString& mail, int palette);

   public slots:
    void OpenUserSettings(bool isAtStart = false);

   private slots:
    void ChangePalette(int idx);
    void ShowHelpBox() const;
    void ShowSecret() const;
};

#endif  // !MainWindow_H