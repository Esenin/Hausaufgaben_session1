#include "hasher.h"

Hasher::Hasher() :
    strMaxLen(255)
{
    hashmap = NULL;
    primePow = new int[strMaxLen];

    int const prime = 59;
    primePow[0] = 1;
    for (int i = 1; i < strMaxLen; i++)
        primePow[i] = primePow[i - 1] * prime;
}

Hasher::~Hasher()
{
    delete[] primePow;
    if (!isTableFree())
    {
        hashmap->printStatistics();
        delete hashmap;
    }
}

bool Hasher::isTableFree()
{
    return hashmap == NULL;
}

int Hasher::predictTableSize(const char *fileName)
{
    fInput = fopen(fileName, "r");
    unsigned int fileSize = 0;
    fseek(fInput, 0, SEEK_END);
    fileSize = ftell(fInput);
    rewind(fInput);
    fclose(fInput);
    float const alpha = 25.15; // by experiemental results
    return int(fileSize / alpha);
}

unsigned long long Hasher::getCharCode(const char &symbol)
{
    if (symbol >= 'a' && symbol <= 'z')
        return (symbol - 'a' + 1);
    if (symbol >= 'A' && symbol <= 'Z')
        return (symbol - 'A' + 26 + 1);
    return (int)symbol;
}

unsigned long long Hasher::getHash(const char *target)
{
    unsigned long long hash = 0;
    int index = 0;
    while (target[index] != '\0')
    {
        hash += getCharCode(target[index]) * primePow[index];
        index++;
    }
    return hash;
}

void Hasher::makeHashMapFromFile(const char fileName[])
{
    if (isTableFree())
        hashmap = new HashTable(predictTableSize(fileName));

    fInput = fopen(fileName, "r");
    char string[strMaxLen];
    while (!feof(fInput))
    {
        fscanf(fInput, "%s", string);
        hashmap->add(getHash(string));
    }

    fclose(fInput);
}

bool Hasher::isExists(const char *target)
{
    if (isTableFree())
        return false;
    return hashmap->isExists(getHash(target));
}


int Hasher::getStrLen(const char *string)
{
    int size = 0;
    while (string[size] != '\0')
        size++;
    return size;
}


