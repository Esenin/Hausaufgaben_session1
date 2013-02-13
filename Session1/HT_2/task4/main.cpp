#include <iostream>

using namespace std;

int euclidCN(int a, int b)
{
    if (a == 0)
        return b;
    else
        return euclidCN(b % a, a);
}

bool isEachPrime(int a, int b)
{
    return euclidCN(a, b) == 1;
}

void printNum(int upArray[], int id)
{
    cout << upArray[id] << "/" << id << endl;
}

void fillArray(int *arr, int size)
{
    for (int i = 0; i <= size; i++)
        arr[i] = 1;
}

void calculate(int array[], int maxDown)
{
    fillArray(array, maxDown);
    int used = maxDown;
    while (array[maxDown] < maxDown)
    {
        int min = 1;
        for (int current = maxDown; current >= used - 1; current--)
            if (min * array[current] < current * array[min])
                min = current;

        printNum(array, min);

        array[min]++;
        while (!isEachPrime(min, array[min]))
            array[min]++;

        if (min < used)
            used--;
    }
}

void sampleTest(int array[])
{
    int const testNum = 5;
    cout << "Sample test for max dividor = 5\n";
    calculate(array, testNum);
}

int main()
{
    int const maxN = 1025;
    int upNum[maxN] = {};

    sampleTest(upNum);

    int maxDown = 2;
    cout << "Enter max possible down number:\n";
    cin >> maxDown;

    calculate(upNum, maxDown);

    return 0;
}

