#include "polynomList.h"

PolynomList::PolynomList() :
    head(NULL),
    elementsCount(0)
{
}

struct PolynomList::ListElement
{
    int degree;
    int factor;
    ListElement *next;

    ListElement()
    {
        degree = 0;
        factor = 0;
        next = NULL;
    }

    ListElement(const ListElement *base)
    {
        degree = base->degree;
        factor = base->factor;
        next = NULL;
    }
};

void PolynomList::copyConstructor(const PolynomList *base)
{
    clearList();
    ListElement *current = base->getHead();
    while (current != NULL)
    {
        add(current);
        current = current->next;
    }
}

PolynomList::~PolynomList()
{
    while (!isEmpty())
        deleteTop();
}

void PolynomList::clearList()
{
    while (!isEmpty())
        deleteTop();
    head = NULL;
    elementsCount = 0;
}



PolynomList::ListElement* PolynomList::getHead() const
{
    return head;
}

void PolynomList::add(const PolynomList &element)
{
    ListElement *foreignPointer = element.getHead();
    while (foreignPointer != NULL)
    {
        add(foreignPointer);
        foreignPointer = foreignPointer->next;
    }
}

PolynomList* PolynomList::add(const PolynomList &left, const PolynomList &right)
{
    PolynomList *temp = new PolynomList;
    temp->add(left);
    temp->add(right);
    return temp;
}

void PolynomList::add(const ListElement *element)
{
    if (isEmpty() || (element->degree < head->degree))
    {
        addToTop(element);
        return;
    }

    if (element->degree == head->degree)
    {
        head->factor += element->factor;
        return;
    }

    ListElement *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->degree > element->degree)
        {
            addAfter(element, temp);
            return;
        }
        if (temp->next->degree == element->degree)
        {
            temp->next->factor += element->factor;
            deleteZeros();
            return;
        }

        temp = temp->next;
    }
    addAfter(element, temp);
}

void PolynomList::addToTop(const ListElement *element)
{
    ListElement *newElement = new ListElement(element);
    newElement->next = head;
    head = newElement;
    elementsCount++;
    deleteZeros();
}

void PolynomList::addAfter(const ListElement *element, ListElement *position)
{
    ListElement *newElement = new ListElement(element);
    newElement->next = position->next;
    position->next = newElement;
    elementsCount++;
    deleteZeros();
}

bool PolynomList::isEmpty() const
{
    return (elementsCount < 1);
}

void PolynomList::printPolynom() const
{
    if (!isEmpty())
        writeElement(head);
    else
        cout << "Polynom is empty";
    cout << endl;
}

void PolynomList::writeElement(const ListElement *element) const
{
    if (element->next != NULL)
        writeElement(element->next);
    if (element->factor == 1 && element->degree == 0)
    {
        cout << "+ 1";
        return;
    }
    cout << ((element->factor > 0)? "+" : "");
    if (element->factor != 1)
        cout << element->factor;
    if (element->degree > 0)
        cout << "x";
    if (element->degree > 1)
        cout << "^" << element->degree;
    cout << " ";
}

void PolynomList::deleteZeros()
{
    while (!isEmpty() && head->factor == 0)
        deleteTop();
    if (isEmpty())
        return;

    ListElement *current = head;
    while (current->next != NULL)
    {
        if (current->next->factor == 0)
        {
            ListElement *temp = current->next;
            current->next = temp->next;
            delete temp;
            elementsCount--;
        }
        current = current->next;
    }
}

void PolynomList::deleteTop()
{
    ListElement *temp = head;
    head = head->next;
    delete temp;
    elementsCount--;
}


int PolynomList::getComponentsCount() const
{
    return elementsCount;
}

int PolynomList::power(const int &base, int degree) const
{
    if (degree == 0)
        return 1;

    if (degree % 2 == 1)
        return base * power(base, degree - 1);
    else
    {
        int result = power(base, degree / 2);
        return result * result;
    }
}

int PolynomList::getValue(const int x) const
{
    int result = 0;
    if (isEmpty())
        return 0;

    ListElement *current = head;
    while (current != NULL)
    {
        result += current->factor * power(x, current->degree);
        current = current->next;
    }
    return result;
}

bool PolynomList::equals(const PolynomList &first, const PolynomList &second)
{
    if (first.getComponentsCount() != second.getComponentsCount())
        return false;
    ListElement *leftptr = first.getHead();
    ListElement *rightptr = second.getHead();

    while ((leftptr != NULL) && (rightptr != NULL))
    {
        if ((leftptr->degree != rightptr->degree) || (leftptr->factor != rightptr->factor))
            return false;
        else
        {
            leftptr = leftptr->next;
            rightptr = rightptr->next;
        }
    }
    return true;
}

void PolynomList::addPrimitiveComponent(const int factor, const int degree)
{
    ListElement *newElement = new ListElement;
    newElement->factor = factor;
    newElement->degree = degree;
    add(newElement);
}
