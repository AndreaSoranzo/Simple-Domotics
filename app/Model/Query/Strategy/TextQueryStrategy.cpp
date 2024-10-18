#include "TextQueryStrategy.h"

TextQueryStrategy::TextQueryStrategy(const Query& query) : visitor(query.GetQueryText(), query.PerfectMatch()), score(0) {
}

bool TextQueryStrategy::IsMatch(AbstractSensor* sensor) {
    sensor->accept(visitor);
    score = visitor.GetScore();
    return score > 0;
}

unsigned int TextQueryStrategy::GetScore() const {
    return score;
}
