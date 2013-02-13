#ifndef POLYNOMLIST_H
#define POLYNOMLIST_H

#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

class PolynomList
{
public:
    PolynomList();
    void copyConstructor(const PolynomList *base);
    ~PolynomList();

    static bool equals(const PolynomList &first, const PolynomList &second);
    static PolynomList *add(const PolynomList &left, const PolynomList &right);
    int getValue(const int x) const;
    bool isEmpty() const;
    void printPolynom() const;
    int getComponentsCount() const;
    void addPrimitiveComponent(const int factor, const int degree);
    void clearList();

private:
    struct ListElement;
    ListElement *head;
    int elementsCount;

    ListElement* getHead() const;
    void add(const PolynomList &element);
    void add(const ListElement *element);
    void addToTop(const ListElement *element);
    void addAfter(const ListElement *element, ListElement *position);
    void writeElement(const ListElement *element) const;
    void deleteZeros();
    void deleteTop();
    int power(const int &base, int degree) const;
};

#endif // POLYNOMLIST_H
