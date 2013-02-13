#include <iostream>
#include <string.h>

using namespace std;

bool beenFound(char target[], char mainstr[], int start, int tlen)
{
    for (int curr = 0; curr < tlen; curr++)
        if (target[curr] != mainstr[start + curr])
            return false;
    return true;
}

int main()
{
    int const strMaxLen = 1024;

    cout << "Enter main string:\n";
    char bigStr[strMaxLen] = {};
    cin.getline(bigStr, strMaxLen);
    cout << "Enter string to find:\n";
    char target[strMaxLen] = {};
    cin.getline(target, strMaxLen);    

    int tlen = strlen(target);
    int blen = strlen(bigStr);

    int summ = 0;
    for (int start = 0; start <= blen - tlen; start++)
        if (beenFound(target, bigStr, start, tlen))
            summ++;

    cout << "Number of target in mainstring:\n" << summ;

    return 0;
}

