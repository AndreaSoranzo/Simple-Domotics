#include "QueryRunner.h"

void QueryRunner::AddStrategy(IQueryStrategy* strategy) {
    strats.push_back(strategy);
}

void QueryRunner::Run(AbstractSensor* sensor) {
    bool allMatch = false;
    unsigned int totalScore = 0;
    for (IQueryStrategy* strat : strats) {
        allMatch = strat->IsMatch(sensor);
        if (allMatch) {  // AND between strategies
            totalScore += strat->GetScore();
        } else {
            // if only one does not match return and do nothing
            return;
        }
    }
    results.AddResult(sensor, totalScore);
}

QueryResults QueryRunner::GetResults() {
    results.Sort();
    return results;
}

QueryRunner::~QueryRunner() {
    for (IQueryStrategy* strat : strats) {
        delete strat;
    }
}