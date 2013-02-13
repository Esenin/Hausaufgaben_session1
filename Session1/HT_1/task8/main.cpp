#include <iostream>

using namespace std;

int fact(long n)
{
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

int main()
{
    cout << "Enter N:\n";
    int target = 0;
    cin >> target;

    long fact1 = 1;
    for (int current = 1; current<=target; current++)
        fact1 *= current;

    long fact2 = 1;
    fact2 = fact(target);

    cout << "Factorial by iteration(1) and reccur.(2):\n";
    cout << fact1 <<endl;
    cout << fact2;
    return 0;
}

