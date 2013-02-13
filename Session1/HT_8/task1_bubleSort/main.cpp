#include <iostream>
#include <stdlib.h>

using namespace std;

void printArray(int *array, int const &size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void bubbleSort(int *array, int const &size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i; j++)
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
}

void fillArray(int *array, int const &size)
{
    int const maxRand = 100;
    for (int i = 0; i < size; i++)
        array[i] = rand() % maxRand;
}

void test(int const arraySize)
{
    int *mainArray = new int[arraySize];
    fillArray(mainArray, arraySize);
    cout << "Array before sort:\n";
    printArray(mainArray, arraySize);

    bubbleSort(mainArray, arraySize);

    cout << "Sorted array is:\n";
    printArray(mainArray, arraySize);

    delete[] mainArray;
}

void autoTest()
{
    cout << "Test for single element:\n";
    test(1);
    cout << "Test 2, 10 elements\n";
    test(10);
    cout << "Test 3, 100 elements\n";
    test(100);
    cout << endl;
}

int main()
{
    autoTest();

    cout << "Enter array size:\n";
    int size = 0;
    cin >> size;
    test(size);

    return 0;
}

