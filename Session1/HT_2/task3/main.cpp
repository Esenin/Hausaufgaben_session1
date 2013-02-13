#include <iostream>

using namespace std;

void showArr(int arr[], int size)
{
    if (size < 1)
        return;

    cout << arr[0];
    for (int i = 1; i <= size; i++)
        cout << "+" << arr[i];
    cout << endl;
}

void decomposeIt(int *arr, int remain, int position)
{
    if (remain == 0)
            showArr(arr, position - 1);

    for (int i = 1; i <= remain; i++)
    {
        /* печатаем в порядке возрастания слагаемых - гарантирует, что не будет повторов: */
        if (position > 0 && i < arr[position - 1])
            continue;

        arr[position] = i;

        decomposeIt(arr, remain - i, position + 1);
    }
}



void nigga(int victim, int maxX)
{
    int count = 0;
    for (int i = 0; i <= min(victim / 2, maxX); i++)
    {
        cout << i << " " << victim - i << endl;
        if (victim - i != i)
        {
            cout << victim - i << " " << i << endl;
            count++;
        }

        count++;
    }
    cout << "Out:  " << count;
}


int main()
{
//    int const maxN = 255;
//    int decomposition[maxN] = {};

//    // Sample test
//    cout << "Sample test for N=5\n";
//    decomposeIt(decomposition, 5, 0);
//    // end of test

//    int victim = 1;
//    cout << "Enter some number to partiotion operation (Max. " << maxN <<") :\n";
//    cin >> victim;

//    decomposeIt(decomposition, victim, 0);

    int x = 0;
    cin >> x;
    nigga(x, 7);

    return 0;
}

