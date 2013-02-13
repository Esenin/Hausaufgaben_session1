#ifndef FLOATMEMVIEWER_H
#define FLOATMEMVIEWER_H

#include <iostream>

using std::cout;
using std::endl;

class FloatMemViewer
{
public:
    FloatMemViewer(double const number);
    void writeAllBits();
    void writeNormalView();

private:
    char bitBuffer[64];
    int const accuracy;
    int lastNonZeroBit;
    void makeBitMap(double const &number);
    int getExponent();
    unsigned long long tenPower(int high);
    unsigned long long int getMantissa();
};

#endif // FLOATMEMVIEWER_H
