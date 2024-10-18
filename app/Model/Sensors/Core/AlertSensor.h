#ifndef AlertSensor_H
#define AlertSensor_H

#include "AbstractSensor.h"

class AlertSensor : public AbstractSensor {
   private:
    const std::string alertText;
    std::string lastTrigger;
    double dangerLV;

   public:
    AlertSensor(const std::string& name,
                const std::string& brand,
                const std::string& moreInfo,
                double dangerLV,
                const std::string& alertText,
                const std::string& label,
                const std::string& description,
                const std::string& iconPath,
                int id);
    void SetLastTrigger(std::string time);
    const std::string& GetLastTrigger() const;
    double GetDangerLV() const;
    void SetDangerLV(double danger);

    const std::string& GetAlertText() const;
};

#endif  // !AlertSensor_H