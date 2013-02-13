#include <iostream>

using namespace std;

int main()
{
    int combine[28];
    for (int i = 0; i < 28; i++)
        combine[i] = 0;

    for (int first = 0; first < 10; first++)
        for (int second = 0; second < 10; second++)
             for (int third = 0; third < 10; third++)
                 combine[first + second + third]++;

    int sum = 0;
    for (int i = 0; i < 28; i++)
        sum += combine[i] * combine[i];
    cout << "Luckytickets number:\n";
    cout << sum;
    return 0;
}

