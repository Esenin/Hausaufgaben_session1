#ifndef DISJOINTSETUNION_H
#define DISJOINTSETUNION_H

#include <iostream>

using std::cout;
using std::endl;

class DisjointSetUnion
{
public:
    DisjointSetUnion(int studentsCount);
    ~DisjointSetUnion();
    void add(int const identy, int const author);
    int getAuthorOf(int const identy);
    void writeAll();

private:
    int const peopleCount;
    int *copyFrom;

    int findRealAuthor(int identy);
};

#endif // DISJOINTSETUNION_H
