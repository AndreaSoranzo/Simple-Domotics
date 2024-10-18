#ifndef IUserInfoObserver_H
#define IUserInfoObserver_H

#include <string>

class IUserInfoObserver {
   public:
    virtual void Notify(const std::string& name, const std::string& mail, int palette) = 0;
    virtual ~IUserInfoObserver() = default;
};
#endif  // !IUserInfoObserver_H