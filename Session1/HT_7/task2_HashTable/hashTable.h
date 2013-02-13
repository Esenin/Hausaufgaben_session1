#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "wordList.h"
#include "fstream"

class HashTable
{
public:
    HashTable(int elementsMaxCount);
    ~HashTable();
    void addWord(char word[]);
    void printResults();
    void printStatistics();

private:
    int const tableSize;
    WordList *table;
    FILE *fOutput;

    int hash(char *string);
    int *primePower;
};

#endif // HASHTABLE_H
