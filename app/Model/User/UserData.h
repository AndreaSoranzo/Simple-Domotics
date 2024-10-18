#ifndef UserData_H
#define UserData_H

#include <iostream>
#include <string>

#include "ColorSchemeEnum.h"

class UserData {
   private:
    std::string name;
    std::string email;
    ColorScheme colorScheme;

    std::string prevName;
    std::string prevEmail;
    ColorScheme prevColorScheme;

    friend std::ostream& operator<<(std::ostream& os, const UserData& user);
    friend std::istream& operator>>(std::istream& is, UserData& user);

   public:
    UserData(const std::string& newName = "", const std::string& newMail = "", ColorScheme scheme = ColorScheme::GrassCaffe);
    void SetName(const std::string& newName);
    void SetMail(const std::string& newMail);
    void SetScheme(int val);
    const std::string& GetName() const;
    const std::string& GetMail() const;
    int GetScheme() const;
    void Revert();
};

#endif  // !UserData_H