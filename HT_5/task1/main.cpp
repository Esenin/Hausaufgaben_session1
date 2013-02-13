#include <iostream>
#include <string.h> //for strlen
#include "binaryMask.h"

using namespace std;

bool isLetter(char const &symbol)
{
    return ((symbol >= 'a') && (symbol <= 'z'));
}

void cleanWords(char const *string)
{
    BinaryMask bitMask;
    int strSize = strlen(string);
    for (int i = 0; i < strSize; i++)
    {
        if (!isLetter(string[i]))
        {
            cout << string[i];
            bitMask.clear();
        }
        else
            if (!bitMask.getValueAt(string[i] - 'a'))
            {
                cout << string[i];
                bitMask.setTrueAt(string[i] - 'a');
            }
    }
}

int main()
{
    int const stringMaxSize = 256;
    char string[stringMaxSize] = {};

    cout << "Enter text:\n";
    cin.getline(string, stringMaxSize);

    cout << "Answer is:\n";
    cleanWords(string);
    cout << endl;

    return 0;
}

