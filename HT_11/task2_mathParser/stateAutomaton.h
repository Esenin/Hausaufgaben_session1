#ifndef STATEAUTOMATON_H
#define STATEAUTOMATON_H

#include <stdio.h>
#include <stdlib.h> //NULL
#include <climits>  //max_int
#include "stringList.h"

const int strMaxLen = 255;

class StateAutomaton
{
public:
    StateAutomaton();
    ~StateAutomaton();
    void setOptionsFile(const char fileName[]);
    bool runOnExpression(const char *expression, int &position, bool showErrors = true);
    static bool isEquals(const char first[], const char second[]);
    static int getStrSize(const char *string);

private:
    bool canShowErrorMsg;
    FILE *fRules;
    StringList *rulesArray;
    int finishState;
    int startState;

    bool isDigit(const char symbol) const;
    bool isLetter(const char symbol) const;
    bool isExistsFile() const;
    void lowerCase(char *string);
    bool isReservedWord(const char *word) const;
    int findMaxState();
    bool loadRulesFromFile();
    bool parseString(const char *string, int &startPosition);
    int getNextState(const char symbol, const int &currentState);
    void showExpections(const int &currentState, const char curSymbol);
};

#endif // STATEAUTOMATON_H
