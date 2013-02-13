#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "list.h"
#include <iostream>

using std::cout;
using std::endl;

class HashTable
{
public:
    HashTable(int elementsMaxCount);
    ~HashTable();
    void add(const unsigned long long &newValue);
    bool isExists(const long long &target);
    void printStatistics();

private:
    int const tableSize;
    List *table;

    unsigned int hash(const unsigned long long &value);
};

#endif // HASHTABLE_H
