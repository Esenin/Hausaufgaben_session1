#include <iostream>
#include "wordsCalculator.h"


using namespace std;

void calcFile(char fileName[])
{
    cout << "Processing file: '" << fileName << "'...\n";
    int const maxWordsCount = 11120;
    WordsCalculator mainTextProcessor(fileName, maxWordsCount);
    mainTextProcessor.processFile();
    mainTextProcessor.printResults();
}

int main()
{
    int const strMaxSize = 256;
    cout << "Enter file name (ex. 'test.txt'):\n";
    char fileName[strMaxSize] = {};
    cin.getline(fileName, strMaxSize);
    calcFile(fileName);

    return 0;
}

