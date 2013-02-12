#ifndef LIST_H
#define LIST_H

struct ListElement
{
    int value;
    ListElement *next;
};

class List
{
public:
    List();
    void add(int value);
    void writeAll();
    void deleteByValue(int value);
    void loopList();
    int getHeadVal();
    ~List();

    void rouletteDelete(int step);

protected:
    ListElement *head;
    ListElement *tail;
    int elementsCount;
    bool listLooped;
    void deleteAll();
};

#endif // LIST_H
