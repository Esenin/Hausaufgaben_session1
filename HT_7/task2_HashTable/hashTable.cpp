#include "hashTable.h"


HashTable::HashTable(int elementsMaxCount) :
    tableSize(elementsMaxCount)
{
    table = new WordList[tableSize];
    fOutput = fopen("output.txt", "w");

    int const letterCount = 26;
    int const prime = 31;
    primePower = new int[letterCount];
    primePower[0] = prime;
    for (int i = 1; i < letterCount; i++)
        primePower[i] = primePower[i - 1] * prime;
}

HashTable::~HashTable()
{
    delete[] table;
    delete[] primePower;
    fclose(fOutput);
}

int HashTable::hash(char *string)
{
    unsigned int hash = 0;
    int index = 0;
    while (string[index] != '\0')
    {
        hash += primePower[string[index] - 'a'];
        index++;
    }
    return hash % tableSize;
}

void HashTable::addWord(char word[])
{
    table[hash(word)].add(word);
}

void HashTable::printResults()
{
    fprintf(fOutput, "Statistics of words usage:\n\n");
    for (int i = 0; i < tableSize; i++)
    {
        table[i].printAll(fOutput);
    }
}

void HashTable::printStatistics()
{
    int maxCollisions = 0;
    int maxCollisIndex = -1;
    int wordsCount = 0;
    for (int i = 0; i < tableSize; i++)
    {
        wordsCount += table[i].getElementsCount();
        if (table[i].getElementsCount() > maxCollisions)
        {
            maxCollisions = table[i].getElementsCount();
            maxCollisIndex = i;
        }
    }
    fprintf(fOutput, "HashTable stat:\n");
    fprintf(fOutput, "Number of cells in hash table: %d\n", tableSize);
    fprintf(fOutput, "All different words total: %d\n", wordsCount);
    fprintf(fOutput, "Load factor is: %f \n", ((float)wordsCount / tableSize));
    fprintf(fOutput, "Most loaded cell is: %d, with %d elements\n", maxCollisIndex, maxCollisions);
}
