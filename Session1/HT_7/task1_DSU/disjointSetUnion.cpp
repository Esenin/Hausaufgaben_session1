#include "disjointSetUnion.h"

DisjointSetUnion::DisjointSetUnion(int studentsCount) :
    peopleCount(studentsCount)
{
    copyFrom = new int[peopleCount];
    for (int i = 0; i < peopleCount; i++)
        copyFrom[i] = -1;
}

DisjointSetUnion::~DisjointSetUnion()
{
    delete[] copyFrom;
}

int DisjointSetUnion::findRealAuthor(int identy)
{
    if (identy == copyFrom[identy])
        return identy;
    copyFrom[identy] = findRealAuthor(copyFrom[identy]);
    return copyFrom[identy];
}

void DisjointSetUnion::add(int identy, int author)
{
    copyFrom[identy] = author;
}

int DisjointSetUnion::getAuthorOf(const int identy)
{
    int const nothing = -1;
    return (copyFrom[identy] <= nothing)? nothing : findRealAuthor(copyFrom[identy]);
}

void DisjointSetUnion::writeAll()
{
    cout << "Student : author  ('0' in case 'out of work')\n";
    for (int i = 0; i < peopleCount; i++)
    {
        cout << (i + 1) << "  copied from: " << (getAuthorOf(i) + 1) << endl;
    }
}
