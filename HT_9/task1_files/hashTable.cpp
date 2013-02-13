#include "hashTable.h"


HashTable::HashTable(int elementsMaxCount) :
    tableSize(elementsMaxCount)
{
    table = new List[tableSize];
}

HashTable::~HashTable()
{
    delete[] table;
}

unsigned int HashTable::hash(const unsigned long long &value)
{
    unsigned int mask = 1431655765; // 10101010101b;
    return ((value ^ mask) % tableSize);
}

void HashTable::add(const unsigned long long &newValue)
{
    table[hash(newValue)].add(newValue);
}

bool HashTable::isExists(const long long &target)
{
    return table[hash(target)].isExists(target);
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
    cout << "HashTable stat:\n";
    cout << "Number of cells in hash table: " << tableSize << endl;
    cout << "All different words total: " <<  wordsCount << endl;
    cout << "Load factor is: " << ((float)wordsCount / tableSize) << endl;
    cout << "Most loaded cell is: " << maxCollisIndex << " with " << maxCollisions << " elements\n\n";
}
