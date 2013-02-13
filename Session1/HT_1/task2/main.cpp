#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a,b integers:\n";
    int a = 0;
    int b = 0;
    cin >> a;
    cin >> b;

    if (b > a)
    {
        a = a xor b;
        b = a xor b;
        a = a xor b;
    }

    int k = 1;
    while (b * (k + 1) <= a)
        k++;

    cout << "a div b =  ";
    cout << k;

    return 0;
}

