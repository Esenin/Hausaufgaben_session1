#include "floatMemViewer.h"

FloatMemViewer::FloatMemViewer(const double number) :
    accuracy(50),
    lastNonZeroBit(0)
{
    makeBitMap(number);
}


void FloatMemViewer::makeBitMap(const double &number)
{
    int const byteCount = 8;
    int const bitCount = 8;
    unsigned char *cortege = (unsigned char*)&number;
    unsigned char curByte = 0;
    int index = 0;
    for (int i = byteCount - 1; i >= 0; i--)
    {
        curByte = cortege[i];
        for (int j = bitCount - 1; j >= 0; j--)
        {
            index = ((byteCount - 1) - i) * 8 + ((bitCount - 1) - j);
            if ((curByte & (1 << j)) > 0)
            {
                bitBuffer[index] = '1';
                lastNonZeroBit = index;
            }
            else
                bitBuffer[index] = '0';
        }
    }
}



int FloatMemViewer::getExponent()
{
    int const firstBit = 1;
    int const bitCount = 11;
    int const shift = 1023;  // 2^10 - 1
    int movedExp = 0;
    for (int i = firstBit; i < firstBit + bitCount; i++)
        if (bitBuffer[i] == '1')
            movedExp += (1 << (bitCount - i));

    return (movedExp - shift);
}

unsigned long long FloatMemViewer::tenPower(int high)
{
    unsigned long long result = 10;
    while (high > 1)
    {
        if (high % 2)
        {
            result *= 10;
            high--;
        }
        else
        {
            result *= result;
            high /= 2;
        }
    }
    return result;
}


unsigned long long FloatMemViewer::getMantissa()
{
    int const firstBit = 12;
    int const lastBit = 45; //if bigger accuracy decreases for fractions.
    unsigned long long result = 0;

    for (int i = firstBit; i < lastBit; i++)
    {
        if (bitBuffer[i] == '1')
            result += (tenPower(i - firstBit + 1) / (1 << (i - firstBit + 1)));
        if (i > lastNonZeroBit || (result > tenPower(19)))
            break;
        else
            result *= 10;
    }

    return result;
}

void FloatMemViewer::writeAllBits()
{
    int const expCount = 11;
    int const mantissCount = 52;
    cout << bitBuffer[0] << " ";

    for (int i = 1; i < 1 + expCount; i++)
        cout << bitBuffer[i];
    cout << " ";
    for (int i = expCount + 1; i < 1 + expCount + mantissCount; i++)
        cout << bitBuffer[i];
    cout << endl;
}

void FloatMemViewer::writeNormalView()
{
    int const signPos = 0;
    cout << ((bitBuffer[signPos] == '0')? "+" : "-");
    cout << "1." << getMantissa();
    cout << " *2^(" << getExponent() << ")" << endl;
}




