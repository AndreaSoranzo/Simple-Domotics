#ifndef WindSensor_H
#define WindSensor_H

#include "Core/InfoSensor.h"

class WindSensor : public InfoSensor {
   public:
    WindSensor(const std::string& name, const std::string& brand, const std::string& moreInfo = "", int id = -1);

    void accept(ISensorClassVisitor& visitor) override;
    void accept(ISensorClassVisitorConst& visitor) const override;

    void accept(ISensorTypeVisitor& visitor) override;
    void accept(ISensorTypeVisitorConst& visitor) const override;
};

#endif  // !WindSensor_H