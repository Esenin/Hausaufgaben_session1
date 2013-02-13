#include <iostream>
#include <list.h>

using namespace std;

void initList(List *list1, int const count)
{
    for (int i = 0; i < count; i++)
        list1->add(i);
    list1->loopList();
}

int getLastRoulette(int const step, int const count)
{
    List *mainList = new List;
    initList(mainList, count);
    mainList->rouletteDelete(step);
    int result = mainList->getHeadVal();
    delete mainList;
    return result;
}

int main()
{
    int count = 0;
    int posGood = 0;
    cout << "Enter elements count:\n";
    cin >> count;
    cout << "Enter your position to survive (from 1 (one) and less than "
         << count + 1 << ") :\n" ;
    cin >> posGood;
    if (--posGood == -1)
        posGood++;

    cout << "Good step for you is (are):\n";
    int summ = 0;
    for (int k = 2; k <= count; k++)
        if (getLastRoulette(k, count) == posGood)
        {
            cout << k << " ";
            summ++;
        }

    cout << "\nThere are " << summ << " good step-value(s) for you!" << endl;

    return 0;
}

