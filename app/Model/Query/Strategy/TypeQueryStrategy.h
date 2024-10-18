#ifndef TypeQueryStrategy_H
#define TypeQueryStrategy_H

#include "../Query.h"
#include "../TypeQueryChecker.h"
#include "IQueryStrategy.h"

class TypeQueryStrategy : public IQueryStrategy {
   private:
    TypeQueryChecker checker;

   public:
    TypeQueryStrategy(const Query& query);
    bool IsMatch(AbstractSensor* sensor) override;
    unsigned int GetScore() const override;
};

#endif  // !TypeQueryStrategy_H