#ifndef GroundSensor_H
#define GroundSensor_H

#include "Core/AlertSensor.h"

class GroundSensor : public AlertSensor {
   public:
    GroundSensor(const std::string& name, const std::string& brand, double dangerLV, const std::string& moreInfo = "", int id = -1);


    void accept(ISensorClassVisitor& visitor) override;
    void accept(ISensorClassVisitorConst& visitor) const override;

    void accept(ISensorTypeVisitor& visitor) override;
    void accept(ISensorTypeVisitorConst& visitor) const override;
};

#endif  // !WindSensor_H