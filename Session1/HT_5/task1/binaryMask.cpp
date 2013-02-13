#include "binaryMask.h"

BinaryMask::BinaryMask() :
    mainMask(0)
{
}

BinaryMask::~BinaryMask()
{
    clear();
}

void BinaryMask::setTrueAt(int const &index)
{
    mainMask = mainMask | (1 << index);
}

bool BinaryMask::getValueAt(int const &index)
{
    return mainMask & (1 << index);
}

void BinaryMask::clear()
{
    mainMask = 0;
}
