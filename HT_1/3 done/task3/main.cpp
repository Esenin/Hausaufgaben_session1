#include <iostream>
#include <stdlib.h>

using namespace std;

void reverseArray(int *arr1, int start, int len1)
{
    for (int i = start; i < start + (len1 + 1) / 2; i++)
        swap(arr1[i], arr1[2 * start + len1 - i - 1]);
}

void writeArray(int *array, int count)
{
    for (int i = 0; i < count; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    cout << "Enter first array length:\n";
    int len1 = 1;
    cin >> len1;
    cout << "Enter length of second part:\n";
    int len2 = 1;
    cin >> len2;

    int mainArray[len1 + len2];
    for (int i = 0; i < len1 + len2; i++)
        mainArray[i] = rand() % 20;
    cout << "Current array is:\n";
    writeArray(mainArray, len1 + len2);

    reverseArray(mainArray, 0, len1);
    reverseArray(mainArray, len1, len2);
    reverseArray(mainArray, 0, len1 + len2);


    cout << "New array:\n";
    writeArray(mainArray, len1 + len2);

    return 0;
}

