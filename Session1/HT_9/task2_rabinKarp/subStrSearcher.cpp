#include "subStrSearcher.h"

SubStrSearcher::SubStrSearcher()
{
    primePow = NULL;
}

SubStrSearcher::~SubStrSearcher()
{
    if (primePow != NULL)
        delete[] primePow;
}

int SubStrSearcher::getStrSize(const char *string)
{
    int size = 0;
    while (string[size] != '\0')
        size++;
    return size;
}

void SubStrSearcher::loadPrimes(const int &arrayLen)
{
    int const prime = 59;
    primePow = new unsigned int[arrayLen];
    primePow[0] = 1;
    for (int i = 1; i < arrayLen; i++)
        primePow[i] = primePow[i - 1] * prime;
}

unsigned int SubStrSearcher::getSymbolCode(const char &symbol)
{
    if (symbol >= 'a' && symbol <= 'z')
        return (symbol - 'a' + 1);
    if (symbol >= 'A' && symbol <= 'Z')
        return (symbol - 'A' + 1 + 26);
    return 0;
}

unsigned int SubStrSearcher::hash(const char *string, const int &shift, const int &count)
{
    unsigned int hash = 0;
    int index = shift;

    while ((string[index] != '\0') && (index < shift + count))
    {
        hash += getSymbolCode(string[index]) * primePow[index];
        index++;
    }
    return hash;
}

int SubStrSearcher::findEntriesCount(const char *subStr, const char *string)
{
    int result = 0;
    int subStrSize = getStrSize(subStr);
    int strSize = getStrSize(string);
    if (subStrSize > strSize)
        return result;

    loadPrimes(strSize);

    unsigned int *hashMap = new unsigned int[strSize];
    hashMap[0] = hash(string);
    for (int i = 1; i < strSize; i++)
        hashMap[i] = hashMap[i - 1] + hash(string, i);

    const unsigned int targetHash = hash(subStr, 0, subStrSize);

    unsigned int subHash = 0;
    for (int i = 0; i + subStrSize - 1 < strSize; i++)
    {
        subHash = hashMap[i + subStrSize - 1];
        if (i > 0)
            subHash -= hashMap[i - 1];

        if (subHash == targetHash * primePow[i])
            result++;
    }

    delete[] hashMap;
    return result;
}
