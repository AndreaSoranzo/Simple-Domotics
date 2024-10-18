#include "UserDataLoader.h"

#include <fstream>

UserData LoadUser(const std::string& path) {
    std::ifstream rf(path.c_str(), std::ios::out | std::ios::binary);
    if (!rf.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    UserData user;
    rf >> user;
    if (rf.fail() || rf.bad()) {
        throw std::runtime_error("The file is corrupted");
    }
    rf.close();
    return user;
}

bool SaveUser(const UserData& user, const std::string& path) {
    std::ofstream wf(path.c_str(), std::ios::out | std::ios::binary);
    if (!wf.is_open()) {
        return false;
    }
    wf << user;
    if (wf.fail() || wf.bad()) {
        return false;
    }
    wf.close();
    return true;
}
