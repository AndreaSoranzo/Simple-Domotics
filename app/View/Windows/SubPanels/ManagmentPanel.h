#ifndef ManagmentPanel_H
#define ManagmentPanel_H

#include <QGridLayout>
#include <QList>
#include <QString>

#include "../../Utils/QWidgetFix.h"

class ManagmentPanel : public QWidgetFix {
    Q_OBJECT
   private:
    QGridLayout* btnLayout;
    QList<QWidget*> configurationBtns;

    QWidget* CreateButton(const QString& text, const QString& iconPath, int width, int height, void (ManagmentPanel::*slot)()) const;
    void UpdateLayout();

   protected:
    void resizeEvent(QResizeEvent* event) override;

   public:
    explicit ManagmentPanel(QWidget* parent = 0);

   public slots:
    void OpenJson();
    void SaveJson();

   signals:
    void OnAddSensor();
    void OnSave(const QString& path);
    void OnLoad(const QString& path);
};

#endif  // !ManagmentPanel_H