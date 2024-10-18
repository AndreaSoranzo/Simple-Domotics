#ifndef DataEncrypt_H
#define DataEncrypt_H

#include <string>

void Crypt(const std::string& string, const char* psw, char* output);
void DeCrypt(const char* crypted, unsigned int lenght, const char* psw, std::string& output);

#endif  // !DataEncrypt_H