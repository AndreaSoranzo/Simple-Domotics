#ifndef TextQueryVisitor_H
#define TextQueryVisitor_H

#include <string>

#include "../Sensors/Core/AlertSensor.h"
#include "../Sensors/Core/InfoSensor.h"
#include "../Sensors/VisitorTypes/ISensorClassVisitorConst.h"

class TextQueryVisitor : public ISensorClassVisitorConst {
   private:
    std::string filter;
    bool perfectMatch;
    unsigned int score;

    unsigned int CalcolateScore(std::string target, std::string query, bool forcePerfectMatch = false) const;

   public:
    TextQueryVisitor(const std::string& filter, bool perfectMatch);
    unsigned int GetScore() const;

    void visit(const InfoSensor& sens) override;
    void visit(const AlertSensor& sens) override;
};

#endif  // !ScoreVisitor_H