#ifndef SUBSTRSEARCHER_H
#define SUBSTRSEARCHER_H

#include <stdlib.h>

class SubStrSearcher
{
public:
    SubStrSearcher();
    ~SubStrSearcher();

    int findEntriesCount(const char *subStr, const char *string);

private:
    unsigned int *primePow;

    int getStrSize(const char *string);
    void loadPrimes(const int &arrayLen);
    unsigned int getSymbolCode(const char &symbol);
    unsigned int hash(const char *string, const int &shift = 0, const int &count = 1);
};

#endif // SUBSTRSEARCHER_H
