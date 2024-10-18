#include "DataEncrypt.h"

static int len(const char* string) {
    int count = 0;
    while (*string != '\0') {
        string++;
        count++;
    }
    return count;
}

void Crypt(const std::string& string, const char* psw, char* output) {
    int pswlen = len(psw);
    for (unsigned int i = 0; i < string.size(); i++) {
        char temp = string[i] ^ psw[i % pswlen];
        output[i] = temp;
    }
}

void DeCrypt(const char* crypted, unsigned int lenght, const char* psw, std::string& output) {
    int pswlen = len(psw);
    for (unsigned int i = 0; i < lenght; i++) {
        char temp = crypted[i] ^ psw[i % pswlen];
        output.push_back(temp);
    }
}
