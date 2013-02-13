#include "wordList.h"

struct WordList::ListElement
{
    char word[wordMaxSize];
    int count;

    ListElement *next;

    ListElement()
    {
        for (int i = 0; i < wordMaxSize; i++)
            word[i] = '\0';
    }
};

WordList::WordList() :
    head(NULL),
    tail(NULL),
    elementsCount(0)
{
}

WordList::~WordList()
{
    deleteAll();
    head = NULL;
    tail = NULL;
    elementsCount = 0;
}

bool WordList::isEmpty()
{
    return (elementsCount < 1);
}

bool WordList::isEqual(char const string1[], char const string2[])
{
   // cout << "=3   " << string1 << " <> " << string2 << endl;
    int index = 0;
    while (string1[index] != '\0' && string2[index] != '\0')
    {
        if (string1[index] != string2[index])
            return false;
        index++;
    }
    return true;
}

int WordList::getElementsCount()
{
    return elementsCount;
}

void WordList::add(char const *newWord)
{
    ListElement *temp = head;
    while (temp != NULL)
    {
        if (isEqual(newWord, temp->word))
        {
            temp->count++;
            return;
        }
        temp = temp->next;
    }

    ListElement *newElement = new ListElement;
    int index = 0;
    do
    {
        newElement->word[index] = newWord[index];
        index++;
    }
    while (newWord[index] != '\0');
    newElement->word[index] = '\0';
    newElement->count = 1;
    newElement->next = NULL;

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

void WordList::printAll(FILE *fOutput)
{
    ListElement *temp = head;
    while (temp != NULL)
    {
        fprintf(fOutput, "%4d   %s\n", temp->count, temp->word);
        temp = temp->next;
    }
}


void WordList::deleteAll()
{
    ListElement *temp = head;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}
