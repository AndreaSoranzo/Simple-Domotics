#ifndef StringHelper_H
#define StringHelper_H

#include <string>

class StringHelper {
   private:
    StringHelper();

   public:
    static std::string ToLower(std::string s);
    static std::string ToUpper(std::string s);
};

#endif  // !StringHelper_H