#include "formulatranslator.h"

FormulaTranslator::FormulaTranslator(char const string[])
{
    translate(string);
}

void FormulaTranslator::finalPopAll(Stack *object)
{
    while (!object->isEmpty())
        cout << object->pop() << " ";
}

bool FormulaTranslator::isOperator (const char &x)
{
    int const opCount = 7;
    char operators[opCount]  = "(+-*/^";

    for (int i = 0; i < opCount; i++)
        if (x == operators[i])
            return true;
    return false;
}

bool FormulaTranslator::isOperand (const char &x)
{
    bool isLetter = (x >= 'a' && x <= 'z');
    bool isNumber = (x >= '0' && x <= '9');
    return isLetter || isNumber;
}

void FormulaTranslator::popUntilSkobe(Stack *object)
{
    char current = object->pop();
    while (current != '(')
    {
        cout << current << " ";
        current = object->pop();
    }
}

void FormulaTranslator::translate(char const *string)
{
    int strSize = getStringSize(string);
    Stack *polandStack = new Stack;
    bool operandWritten = false;

    for (int i = startIndex; i < strSize; i++)
    {
        if (string[i] == ')')
            popUntilSkobe(polandStack);
        if (isOperand(string[i]))
        {
            cout << string[i];
            operandWritten = true;
        }
        if (isOperator(string[i]))
        {
            if (operandWritten)
            {
                cout << " ";
                operandWritten = false;
            }

            if (polandStack->isEmpty())
                polandStack->push(string[i]);
            else
            {
                if (string[i] != '(')
                    while (polandStack->getHeadPriority() >= getPriority(string[i]))
                        cout << polandStack->pop();
                polandStack->push(string[i]);
            }
        }
    }
    if (!polandStack->isEmpty())
        finalPopAll(polandStack);
    delete polandStack;
}
