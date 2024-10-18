#ifndef ISensor_H
#define ISensor_H
#include <string>
#include <vector>

#include "../Distributions/AbstractDistribution.h"
#include "../VisitorTypes/ISensorClassVisitor.h"
#include "../VisitorTypes/ISensorClassVisitorConst.h"
#include "../VisitorTypes/ISensorTypeVisitor.h"
#include "../VisitorTypes/ISensorTypeVisitorConst.h"

class AbstractSensor {
   private:
    struct GenericSensorInfo {
        std::string name;
        std::string brand;
        std::string moreInfo;
        std::vector<double> values;
    };
    const std::string label;
    const std::string description;
    const std::string iconPath;

    unsigned int id;
    GenericSensorInfo info;
    AbstractDistribution* currentDistribution;

   public:
    static unsigned int products;
    AbstractSensor(const std::string& name,
                   const std::string& brand,
                   const std::string& moreInfo,
                   const std::string& label,
                   const std::string& description,
                   const std::string& iconPath,
                   int id);
    virtual ~AbstractSensor();

    void SetDistribution(AbstractDistribution* newDistribution);
    AbstractDistribution& GetDistribution() const;

    const GenericSensorInfo& GetInfo() const;
    GenericSensorInfo& GetInfo();

    unsigned int GetSensorId() const;

    const std::string& ToString() const;
    const std::string& GetDescription() const;
    const std::string& GetIcon() const;

    virtual void accept(ISensorTypeVisitor& visitor) = 0;
    virtual void accept(ISensorTypeVisitorConst& visitor) const = 0;
    virtual void accept(ISensorClassVisitor& visitor) = 0;
    virtual void accept(ISensorClassVisitorConst& visitor) const = 0;

    void Generate();
};

#endif  // !ISensor_H