#ifndef QueryRunner_H
#define QueryRunner_H

#include <vector>

#include "QueryResults.h"
#include "Strategy/IQueryStrategy.h"

class QueryRunner {
   private:
    std::vector<IQueryStrategy*> strats;
    QueryResults results;

   public:
    void AddStrategy(IQueryStrategy* strategy);
    void Run(AbstractSensor* sensor);
    QueryResults GetResults();
    ~QueryRunner();
};

#endif  // !QueryRunner_H