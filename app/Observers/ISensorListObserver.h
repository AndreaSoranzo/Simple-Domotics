#ifndef ISensorListObserver_H
#define ISensorListObserver_H

#include <vector>

#include "../Utils/SensorItem.h"

class ISensorListObserver {
   public:
    virtual ~ISensorListObserver() = default;
    virtual void NotifyAdd(const std::vector<const SensorItem*>& list) = 0;  // add a single sensor
    virtual void NotifySearch(const std::vector<unsigned int>& list) = 0;    // search
    virtual void NotifySimulation(const std::vector<double>& list) = 0;      // simulation data
};

#endif  // !ISensorListObserver_H