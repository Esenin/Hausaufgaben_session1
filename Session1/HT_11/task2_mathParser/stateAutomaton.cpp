#include "stateAutomaton.h"

StateAutomaton::StateAutomaton() :
    canShowErrorMsg(true),
    fRules(NULL),
    rulesArray(NULL),
    finishState(-1),
    startState(1)
{
}

StateAutomaton::~StateAutomaton()
{
    if (rulesArray != NULL);
        delete[] rulesArray;
}

void StateAutomaton::setOptionsFile(const char fileName[])
{
    fRules = fopen(fileName, "r");
    if (!isExistsFile())
    {
        printf("Warning: cannot find file with rules\n");
        return;
    }

    if (rulesArray != NULL)
        delete[] rulesArray;
    else
        rulesArray = new StringList[findMaxState() + 1];

    if (!loadRulesFromFile())
        printf("Warning: file with rules is probably incorrect\n");

    fclose(fRules);
}

int StateAutomaton::findMaxState()
{
    rewind(fRules);
    int max = 0;
    int min = INT_MAX;
    int current = 0;

    char word[strMaxLen];

    while (!feof(fRules))
    {
        fscanf(fRules, "%s", word);
        lowerCase(word);
        if (isEquals(word, "state"))
        {
            fscanf(fRules, "%d", &current);
            if (current > max)
                max = current;
            if (current < min)
                min = current;
        }
    }
    rewind(fRules);
    startState = min;
    return max;
}

bool StateAutomaton::loadRulesFromFile()
{
    rewind(fRules);
    int currentState = 0;
    int currentDestination = 0;
    char word[strMaxLen] = {};

    while (!feof(fRules))
    {
        fscanf(fRules, "%s", word);
        lowerCase(word);
        if (isEquals(word, "state"))
        {
            fscanf(fRules, "%d", &currentState);
        }

        if (isEquals(word, "goto"))
            fscanf(fRules, "%d", &currentDestination);

        if (isEquals(word, "case"))
        {
            fpos_t curPosition;
            fgetpos(fRules, &curPosition);
            fscanf(fRules, "%s", word);
            while (!isReservedWord(word) && (!feof(fRules)))
            {
                rulesArray[currentState].add(word, currentDestination);
                fgetpos(fRules, &curPosition);
                fscanf(fRules, "%s", word);
            }
            fsetpos(fRules, &curPosition);
        }

        if (isEquals(word, "finish"))
        {
            fscanf(fRules, "%d", &finishState);
        }
    }
    return (feof(fRules) && finishState != -1);
}

bool StateAutomaton::isExistsFile() const
{
    return (fRules != NULL);
}

bool StateAutomaton::isReservedWord(const char *word) const
{
    return (isEquals(word, "state")) || (isEquals(word, "finish") || isEquals(word, "goto"));
}

bool StateAutomaton::isDigit(const char symbol) const
{
    return (symbol >= '0' && symbol <= '9');
}

bool StateAutomaton::isLetter(const char symbol) const
{
    return ((symbol >= 'a' && symbol <= 'z') || (symbol >='A' && symbol <= 'Z'));
}

bool StateAutomaton::runOnExpression(const char *expression, int &position, bool showErrors)
{
    if (!isExistsFile())
    {
        printf("No file - no checking...\n");
        return false;
    }
    canShowErrorMsg = showErrors;
    return parseString(expression, position);
}

int StateAutomaton::getStrSize(const char *string)
{
    int size = 0;
    while (string[size] != '\0')
        size++;
    return size;
}

void StateAutomaton::lowerCase(char *string)
{
    int stringSize = getStrSize(string);
    for (int i = 0; i < stringSize; i++)
        if (string[i] >= 'A' && string[i] <= 'Z')
            string[i] = 'a' + (string[i] - 'A');
}

void StateAutomaton::showExpections(const int &currentState, const char curSymbol)
{
    printf("Error. We found '%c', but:\n", curSymbol);
    printf("we expected:\n");
    rulesArray[currentState].printOut();
}

int StateAutomaton::getNextState(const char symbol, const int &currentState)
{
    const int notFound = -1;
    int result = notFound;

    if (symbol == '\0' || isDigit(symbol) || isLetter(symbol))
    {
        if (symbol == '\0')
            result = rulesArray[currentState].getDestination("none");
        else
        {
            if (isDigit(symbol))
                result = rulesArray[currentState].getDestination("digit");
            else
                result = rulesArray[currentState].getDestination("letter");
        }
    }
    else
    {
        char word[2] = {symbol, '\0'};
        result = rulesArray[currentState].getDestination(word);
    }

    if (result == notFound)
        result = -currentState;

    return result;
}


bool StateAutomaton::parseString(const char *string, int &startPosition)
{
    int stringSize = getStrSize(string);
    int currentState = startState;
    int curPosition = startPosition;

    while (curPosition < stringSize)
    {
        currentState = getNextState(string[curPosition], currentState);

        if (currentState == finishState)
        {
            startPosition = curPosition;
            break;
        }

        if (currentState < 0)
        {
            if (getNextState('\0', -1 * currentState) == finishState)
            {
                startPosition = curPosition;
                return true;
            }

            if (canShowErrorMsg)
                showExpections(-1 * currentState, string[curPosition]);
            break;
        }


        curPosition++;
    }
    if ((currentState != finishState) && (currentState > 0))
        currentState = getNextState('\0', currentState);

    startPosition = curPosition;
    return currentState == finishState;
}


bool StateAutomaton::isEquals(const char first[], const char second[])
{
    int firstSize = getStrSize(first);
    if (firstSize != getStrSize(second))
        return false;

    for (int i = 0; i < firstSize; i++)
        if (first[i] != second[i])
            return false;
    return true;
}
