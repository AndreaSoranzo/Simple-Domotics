#ifndef UserDataLoader_H
#define UserDataLoader_H

#include <string>

#include "UserData.h"

UserData LoadUser(const std::string& path);
bool SaveUser(const UserData& user, const std::string& path);

#endif  // !UserDataLoader_H