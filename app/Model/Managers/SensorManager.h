#ifndef SensorManager_H
#define SensorManager_H

#include <map>
#include <string>
#include <vector>

#include "../Query/Query.h"
#include "../Query/QueryResults.h"
#include "../Sensors/Core/AbstractSensor.h"

class SensorManager {
   private:
    std::map<unsigned int, AbstractSensor*> sensors;

   public:
    SensorManager() = default;
    ~SensorManager();

    bool AddSensor(AbstractSensor* newSensor);  // returns 0 if a element with the same name exists
    void RemoveSensor(unsigned int index);
    unsigned int GetSize() const;
    bool IsEmpty() const;
    const QueryResults Search(const Query& query) const;
    AbstractSensor* GetSensor(unsigned int index) const;
    const std::vector<AbstractSensor*> GetAll() const;
    void Clear();
    void Inizialize(std::vector<AbstractSensor*>& newSensors);
};

#endif  // !SensorManager_H