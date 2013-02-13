#ifndef SENINSUPPORT_H
#define SENINSUPPORT_H

int const maxRand = 10;
int const startIndex = 0;
int const stringMaxSize = 255;

enum operatorPriority
{
    pLowest = -1,
    pLow,
    pMiddle,
    pHigh
};

operatorPriority getPriority(char x);
void fillArrRand(int *array, int const size);
void writeArray(int *array, int const size);

int getStringSize (const char *string);

void qSSort(int *array, int m, int n);


#endif // SENINSUPPORT_H
