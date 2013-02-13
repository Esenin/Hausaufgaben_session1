#ifndef WORDLIST_H
#define WORDLIST_H

#include <stdlib.h>
#include <fstream>


int const wordMaxSize = 35;

class WordList
{
public:
    WordList();
    ~WordList();
    int getElementsCount();
    void add(const char newWord[]);
    void printAll(FILE *fOutput);

private:
    struct ListElement;
    ListElement *head;
    ListElement *tail;
    int elementsCount;
    bool isEmpty();
    bool isEqual(const char string1[], const char string2[]);
    void deleteAll();
};

#endif // WORDLIST_H
