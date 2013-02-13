#ifndef FORMULATRANSLATOR_H
#define FORMULATRANSLATOR_H
#include <stack.h>
#include <SeninSupport.h>
#include <iostream>

using std::cout;
using std::endl;

class FormulaTranslator
{
public:
    FormulaTranslator(char const string[]);
protected:
    void finalPopAll(Stack *object);
    void popUntilSkobe(Stack *object);
    bool isOperand (char const &x);
    bool isOperator (char const &x);
    void translate (char const *string);
};

#endif // FORMULATRANSLATOR_H
