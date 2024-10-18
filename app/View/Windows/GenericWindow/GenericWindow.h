#ifndef GenericWindow_H
#define GenericWindow_H

#include <QString>

#include "../../../Observers/IUserInfoObserver.h"
#include "../../CustomWidgets/Header.h"
#include "AbstractWindow.h"

class GenericWindow : public AbstractWindow, public IUserInfoObserver {
   private:
    Header header;

   public:
    explicit GenericWindow(const QString& headerText,QWidget* parent = 0);
    void Notify(const std::string& name, const std::string&, int) override;
    Header* GetHeader();
    virtual ~GenericWindow() = default;
};

#endif  // !GenericWindow_H