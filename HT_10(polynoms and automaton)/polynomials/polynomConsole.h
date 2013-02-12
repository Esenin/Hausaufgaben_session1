#ifndef POLYNOMCONSOLE_H
#define POLYNOMCONSOLE_H

#include <iostream>
#include <stdlib.h>
#include <cstdlib> //clearscr
#include "polynomList.h"

using std::cout;
using std::cin;
using std::endl;

class PolynomConsole
{
public:
    PolynomConsole();
    ~PolynomConsole();
    void polynomeProcessor();


private:
    PolynomList *polynomArray;
    int const maxPolynoms;
    int listCount;

    void polynomMaker();
    void clearScreen();
    void createPolynome();
    void showAllPolynoms();
    void editPolynom();
    void deletePolynome();
    void pollynomesAdditor();
    void checkEquals();
    void calculate();
    void waiting();
};

#endif // POLYNOMCONSOLE_H
