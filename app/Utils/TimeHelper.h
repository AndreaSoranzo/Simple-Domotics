#ifndef TimeHelper_H
#define TimeHelper_H

#include <string>

class TimeHelper {
   private:
    TimeHelper();

   public:
    static std::string ConvertToHourOfDay(double when);
    static std::string GetCurrentTime();
};

#endif  // !TimeHelper_H