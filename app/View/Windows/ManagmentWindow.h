#ifndef ManagmentWindow_H
#define ManagmentWindow_H

#include <QStackedLayout>
#include <QWidget>

#include "GenericWindow/GenericWindow.h"
#include "SubPanels/AddPanel.h"
#include "SubPanels/ManagmentPanel.h"

class ManagmentWindow :  public GenericWindow {
    Q_OBJECT
   private:
    QStackedLayout* panels;
    AddPanel* addPanel;
    ManagmentPanel* managmentPanel;

   public:
    explicit ManagmentWindow(QWidget* parent = 0);
    void RevertToDefaultState() override;

    const AddPanel* GetAddPanel() const;
    const ManagmentPanel* GetManagmentPanel() const;

   public slots:
    void ShowAddPanel();
};

#endif  // !ManagmentWindow_H