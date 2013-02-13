#include <iostream>
#include <string.h>

using namespace std;

void push(int type, int *stack1, int &last)
{
    last++;
    stack1[last] = type;
}

int pop(int *stack, int &last)
{
    last--;
    return stack[last + 1];
}

bool isGoodSequence (int *stack, int &last, char string1[])
{
    bool goodSecq = true;
    for (int i = 0; i < strlen(string1); i++)
    {
        if (string1[i] == '(')
            push(1, stack, last);
        if (string1[i] == '[')
            push(2, stack, last);
        if (string1[i] == '{')
            push(3, stack, last);

        if (string1[i] == ')' && pop(stack, last) != 1)
            goodSecq = false;
        if (string1[i] == ']' && pop(stack, last) != 2)
            goodSecq = false;
        if (string1[i] == '}' && pop(stack, last) != 3)
            goodSecq = false;

        if (!goodSecq)
            break;
    }
    return goodSecq;
}

int main()
{
    int const maxLen = 255;
    int const empty = -1;

    int stack[maxLen] = {};
    int last = -1;

    char string1[maxLen] = {};
    cout << "Enter () sequence:\n";
    cin.getline(string1, maxLen);

    if (!isGoodSequence(stack, last, string1) || last > empty)
        cout << "It's BAD sequence";
    else
        cout << "All right!";

    return 0;
}

