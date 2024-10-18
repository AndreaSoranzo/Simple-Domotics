#ifndef HumiditySensor_H
#define HumiditySensor_H

#include "Core/InfoSensor.h"

class HumiditySensor : public InfoSensor {
   public:
    HumiditySensor(const std::string& name, const std::string& brand, const std::string& moreInfo = "", int id = -1);

    void accept(ISensorClassVisitor& visitor) override;
    void accept(ISensorClassVisitorConst& visitor) const override;

    void accept(ISensorTypeVisitor& visitor) override;
    void accept(ISensorTypeVisitorConst& visitor) const override;
};

#endif  // !HumiditySensor_H