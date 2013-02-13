#include <iostream>
#include <SeninSupport.h>

using namespace std;

void findRepeater(int *array, int arrSize)
{
    int summ = 0;
    for (int i = arrSize - 1; i > 0; i--)
        if (array[i] == array[i - 1])
        {
            cout << array[i] << endl;
            summ++;
            break;
        }
    if (!summ)
        cout << "There are no such element\n";
}

void simpleTest()
{
    int const testSize = 13;
    cout << "This is a simple test\n" << "Array size = " << testSize << endl;
    int *testArr = new int [testSize];
    fillArrRand(testArr, testSize);
    cout << "Array is:\n";
    writeArray(testArr, testSize);

    qSSort(testArr, startIndex, testSize);

    cout << "Answer: \n";
    findRepeater(testArr, testSize);

    delete[] testArr;
}

int main()
{
    // Simple test
    simpleTest();
    cout << endl;
    // end of test

    int arrSize = 0;
    cout << "Enter array size:\n";
    cin >> arrSize;
    int *mainArray = new int[arrSize];

    fillArrRand(mainArray, arrSize);
    cout << "Current array is:\n";
    writeArray(mainArray, arrSize);

    qSSort(mainArray, startIndex, arrSize);

    cout << "Answer: \n";
    findRepeater(mainArray, arrSize);

    delete[] mainArray;

    return 0;
}

