#include <iostream>
#include "SortedList.h"

using namespace std;

void getNew(SortedList *object)
{
    cout << "Enter new number:\n";
    int newNumb = 0;
    cin >> newNumb;
    object->add(newNumb);
}

void getToRemove(SortedList *object)
{
    cout << "Enter value to delete\n";
    int badVal = 0;
    cin >> badVal;
    object->deleteByValue(badVal);
}

void processCommand(SortedList *object, char input)
{
    char const addNew = '1';
    char const removeVal = '2';
    char const printAll = '3';
    if (input == addNew)
        getNew(object);
    if (input == removeVal)
        getToRemove(object);
    if (input == printAll)
        object->writeAll();
}

int main()
{
    SortedList *mainList = new SortedList;
    char input = '\0';
    do
    {
        cout << "Enter:\n"
             << "0 to exit\n"
             << "1 - add value to sorted list\n"
             << "2 - remove value from list\n"
             << "3 - print list\n";
        cin >> input;
        processCommand(mainList, input);
        cout << endl;
    }
    while (input != '0');

    cout << "Program has been closed\n";
    delete mainList;
    return 0;
}

