#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>
#include "charLine.h"

class StringList
{
public:
    StringList();
    ~StringList();
    int getElementsCount() const;
    void add(const char *string, const int destination);
    bool isExists(const char *target) const;
    int getDestination(const char target[]) const;
    bool isEmpty();
    void printOut() const;

private:
    struct ListElement;
    ListElement *head;
    ListElement *tail;
    int elementsCount;
    void deleteAll();
};

#endif // LIST_H
