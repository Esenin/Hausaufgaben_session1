#include <iostream>
#include "floatMemViewer.h"


using namespace std;

void writeDifferent(double const &number)
{
    FloatMemViewer memViewer(number);
    cout << "Memory:\n";
    memViewer.writeAllBits();
    cout << endl << "Normalize view:\n";
    memViewer.writeNormalView();
    cout << endl;
}

void testing()
{
    cout << "Test 1.  '5'\n";
    writeDifferent(5);
    cout << "Test 2. '2012'\n";
    writeDifferent(2012);
    cout << "Test 2. '5.2'\n";
    writeDifferent(5.2);
    cout << "Test 2. '-14'\n";
    writeDifferent(-14);
}

int main()
{
    testing();
    cout << "Enter number in casual form (ex. '17')\n";
    double input = 0;
    cin >> input;
    writeDifferent(input);

    return 0;
}

