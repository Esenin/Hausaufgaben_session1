#include "stringList.h"

struct StringList::ListElement
{
    CharLine value;
    int destinationState;
    ListElement *next;

    ListElement(const char *string, const int &destination)
    {
        destinationState = destination;
        next = NULL;

        int index = 0;
        while (string[index] != '\0')
            value.pushBack(string[index++]);
    }
};

StringList::StringList() :
    head(NULL),
    tail(NULL),
    elementsCount(0)
{
}

StringList::~StringList()
{
    deleteAll();
    head = NULL;
    tail = NULL;
    elementsCount = 0;
}

bool StringList::isEmpty()
{
    return (elementsCount < 1);
}

int StringList::getElementsCount() const
{
    return elementsCount;
}

void StringList::add(const char *string, const int destination)
{
    ListElement *newElement = new ListElement(string, destination);

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


bool StringList::isExists(const char *target) const
{
    ListElement *temp = head;

    while (temp != NULL)
        if (temp->value.isEqual(target))
            return true;
        else
            temp = temp->next;

    return false;
}

int StringList::getDestination(const char target[]) const
{
    const int notExists = -1;

    ListElement *temp = head;

    while (temp != NULL)
        if (temp->value.isEqual(target))
            return temp->destinationState;
        else
            temp = temp->next;

    return notExists;
}

void StringList::printOut() const
{
    ListElement *temp = head;

    while (temp != NULL)
    {
        printf("'%s' ", temp->value.toCharArray());
        temp = temp->next;
    }
    printf("\n");
}


void StringList::deleteAll()
{
    ListElement *temp = head;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}
