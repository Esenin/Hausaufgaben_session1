#include "charLine.h"


CharLine::CharLine() :
    size(0),
    stringLen(0)
{
    reconstruct();
}

CharLine::CharLine(const char *source)
{
    size = getStrSize(source);
    stringLen = (size / 50 + 1) * 50 + 1;
    string = new char[stringLen];
    for (int i = 0; i < size; i++)
        string[i] = source[i];
    string[size] = '\0';
}

CharLine::CharLine(const int source)
{
    if (source == 0)
    {
        size = 2;
        string = new char[2];
        string[0] = '0';
        string[1] = '\0';
        stringLen = 2;
        reconstruct();
        return;
    }

    size = 0;
    int integer = source;
    if (integer < 0)
    {
        size++;
        integer = -integer;
    }

    while (integer > 0)
    {
        integer /= 10;
        size++;
    }

    stringLen = size + 1;
    string = new char[stringLen];

    integer = source;
    if (source < 0)
        integer = -integer;
    int index = size - 1;
    while (integer != 0)
    {
        string[index] = (integer % 10) + '0';
        integer /= 10;
        index--;
    }
    if (index == 0)
        string[index] = '-';

    reconstruct();
}

CharLine::~CharLine()
{
    if (stringLen > 0)
        delete[] string;
}

int CharLine::getStrSize(const char *string)
{
    int size = 0;
    while (string[size] != '\0')
        size++;
    return size;
}

void CharLine::reconstruct()
{
    const int deltaOfReconstruct = 10;

    if (stringLen == 0)
    {
        stringLen = blockSize + 1;
        string = new char[stringLen];
        return;
    }

    if (stringLen - size >= deltaOfReconstruct)
        return;

    char *temp = new char[size + 1];
    for (int i = 0; i < size; i++)
        temp[i] = string[i];
    temp[size] = '\0';

    delete[] string;
    stringLen = ((size + deltaOfReconstruct) / blockSize + 1) * blockSize + 1;
    string = new char[stringLen];
    for (int i = 0; i <= size; i++)
        string[i] = temp[i];

    delete[] temp;
}

int CharLine::getLength() const
{
    return size;
}

int CharLine::getArrLen() const
{
    return stringLen;
}

void CharLine::pushBack(const char symbol)
{
    string[size++] = symbol;
    string[size] = '\0';
    reconstruct();
}

char CharLine::atPosition(const int &index) const
{
    if (index >= size)
        return '\0';
    return string[index];
}

void CharLine::setAtPosition(const char symbol, const int index)
{
    if (index >= size)
        pushBack(symbol);
    else
        string[index] = symbol;

}

void CharLine::pushForward(const char symbol)
{
    for (int i = size; i > 0; i--)
        string[i] = string[i - 1];
    string[0] = symbol;
    string[++size] = '\0';
    reconstruct();
}

char* CharLine::toCharArray() const
{
    return string;
}

int CharLine::toInteger() const
{
    int result = 0;
    int high = 1;
    int low = (string[0] == '-')? 1 : 0;
    for (int i = size - 1; i >= low; i--)
    {
        result += (string[i] - '0') * high;
        high *= 10;
    }

    if (low)
        result = -result;
    return result;
}

bool CharLine::isEqual(const char string[]) const
{
    if (size != getStrSize(string))
        return false;
    for (int i = 0; i < size; i++)
        if (atPosition(i) != string[i])
            return false;
    return true;
}

void CharLine::clear()
{
    if (stringLen > 0)
        delete string;
    stringLen = 0;
    size = 0;
    reconstruct();
}
