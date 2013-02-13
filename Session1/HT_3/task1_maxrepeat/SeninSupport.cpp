#include <SeninSupport.h>
#include <stdlib.h> // for random
#include <iostream>

using std::cout;
using std::endl;
using std::swap;


void fillArrRand(int *array, int const size)
{
    for (int i = 0; i < size; i++)
        array[i] = rand() % maxRand;
}

void writeArray(int *array, int const size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void qSSort(int *array, int m, int n)
{
    int left = m;
    int right = n;
    int cool = array[(left + right) / 2];

    do
    {
        while (array[left] < cool)
            left++;
        while (array[right] > cool)
            right--;
        if (left <= right)
        {
            swap(array[left], array[right]);
            right--;
            left++;
        }
    }
    while (left <= right);

    if (left < n)
        qSSort(array, left, n);
    if (right > m)
        qSSort(array, m, right);
}
