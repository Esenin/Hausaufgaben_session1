#ifndef WORDSCALCULATOR_H
#define WORDSCALCULATOR_H

#include <iostream>
#include <stdlib.h>
#include "hashTable.h"

using std::cout;
using std::endl;

class WordsCalculator
{
public:
    WordsCalculator(char fileName[], int const wordsMaxCount);
    ~WordsCalculator();
    void processFile();
    void printResults();

private:
    FILE *fInput;
    HashTable *hashTable;

    int strLength(char const *string);
    void toLowerCase(char *string);
    void clean(char *word);
    bool isLetter(char const &symbol);

};

#endif // WORDSCALCULATOR_H
