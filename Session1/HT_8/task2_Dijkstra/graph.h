#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <climits>

using std::cout;
using std::endl;

class Graph
{
public:
    Graph(int vertexCount = 0);
    ~Graph();
    bool loadFromFile(char const *fileName);
    void calcDistance();
    void printVertexDistance();

private:
    int const noRoad;
    int **matrix;
    int *distance;
    int *parent;
    int matrixSize;

    void createMatrix(int const &size);
    int min(int const &a, int const b);
    int getMinVertex(bool *visited);
};

#endif // GRAPH_H
