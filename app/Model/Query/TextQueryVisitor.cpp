#include "TextQueryVisitor.h"

#include "../../Utils/StringHelper.h"

TextQueryVisitor::TextQueryVisitor(const std::string& filter, bool perfectMatch) : filter(filter), perfectMatch(perfectMatch) {
}

unsigned int TextQueryVisitor::GetScore() const {
    return score;
}

void TextQueryVisitor::visit(const InfoSensor& sens) {
    score = CalcolateScore(sens.GetInfo().name, filter) + CalcolateScore(sens.GetInfo().brand, filter);
}

void TextQueryVisitor::visit(const AlertSensor& sens) {
    score = CalcolateScore(sens.GetInfo().name, filter) + CalcolateScore(sens.GetInfo().brand, filter) + CalcolateScore("danger", filter, true);
}

unsigned int TextQueryVisitor::CalcolateScore(std::string target, std::string query, bool forcePerfectMatch) const {
    if (perfectMatch || forcePerfectMatch) {  // if the user want the perfect match of what he writes
        int queryLen = query.size();
        std::string targetSub = target.substr(0, queryLen);
        return query == targetSub ? queryLen : 0;
    }

    target = StringHelper::ToLower(target);
    query = StringHelper::ToLower(query);

    // memoized LCS algorithm
    int targetLen = target.size();
    int queryLen = query.size();
    int L[targetLen + 1][queryLen + 1];
    for (int i = 0; i <= targetLen; i++) {
        for (int j = 0; j <= queryLen; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (target[i - 1] == query[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = std::max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    return L[targetLen][queryLen];
}