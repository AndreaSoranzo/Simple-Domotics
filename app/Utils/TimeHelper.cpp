#include "TimeHelper.h"

#include <cmath>
#include <ctime>
#include <iomanip>
#include <sstream>

std::string TimeHelper::ConvertToHourOfDay(double when) {
    std::ostringstream timeString;
    int hours = std::floor(when);
    double reminder = when - hours;
    int minutes = std::floor(reminder * 60);
    timeString << std::setfill('0') << std::setw(2) << hours << ":"
               << std::setfill('0') << std::setw(2) << minutes;
    return timeString.str();
}

std::string TimeHelper::GetCurrentTime() {
    std::ostringstream timeString;
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    timeString << std::put_time(&tm, "%d-%m-%Y\n%H-%M-%S");
    return timeString.str();
}
