#include "UserData.h"

#include "DataEncrypt.h"

#define CRYPT_PSW "noConst?Fword"

UserData::UserData(const std::string& newName, const std::string& newMail, ColorScheme scheme) : name(newName), email(newMail), colorScheme(scheme) {
}

void UserData::SetName(const std::string& newName) {
    prevName = name;
    name = newName;
}

void UserData::SetMail(const std::string& newMail) {
    prevEmail = email;
    email = newMail;
}

void UserData::SetScheme(int val) {
    switch (val) {
        case ColorScheme::GrassCaffe:
            prevColorScheme = colorScheme;
            colorScheme = ColorScheme::GrassCaffe;
            break;
        case ColorScheme::BoringTan:
            prevColorScheme = colorScheme;
            colorScheme = ColorScheme::BoringTan;
            break;
        default:
            prevColorScheme = colorScheme;
            colorScheme = ColorScheme::GrassCaffe;
            break;
    }
}

const std::string& UserData::GetName() const {
    return name;
}

const std::string& UserData::GetMail() const {
    return email;
}

int UserData::GetScheme() const {
    return colorScheme;
}

void UserData::Revert() {
    name = prevName;
    email = prevEmail;
    colorScheme = prevColorScheme;
}

std::ostream& operator<<(std::ostream& os, const UserData& user) {
    size_t stringSize = user.name.size();
    char name[stringSize];
    Crypt(user.name, CRYPT_PSW, name);
    os.write(reinterpret_cast<char*>(&stringSize), sizeof(size_t));
    os.write(name, stringSize);

    stringSize = user.email.size();
    char mail[stringSize];
    Crypt(user.email, CRYPT_PSW, mail);
    os.write(reinterpret_cast<char*>(&stringSize), sizeof(size_t));
    os.write(mail, stringSize);

    int scheme = static_cast<int>(user.colorScheme);
    os.write(reinterpret_cast<char*>(&scheme), sizeof(int));

    return os;
}

std::istream& operator>>(std::istream& is, UserData& user) {
    size_t stringSize = 0;
    is.read(reinterpret_cast<char*>(&stringSize), sizeof(size_t));

    char name[stringSize];
    is.read(&name[0], stringSize);
    DeCrypt(name, stringSize, CRYPT_PSW, user.name);

    is.read(reinterpret_cast<char*>(&stringSize), sizeof(size_t));
    char mail[stringSize];
    is.read(&mail[0], stringSize);
    DeCrypt(mail, stringSize, CRYPT_PSW, user.email);

    int scheme;
    is.read(reinterpret_cast<char*>(&scheme), sizeof(int));
    user.SetScheme(scheme);

    return is;
}
