#include <iostream>
#include <formulatranslator.h>

using namespace std;

void transToPoland(char const *mainStr)
{
    FormulaTranslator *polandObj = new FormulaTranslator(mainStr);
    delete polandObj;
}

void sampleTest(char testStr[])
{
    cout << "Input :\n";
    cout << testStr << endl << "Postfix form is:\n";
    transToPoland(testStr);
    cout << endl << "end of test \n\n";
}

int main()
{

    sampleTest("a + b");
    sampleTest("(a*b)+c");
    sampleTest("a*(b+c)");

    cout << "Wikipedia hard sample:\n";
    cout << " (right answer is: 3 4 2 * 1 5 - 2 ^ / +)" << endl;
    sampleTest("3 + 4 * 2 / (1 - 5)^2");
    cout << endl;

    char inputStr[stringMaxSize] = {};
    cout << "Enter formula in casual form (ex. a+b):\n";
    cin >> inputStr;

    transToPoland(inputStr);
    cout << endl;
    return 0;
}

