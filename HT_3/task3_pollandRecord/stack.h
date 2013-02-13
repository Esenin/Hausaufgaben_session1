#ifndef STACK_H
#define STACK_H
#include <SeninSupport.h>
#include <stdlib.h> // for NULL handle

struct StackElement
{
    char value;
    operatorPriority priority;
    StackElement *next;
};



class Stack
{
public:
    Stack();
    void push(char const &newValue);
    bool isEmpty() const;
    int getHeadPriority() const;
    char pop();
    ~Stack();
protected:
    StackElement *head;
    int elementsCount;    
};

#endif // STACK_H
