#ifndef StringTypeHelper_H
#define StringTypeHelper_H

#include <map>
#include <string>
#include <vector>

#include "TypeEnum.h"

class TypeHelper {
   private:
    static const std::map<std::string, SensorType> sensors;
    static const std::map<std::string, DistributionType> distributions;
    static const std::map<std::string, SolarCertification> certificaions;
    TypeHelper();

   public:
    static SensorType ToSensorType(const std::string& s);
    static DistributionType ToDistributionType(const std::string& s);
    static std::string ToSensorName(const SensorType& st);
    static std::string ToDistributionName(const DistributionType& dt);
    static std::vector<std::string> GetAllSolarCertification();
    static std::vector<std::string> GetAllSensorNames();
    static std::vector<std::string> GetAllDistributionNames();
};

#endif  // !StringTypeHelper_H