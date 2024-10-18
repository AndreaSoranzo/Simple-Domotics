#ifndef InfoSensor_H
#define InfoSensor_H

#include "AbstractSensor.h"

class InfoSensor : public AbstractSensor {
   public:
    const std::string unit;
    InfoSensor(const std::string& name,
               const std::string& brand,
               const std::string& moreInfo,
               const std::string& label,
               const std::string& description,
               const std::string& iconPath,
               const std::string& unit,
               int id);

    double GetAvg() const;
    double GetMax() const;
    double GetMin() const;
    const std::string& GetUnit() const;

};

#endif  // !InfoSensor_H