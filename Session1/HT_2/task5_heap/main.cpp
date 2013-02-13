#include <iostream>
#include <stdlib.h>

using namespace std;

void writeArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int getChild(int curr)
{
    return (curr + 1) * 2 - 1;
}

int getParent(int curr)
{
    return (curr + 1) / 2 - 1;
}

void pushUp(int *arr, int pos)
{
    while (pos > 0 && arr[pos] > arr[getParent(pos)])
    {
        swap(arr[pos], arr[getParent(pos)]);
        pos = getParent(pos);
    }
}

void pushDown(int *arr, int size)
{
    int current = 0;
    while (getChild(current) < size)
    {
        int max = getChild(current);
        if (arr[getChild(current)] < arr[getChild(current) + 1])
            max++;
        if (arr[current] > arr[max])
            break;

        swap(arr[current], arr[max]);
        current = max;
    }
}

void fillArray(int *arr, int size)
{
    int const maxRand = 50;
    for (int i = 0; i < size; i++)
        arr[i] = rand() % maxRand;
}

int getMax(int *arr, int &size)
{
    int result = arr[0];
    size--;
    arr[0] = arr[size];
    pushDown(arr, size);
    return result;
}

void heapSort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        pushUp(arr, i);

    int temp = 0;
    for (int i = size; i > 0; i--)
    {
        temp = getMax(arr, size);
        arr[size] = temp;
    }
}


int main()
{
    int const maximum = 1025;
    int mainArray[maximum] = {};

    cout << "Enter array size:\n";
    int arrSize = 1;
    cin >> arrSize;

    fillArray(mainArray, arrSize);
    writeArray(mainArray, arrSize);

    heapSort(mainArray, arrSize);

    cout << "Sorted:\n";
    writeArray(mainArray, arrSize);

    return 0;
}

