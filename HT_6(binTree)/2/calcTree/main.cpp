#include <iostream>
#include <fstream>
#include "calcTree.h"

using namespace std;

void processFile(char const fileName[])
{
    FILE *fInput = fopen(fileName, "r");
    CalcTree mainTree;
    char buffer[strMaxLen] = {};

    while (!feof(fInput))
    {

        fgets(buffer, strMaxLen, fInput);
        mainTree.setNewTree(buffer);
        cout << "Calculating file: " << fileName << "...\n";
        cout << "Tree view:\n";
        mainTree.printTree();
        cout << "Result: " << mainTree.calculateTree() << endl;
    }

    fclose(fInput);
}

void simpleTest()
{
    cout << "Testing file 'test.txt'";
    processFile("test.txt");
    cout << "---> End of test\n";
}

int main()
{
    //simpleTest();

    cout << "Enter filename you want to calculate (ex. 'test.txt'):\n";
    char fileName[strMaxLen] = {};
    cin >> fileName;
    processFile(fileName);

    return 0;
}

