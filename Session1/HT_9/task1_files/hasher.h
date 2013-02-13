#ifndef HASHER_H
#define HASHER_H

#include "hashTable.h"
#include <stdlib.h>
#include <fstream>

class Hasher
{
public:
    Hasher();
    ~Hasher();
    void makeHashMapFromFile(const char fileName[]);
    unsigned long long getHash(const char *target);
    bool isExists(const char *target);

private:
    FILE *fInput;
    const int strMaxLen;
    HashTable *hashmap;
    int *primePow;

    bool isTableFree();
    int predictTableSize(const char *fileName);
    unsigned long long getCharCode(const char &symbol);
    int getStrLen(const char *string);
};

#endif // HASHER_H
