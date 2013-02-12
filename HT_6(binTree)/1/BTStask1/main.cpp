#include <iostream>
#include "binSearchTree.h"

using namespace std;

enum Commands
{
    escape = 0,
    existing,
    add,
    remove,
    writeRising,
    writeDecrease
};

void processCommand(Commands current, BinSearchTree *mainTree)
{
    int input = 0;
    switch (current)
    {
    case escape:
        return;
    case existing:
    {
        cout << "Enter value you want to find:\n";
        cin >> input;
        cout << ((mainTree->isExists(input))? "Yes, it exists\n" : "No there\n");
        break;
    }
    case add:
    {
        cout << "Enter value you want to add:\n";
        cin >> input;
        mainTree->add(input);
        cout << "done.\n";
        break;
    }
    case remove:
    {
        cout << "Enter value you wanna remove:\n";
        cin >> input;
        cout << ((mainTree->remove(input))? "done.\n" : "Such value doesn't exists\n");
        break;
    }
    case writeRising:
    case writeDecrease:
    {
        cout << "Content is:\n";
        mainTree->writeAll(current == writeRising);
    }
    }
    cout << endl;
}

void simpleTest()
{
    BinSearchTree tree;
    cout << "Testing input/output\n";
    tree.add(5);
    tree.add(7);
    tree.add(2);
    tree.add(9);
    tree.add(1);
    tree.add(4);
    tree.add(8);
    tree.writeAll();
    cout << "//Right is: 1 2 4 5 7 8 9\n";
}

void helpMessage()
{
    cout << "Enter one of commands you want to do. (just a number):\n";
    cout << " 0 - exit\n"
         << " 1 - check existing\n"
         << " 2 - add new value\n"
         << " 3 - remove value\n"
         << " 4 - write all in increasing order\n"
         << " 5 - write in decreasing order\n";
}

int main()
{
    simpleTest();
    BinSearchTree *mainTree = new BinSearchTree();
    cout << "Welcome to binary-search-tree component\n";
    helpMessage();

    int currentCommand = escape;
    cin >> currentCommand;
    while (currentCommand != escape)
    {
        processCommand((Commands)currentCommand, mainTree);
        helpMessage();
        cin >> currentCommand;
    }

    delete mainTree;
    return 0;
}

