#ifndef EditPanel_H
#define EditPanel_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "../../CustomWidgets/Editors/SimpleEditor.h"

class EditPanel : public QWidget {
    Q_OBJECT
   private:
    QVBoxLayout* layout;
    QPushButton* okBtn;

    SimpleEditor* currentEditor;

   public:
    explicit EditPanel(QWidget* parent = 0);
    SimpleEditor* GetCurrentEditor() const;
    void SetCurrentId();

   signals:
    void OnApply();
    void OnEditComplete(unsigned int id);

   public slots:
    void SetEditor(SimpleEditor* newEditor);
};

#endif  // !EditPanel_H