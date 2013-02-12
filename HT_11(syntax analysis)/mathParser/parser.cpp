#include "parser.h"

Parser::Parser() :
    stringSize(0)
{
}

Parser::~Parser()
{
    string.clear();
}

bool Parser::isValidExpression(const char *expression)
{
    int exprSize = StateAutomaton::getStrSize(expression);
    for (int i = 0; i < exprSize; i++)
        if(expression[i] != ' ')
            stringSize++;

    string.clear();

    for (int i = 0; i < exprSize; i++)
        if(expression[i] != ' ')
            string.pushBack(expression[i]);

    int curPosition = 0;
    bool answer = (isGoodExpression(curPosition) && curPosition == stringSize);
    return answer;
}

bool Parser::isGoodExpression(int &currentPos)
{
    int position = currentPos;
    if (isMultiplicativeGroup(position) && isLowLevelSigns(position))
    {
        currentPos = position;
        return true;
    }
    else
    {
        return false;
    }
}

bool Parser::isMultiplicativeGroup(int &currentPos)
{
    int position = currentPos;
    if (isSubExpressions(position) && isHighLevelSigns(position))
    {
        currentPos = position;
        return true;
    }
    else
    {
        return false;
    }
}

bool Parser::isLowLevelSigns(int &currentPos)
{
    int position = currentPos;

    if ((string.atPosition(position) == '+') || string.atPosition(position) == '-')
        position++;
    else
        return true; // epsilon escape

    if (isMultiplicativeGroup(position) && isLowLevelSigns(position))
    {
        currentPos = position;
        return true;
    }
    else
    {
        return false;
    }
}


bool Parser::isHighLevelSigns(int &currentPos)
{
    int position = currentPos;
    if ((string.atPosition(position) == '*') || string.atPosition(position) == '/')
        position++;
    else
        return true; // epsilon escape

    if (isSubExpressions(position) && isHighLevelSigns(position))
    {
        currentPos = position;
        return true;
    }
    else
    {
        return false;
    }
}

bool Parser::isSubExpressions(int &currentPos)
{
    int position = currentPos;
    if (string.atPosition(position) == '(')
    {
        position++;
        if (isGoodExpression(position) && (string.atPosition(position) == ')'))
        {
            position++;
            currentPos = position;
            return true;
        }
        else
        {
            return false;
        }
    }
    StateAutomaton numberSearcher;
    numberSearcher.setOptionsFile("rules.txt");
    if (numberSearcher.runOnExpression(string.toCharArray(), position, false))
    {
        currentPos = position;
        return true;
    }
    else
    {
        return false;
    }
}
