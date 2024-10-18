#ifndef INotificationObserver_H
#define INotificationObserver_H

#include <string>

class INotificationObserver {
   public:
    virtual void Notify(const std::string& title, const std::string& text, const std::string& time) = 0;
    virtual ~INotificationObserver() = default;
};

#endif  // !  INotificationObserver_H