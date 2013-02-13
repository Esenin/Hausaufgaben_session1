#include <list.h>
#include <iostream>
#include <stdlib.h> // for NULL

using std::cout;

List::List()
{
    head = NULL;
    tail = head;
    listLooped = false;
    elementsCount = 0;
}

List::~List()
{
    deleteAll();
}

void List::add(int value)
{
    if (head == NULL)
    {
        head = new ListElement;
        head->value = value;
        tail = head;
    }
    else
    {
        tail->next = new ListElement;
        tail = tail->next;
        tail->value = value;
        tail->next = NULL;
    }
    elementsCount++;
}

void List::loopList()
{
    tail->next = head;
    listLooped = true;
}

void List::writeAll()
{
    ListElement *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        if (temp->next == head)
            break;
        else
            temp = temp->next;
    }
}

void List::deleteByValue(int badValue)
{
    ListElement *temp = head;
    while ((temp->next->value != badValue) && temp != NULL)
    {
        if (temp->next == head)
            break;
        else
            temp = temp->next;
    }
    if (temp->next->value == badValue)
    {
        ListElement *prev = temp;
        temp = temp->next;
        prev->next = temp->next;
        delete temp;
        elementsCount--;
    }
}

void List::rouletteDelete(int step)
{
    ListElement *temp = head;
    ListElement *prev = temp;
    while (elementsCount > 1)
    {
        for (int i = 0; i < step - 1; i++)
        {
            temp = temp->next;
        }
        prev = temp;
        temp = temp->next;
        prev->next = temp->next;
        delete temp;
        temp = prev;
        elementsCount--;
    }
    head = prev;
    tail = head;
}

int List::getHeadVal()
{
    return head->value;
}

void List::deleteAll()
{
    tail = head->next;
    while (elementsCount > 1)
    {
        head->next = tail->next;
        delete tail;
        tail = head->next;
        elementsCount--;
    }
    delete head;
    head = NULL;
    tail = NULL;
    elementsCount = 0;
}

