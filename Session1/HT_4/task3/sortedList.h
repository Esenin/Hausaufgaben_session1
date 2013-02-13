#ifndef SORTEDLIST_H
#define SORTEDLIST_H

struct ListElement
{
    int value;
    ListElement *next;
};

class SortedList
{
public:
    SortedList();
    void add(int value);
    void writeAll() const;
    void deleteByValue(int const value);
    ~SortedList();

protected:
    ListElement *head;
    ListElement *tail;
    int elementsCount;
    void setNewHead(int const value);
    void deleteHead();
    void deleteNextElement(ListElement *prev);
};

#endif // SORTEDLIST_H
