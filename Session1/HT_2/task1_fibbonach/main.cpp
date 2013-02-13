#include <iostream>

using namespace std;

long recFib(int n)
{
    if(n == 1 || n == 2)
        return 1;
    else
        return recFib(n - 1) + recFib(n - 2);
}

int circleFib(int n)
{
    long dataArr[n];
    dataArr[0] = 1;
    dataArr[1] = 1;
    for (int i = 2; i < n; i++)
        dataArr[i] = dataArr[i - 1] + dataArr[i - 2];

    return dataArr[n - 1];
}

int main()
{
    cout << "Enter Fibbonachi number:" << endl;
    int n = 1;
    cin >> n;

    cout << "Circle answer: "  << circleFib(n) << endl;
    cout << "Recurs. answer: " << recFib(n) << endl;

    return 0;
}

