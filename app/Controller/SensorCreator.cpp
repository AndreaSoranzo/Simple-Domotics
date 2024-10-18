#include "SensorCreator.h"

#include "../Model/Sensors/Distributions/ExponentialDistribution.h"
#include "../Model/Sensors/Distributions/NormalDistribuition.h"
#include "../Model/Sensors/Distributions/RandomDistribution.h"
#include "../Model/Sensors/Distributions/UniformDistribution.h"
#include "../Model/Sensors/GroundSensor.h"
#include "../Model/Sensors/HumiditySensor.h"
#include "../Model/Sensors/SmokeSensor.h"
#include "../Model/Sensors/SolarSensor.h"
#include "../Model/Sensors/TemperatureSensor.h"
#include "../Model/Sensors/WindSensor.h"
#include "../Utils/RandomGenerator.h"
#include "../Utils/StringHelper.h"
#include "../Utils/TypeHelper.h"
#include "../View/Windows/SubPanels/AddPanel.h"

SensorCreator::SensorCreator(const AddPanel& addPanel) : addPanel(addPanel) {
}
AbstractSensor* SensorCreator::Instantiate() const {
    AbstractSensor* sensor = nullptr;
    switch (TypeHelper::ToSensorType(addPanel.GetSensorType().toStdString())) {
        case SensorType::Ground:
            sensor = new GroundSensor(addPanel.GetName().toStdString(), StringHelper::ToUpper(addPanel.GetBrand().toStdString()), addPanel.GetParamInput()->GetParam(Param::Danger), addPanel.GetMoreInfo().toStdString());
            return sensor;
        case SensorType::Smoke:
            sensor = new SmokeSensor(addPanel.GetName().toStdString(), StringHelper::ToUpper(addPanel.GetBrand().toStdString()), addPanel.GetParamInput()->GetParam(Param::Danger), addPanel.GetMoreInfo().toStdString());
            return sensor;
        case SensorType::Humidity:
            sensor = new HumiditySensor(addPanel.GetName().toStdString(), StringHelper::ToUpper(addPanel.GetBrand().toStdString()), addPanel.GetMoreInfo().toStdString());
            break;
        case SensorType::Wind:
            sensor = new WindSensor(addPanel.GetName().toStdString(), StringHelper::ToUpper(addPanel.GetBrand().toStdString()), addPanel.GetMoreInfo().toStdString());
            break;
        case SensorType::Solar:
            sensor = new SolarSensor(addPanel.GetName().toStdString(), StringHelper::ToUpper(addPanel.GetBrand().toStdString()), addPanel.GetCertification().toStdString(), addPanel.GetMoreInfo().toStdString());
            break;
        case SensorType::Temperature:
            sensor = new TemperatureSensor(addPanel.GetName().toStdString(), StringHelper::ToUpper(addPanel.GetBrand().toStdString()), addPanel.GetMoreInfo().toStdString(), addPanel.GetBatteries());
            break;
        default:
            return sensor;
    }
    AbstractDistribution* distribution = nullptr;
    switch (TypeHelper::ToDistributionType(addPanel.GetDistributionType().toStdString())) {
        case DistributionType::Uniform:
            distribution = new UniformDistribution(RandomGenerator<unsigned int>::Generate(50, 150), addPanel.GetParamInput()->GetParam(Param::Min), addPanel.GetParamInput()->GetParam(Param::Max));
            break;
        case DistributionType::Normal:
            distribution = new NormalDistribuition(RandomGenerator<unsigned int>::Generate(50, 250), addPanel.GetParamInput()->GetParam(Param::Mean), addPanel.GetParamInput()->GetParam(Param::Noise));
            break;
        case DistributionType::Random:
            distribution = new RandomDistribution(RandomGenerator<unsigned int>::Generate(50, 300), addPanel.GetParamInput()->GetParam(Param::Min), addPanel.GetParamInput()->GetParam(Param::Max));
            break;
        default:
            delete sensor;
            return nullptr;
    }
    sensor->SetDistribution(distribution);
    return sensor;
}
