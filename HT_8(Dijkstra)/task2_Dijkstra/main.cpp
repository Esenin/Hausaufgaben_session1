#include <iostream>
#include "graph.h"

using namespace std;

void testGraphOnFile(char *fileName)
{
    Graph kernel;
    if (!kernel.loadFromFile(fileName))
    {
        cout << "File not found!\n";
        return;
    }
    kernel.calcDistance();
    kernel.printVertexDistance();
}

int main()
{
    int const strMaxLen = 255;
    char fileName[strMaxLen] = {};
    cout << "Enter file name  (e.g. 'matrix.txt'):\n";
    cin.getline(fileName, strMaxLen);

    testGraphOnFile(fileName);

    return 0;
}

