#include "Query.h"

Query::Query(const std::string& queryText, const std::string& typeChoise, bool perfectMatch) : queryText(queryText), typeChoise(typeChoise), perfectMatch(perfectMatch) {
}

bool Query::PerfectMatch() const {
    return perfectMatch;
}

const std::string& Query::GetQueryText() const {
    return queryText;
}

const std::string& Query::GetTypeChoise() const {
    return typeChoise;
}
