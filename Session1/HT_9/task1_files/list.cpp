#include "list.h"

struct List::ListElement
{
    unsigned long long value;
    int count;
    ListElement *next;

    ListElement()
    {
        next = NULL;
        count = 0;
    }
};

List::List() :
    head(NULL),
    tail(NULL),
    elementsCount(0)
{
}

List::~List()
{
    deleteAll();
    head = NULL;
    tail = NULL;
    elementsCount = 0;
}

bool List::isEmpty()
{
    return (elementsCount < 1);
}


int List::getElementsCount()
{
    return elementsCount;
}

void List::add(unsigned long long newValue)
{
    ListElement *temp = head;
    while (temp != NULL)
    {
        if (newValue == temp->value)
        {
            temp->count++;
            return;
        }
        temp = temp->next;
    }

    ListElement *newElement = new ListElement;
    newElement->value = newValue;

    if (isEmpty())
    {
        head = newElement;
        tail = head;
    }
    else
    {
        tail->next = newElement;
        tail = tail->next;
    }
    elementsCount++;
}


bool List::isExists(long long const &target)
{
    ListElement *temp = head;

    while (temp != NULL)
        if (temp->value == target)
            return true;
        else
            temp = temp->next;

    return false;
}


void List::deleteAll()
{
    ListElement *temp = head;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}
