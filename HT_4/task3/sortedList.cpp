#include "SortedList.h"
#include <iostream>
#include <stdlib.h> // for NULL

using std::cout;
using std::endl;

SortedList::SortedList()
{
    head = NULL;
    tail = head;
    elementsCount = 0;
}

SortedList::~SortedList()
{
    while (elementsCount > 0)
    {
        deleteHead();
    }
}

void SortedList::setNewHead(const int value)
{
    ListElement *newElement = new ListElement;
    newElement->value = value;
    newElement->next = head;
    head = newElement;
}

void SortedList::add(int value)
{
    if (elementsCount == 0 || head->value >= value)
        setNewHead(value);
    else
    {
        ListElement *current = head;
        while (current->next != NULL && current->next->value < value)
            current = current->next;
        ListElement *newElement = new ListElement;
        newElement->value = value;
        newElement->next = current->next;
        current->next = newElement;
    }
    elementsCount++;
}

void SortedList::writeAll() const
{
    cout << "List exists:\n";
    if (head == NULL)
        cout << "List is empty!\n";
    else
    {
        ListElement *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
    }
    cout << endl;
}

void SortedList::deleteNextElement(ListElement *prev)
{
    ListElement *temp = prev->next;
    prev->next = temp->next;
    delete temp;
    elementsCount--;
}

void SortedList::deleteHead()
{
    ListElement *temp = head;
    head = head->next;
    delete temp;
    elementsCount--;
}

void SortedList::deleteByValue(int const badValue)
{
    ListElement *temp = head;

    while (elementsCount > 0 && head->value == badValue)
        deleteHead();

    while (temp != NULL && temp->next != NULL && temp->next->value <= badValue)
    {
        if (temp->next->value == badValue)
            deleteNextElement(temp);
        temp = temp->next;
    }
}















