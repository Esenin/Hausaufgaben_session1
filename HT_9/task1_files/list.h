#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <fstream>


class List
{
public:
    List();
    ~List();
    int getElementsCount();
    void add(unsigned long long newValue);
    bool isExists(const long long &target);

private:
    struct ListElement;
    ListElement *head;
    ListElement *tail;
    int elementsCount;
    bool isEmpty();    
    void deleteAll();
};

#endif // LIST_H
