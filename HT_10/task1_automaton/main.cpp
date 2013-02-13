#include <stdio.h>
#include "stateAutomaton.h"

using namespace std;


bool isFloatNumber(const char string[])
{
    StateAutomaton mainProcessor;
    mainProcessor.setOptionsFile("rules.txt");
    return mainProcessor.runOnExpression(string);
}

void autoTest()
{
    printf("Here is auto test.\n");
    printf("Answer '1' means good, '0' in case mistakes\n");
    printf("Input: 13.25\n Answer: %d\n", isFloatNumber("13.25"));
    printf("Input: 13.25e-15\n Answer: %d\n", isFloatNumber("13.25e-15"));
    printf("Input: 13z25\n");
    printf(" Answer: %d\n", isFloatNumber("13z25"));
    printf("Input: 13.25eA99\n");
    printf(" Answer: %d\n", isFloatNumber("13.25eA99"));
    printf("End of autotesting...\n\n");
}

void checkInputCircle()
{
    char input[strMaxLen] = {};
    printf("Input some expressions, program will check is it float-number or not\n");
    printf("Type 'exit' to quit...   :\n");
    scanf("%s", input);
    while (!StateAutomaton::isEquals(input, "exit"))
    {
        if (isFloatNumber(input))
            printf("Answer: It's correct float num\n\n");
        else
            printf("Answer: Expression is incorrect\n\n");
        printf("Try again or type 'exit' to quit:\n");
        scanf("%s", input);
    }
}

int main()
{
    autoTest();
    checkInputCircle();
    return 0;
}

