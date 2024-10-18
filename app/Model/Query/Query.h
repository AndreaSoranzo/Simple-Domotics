#ifndef Query_H
#define Query_H

#include <string>
#include <vector>

class Query {
   private:
    std::string queryText;
    std::string typeChoise;
    bool perfectMatch;

   public:
    Query(const std::string& queryText, const std::string& typeChoise, bool perfectMatch);
    bool PerfectMatch() const;
    const std::string& GetQueryText() const;
    const std::string& GetTypeChoise() const;
};

#endif  // !Query_H