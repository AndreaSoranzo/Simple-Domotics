#ifndef SolarSensor_H
#define SolarSensor_H

#include "Core/InfoSensor.h"

class SolarSensor : public InfoSensor {
   private:
    std::string certification;

   public:
    SolarSensor(const std::string& name,
                const std::string& brand,
                const std::string& certification,
                const std::string& moreInfo = "",
                int id = -1);

    const std::string& GetCertification() const;
    void SetCertificaion(const std::string& certificaion);

    void accept(ISensorClassVisitor& visitor) override;
    void accept(ISensorClassVisitorConst& visitor) const override;

    void accept(ISensorTypeVisitor& visitor) override;
    void accept(ISensorTypeVisitorConst& visitor) const override;
};

#endif  // !WindSensor_H