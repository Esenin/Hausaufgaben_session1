#include <iostream>
#include <fstream>
#include "hasher.h"

using namespace std;

void findCommon() // 3 files problem
{
    Hasher kernel;
    const int strMaxLen = 255;
    FILE *fInput2;
    FILE *fOutput;
    cout << "Three files task\n"
         << "Enter first file-name (e.g. 'input1.txt'):\n";
    char fileName[strMaxLen];
    cin.getline(fileName, strMaxLen);
    kernel.makeHashMapFromFile(fileName);

    cout << "Enter name of second file:\n";
    cin.getline(fileName, strMaxLen);
    cout << "Processing...\n";

    fInput2 = fopen(fileName, "r");
    fOutput = fopen("output.txt", "w+");

    char string[strMaxLen];
    while (!feof(fInput2))
    {
        fscanf(fInput2, "%s", string);
        if (kernel.isExists(string))
            fprintf(fOutput, "%s\n", string);
    }

    fclose(fInput2);
    fclose(fOutput);
    cout << "Work done!\n";
}

int main()
{
    findCommon();

    return 0;
}

