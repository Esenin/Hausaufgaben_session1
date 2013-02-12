#include <iostream>

using namespace std;

#define arraySize (nMax + 1)

void doEratosphen(bool *array, int nMax)
{
    array[1] = true;
    int step = 2;
    for (int current = 1; current < nMax / 2 + 1; current++)
    {
        if (!array[current])
        {
            while (current * step <= nMax)
            {
                array[current * step] = true;
                step++;
            }
            step = 2;
        }
    }
}

int main()
{
    cout << "Enter maximum:\n";
    int nMax = 1;
    cin >> nMax;

    bool betaArray[arraySize];
    for (int i = 0; i < arraySize; i++)
        betaArray[i] = false;

    doEratosphen(betaArray, nMax);

    cout << "Prime array:\n";
    for (int i = 1; i <= nMax; i++)
        if (!betaArray[i])
            cout << i << " ";

    return 0;
}

