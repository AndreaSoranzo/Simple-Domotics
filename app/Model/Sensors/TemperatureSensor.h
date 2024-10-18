#ifndef TemperatureSensor_H
#define TemperatureSensor_H

#include "Core/InfoSensor.h"

class TemperatureSensor : public InfoSensor {
   private:
    unsigned int batteries;
    unsigned int currentCharge;

   public:
    TemperatureSensor(const std::string& name,
                      const std::string& brand,
                      const std::string& moreInfo = "",
                      unsigned int batteries = 0,
                      unsigned int intitialCharge = 101,
                      int id = -1);

    bool IsPortable() const;
    unsigned int GetBatteries() const;
    void SetBatteries(unsigned int batteries);
    unsigned int GetCurrentCharge() const;

    void accept(ISensorClassVisitor& visitor) override;
    void accept(ISensorClassVisitorConst& visitor) const override;


    void accept(ISensorTypeVisitor& visitor) override;
    void accept(ISensorTypeVisitorConst& visitor) const override;
};

#endif  // !WindSensor_H