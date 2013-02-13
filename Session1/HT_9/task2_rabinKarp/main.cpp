#include <iostream>
#include "subStrSearcher.h"

using namespace std;

void findSubString(const char subStr[], const char string[])
{
    SubStrSearcher rabinKarpMachine;
    cout << "In '" << string << "' count of '" << subStr << "' is:\n";
    cout << rabinKarpMachine.findEntriesCount(subStr, string) << endl << endl;
}

void autoTest()
{
    cout << "Test#1 answer 3\n";
    findSubString("abba", "abbaababababbaaABBAaabba");
    cout << "Test#2 answer 1\n";
    findSubString("aRa", "BaRack Obama");
    cout << "Test#3 answer 7\n";
    findSubString("a", "zAaaaaaaaAz");
}

int main()
{
    autoTest();

    int const strMaxLen = 255;
    char bigString[strMaxLen];
    char subStr[strMaxLen];
    cout << "Enter big string:\n";
    cin.getline(bigString, strMaxLen);

    cout << "Enter substring, which you want to search:\n";
    cin.getline(subStr, strMaxLen);

    findSubString(subStr, bigString);

    return 0;
}

