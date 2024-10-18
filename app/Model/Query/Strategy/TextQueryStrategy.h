#ifndef TextQueryStrategy_H
#define TextQueryStrategy_H

#include "../Query.h"
#include "../TextQueryVisitor.h"
#include "IQueryStrategy.h"

class TextQueryStrategy : public IQueryStrategy {
   private:
    TextQueryVisitor visitor;
    unsigned int score;

   public:
    TextQueryStrategy(const Query& query);
    bool IsMatch(AbstractSensor* sensor) override;
    virtual unsigned int GetScore() const override;
};

#endif  // !TextQueryStrategy_H