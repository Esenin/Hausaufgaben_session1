#ifndef PARSER_H
#define PARSER_H

#include "stateAutomaton.h"
#include "charLine.h"
#include "iostream"

using namespace std;

class Parser
{
public:
    Parser();
    ~Parser();
    bool isValidExpression(const char *expression);

private:
    CharLine string;
    int stringSize;
    bool isGoodExpression(int &currentPos);
    bool isLowLevelSigns(int &currentPos);
    bool isMultiplicativeGroup(int &currentPos);
    bool isHighLevelSigns(int &currentPos);
    bool isSubExpressions(int &currentPos);
};

#endif // PARSER_H
