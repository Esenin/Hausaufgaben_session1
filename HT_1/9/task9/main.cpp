#include <iostream>

using namespace std;

bool canDivByTwo (int target)
{
    return target & 1 == 0;
}

int main()
{
    int base = 1;
    int high = 1;
    cout << "Enter two numbers (a^b) \n";
    cin >> base;
    cin >> high;

    long result = base;
    while (high > 1)
    {
        if (canDivByTwo(high))
        {
            result *= base * base;
            high /= 2;
        }
        else
        {
            result *= base;
            high--;
        }
    }

    if (high == 0)
        result = 1;

    cout << "a^b = ";
    cout << result << endl;

    return 0;
}

