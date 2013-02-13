#include <stack.h>

Stack::Stack() : head(NULL), elementsCount(0)
{
}

Stack::~Stack()
{
    while (!isEmpty())
        pop();
}


bool Stack::isEmpty() const
{
    return elementsCount < 1;
}

int Stack::getHeadPriority() const
{
    if (isEmpty())
        return pLowest;
    else
        return head->priority;
}

char Stack::pop()
{
    char out = head->value;
    StackElement *temp = head;
    head = head->next;
    delete temp;
    elementsCount--;
    return out;
}

void Stack::push(const char &newValue)
{
    StackElement *temp1 = new StackElement;
    temp1->next = head;
    head = temp1;
    head->value = newValue;
    head->priority = getPriority(newValue);
    elementsCount++;

}
