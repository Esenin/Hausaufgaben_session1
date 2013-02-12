#include <iostream>
#include <string.h>

using namespace std;

bool isPalindrom(char str1[])
{
    int strSize = strlen(str1);
    for (int i = 0; i < strSize / 2; i++)
    {
        if (str1[i] != str1[strSize - i - 1])
            return false;
    }
    return true;
}

int main()
{
    int const stringMaxSize = 255;
    char targetString[stringMaxSize] = {};
    cout << "Enter some string:\n";
    cin.getline(targetString, stringMaxSize);

    if (isPalindrom(targetString))
            cout << "String is palindrome";
    else cout << "String isn't palindrome";

    return 0;
}

