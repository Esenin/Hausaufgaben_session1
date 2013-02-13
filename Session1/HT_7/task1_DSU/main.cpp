#include <iostream>
#include "disjointSetUnion.h"

using namespace std;

void testing()
{
    int const studentsCount = 7;
    int const authors[7] = {0, 1, 2, 5, -1, 1 ,3};
    DisjointSetUnion mainSet(studentsCount);

    cout << "Incoming information:\n";
    for (int i = 0; i <studentsCount; i++)
    {
        mainSet.add(i, authors[i]);
        cout << (i + 1) << " " << (authors[i] + 1) << endl;
    }

    cout << "Output:\n";
    mainSet.writeAll();
    cout << "end of test\n" << endl;
}

void process()
{
    cout << "Enter students count\n";
    int studentsCount = 0;
    cin >> studentsCount;
    DisjointSetUnion mainSet(studentsCount);

    cout << "Input stident's ID and work-link like '5 4'\n"
         << "(First 3 students must link himselfs (0 0, 1 1, 2 2))\n";
    int identy = 0;
    int authorLink = 0;
    for (int i = 0; i < studentsCount; i++)
    {
        cin >> identy;
        cin >> authorLink;
        mainSet.add((identy - 1), (authorLink - 1));
    }

    cout << "Output:\n";
    mainSet.writeAll();
}

int main()
{
    testing();
    process();

    return 0;
}

