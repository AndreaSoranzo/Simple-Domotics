#ifndef SaveLoadManager_H
#define SaveLoadManager_H

#include <string>

#include "../SaveLoad/ObjectConverter.h"
#include "../Sensors/Core/AbstractSensor.h"

class SaveLoadManager {
   private:
    ObjectConverter converter;
    void ConvertError(std::vector<AbstractSensor*>& sensors) const;

   public:
    bool Save(const std::vector<AbstractSensor*> sensors, const std::string& path);
    std::vector<AbstractSensor*> Load(const std::string& path);
};

#endif  // !SaveLoadManager_H