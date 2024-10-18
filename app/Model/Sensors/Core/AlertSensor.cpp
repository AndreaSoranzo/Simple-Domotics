#include "AlertSensor.h"

#include "../../../Utils/RandomGenerator.h"
#include "../Distributions/ExponentialDistribution.h"

AlertSensor::AlertSensor(const std::string& name,
                         const std::string& brand,
                         const std::string& moreInfo,
                         double dangerLV,
                         const std::string& alertText, const std::string& label,
                         const std::string& description,
                         const std::string& iconPath,
                         int id) : AbstractSensor(name, brand, moreInfo, label, description, iconPath, id), alertText(alertText), lastTrigger("Never"), dangerLV(dangerLV / 100) {
    SetDistribution(new ExponentialDistribution(RandomGenerator<unsigned int>::Generate(30, 100), dangerLV / 100));
}

void AlertSensor::SetLastTrigger(std::string time) {
    lastTrigger = time;
}

const std::string& AlertSensor::GetLastTrigger() const {
    return lastTrigger;
}

double AlertSensor::GetDangerLV() const {
    return dangerLV * 100;
}

void AlertSensor::SetDangerLV(double danger) {
    dangerLV = danger / 100;
    ExponentialDistribution* dist = dynamic_cast<ExponentialDistribution*>(&GetDistribution());  // N.B im sure that distribution is an exponential, but testing for possbile json exploits
    if (dist) {
        dist->SetDanger(dangerLV);
    }
}

const std::string& AlertSensor::GetAlertText() const {
    return alertText;
}
