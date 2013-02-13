#include <iostream>
#include <stdlib.h>

using namespace std;

void writeArray(int *array, int toIndex)
{
    for (int i = 0; i < toIndex; i++)
        cout << array[i] << " ";
    cout << endl;
}


void qSort(int *array, int m, int n)
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
        qSort(array, left, n);
    if (right > m)
        qSort(array, m, right);
}

int main()
{
    int arrayLen = 1;
    cout << "Enter array length:\n";
    cin >> arrayLen;
    int array1[arrayLen];
    for (int i = 0; i < arrayLen; i++)
        array1[i] = rand() % 50;

    cout << "Current array:\n";
    writeArray(array1, arrayLen);

    qSort(array1, 0, arrayLen - 1);

    cout << "Sorted:\n";
    writeArray(array1, arrayLen);

    return 0;
}



