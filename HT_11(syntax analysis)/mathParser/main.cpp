#include <stdio.h>
#include "parser.h"

using namespace std;

bool isGoodExpression(const char string[])
{
    Parser analyzer;
    return analyzer.isValidExpression(string);
}

void autoTests()
{
    printf("Here is auto test...\n");
    printf("Answer '1' means good, '0' in case mistakes\n");
    printf("Input: (23.4 + 7 * (-8.3e-15))\n Answer: %d\n", isGoodExpression("23.4 + 7 * (-8.3e-15)"));
    printf("Input: 13.25 + 7\n Answer: %d\n", isGoodExpression("13.25 + 7"));
    printf("Input: (1 + 2 * 3) / 4\n Answer: %d\n", isGoodExpression("(1 + 2 * 3) / 4"));
    printf("Input: (1.25e-10 - 777)/(555.2 * (255 + 2))\n Answer: %d\n",
           isGoodExpression("(1.25e-10 - 777)/(555.2 * (255 + 2))"));
    printf("Input: (1 + 3 + 2 - 77.1e)\n Answer: %d\n", isGoodExpression("(1 + 3 + 2 - 77.1e)"));
    printf("Input: (1 + 1)/*2\n Answer: %d\n", isGoodExpression("(1 + 1)/*2"));
    printf("End of autotesting\n\n");
}

void checkExpression()
{
    printf("Enter some expression (e.g. 23.4 + 7 * (-8.3e-15))\n->");
    char string[strMaxLen] = {};
    scanf("%s", string);
    if (isGoodExpression(string))
        printf("Your expression is correct\n");
    else
        printf("Your expression is NOT correct\n");
}

int main()
{
    autoTests();
    checkExpression();

    return 0;
}

