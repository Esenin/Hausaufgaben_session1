#include "graph.h"

Graph::Graph(int vertexCount) :
    noRoad(-1),
    matrixSize(0)
{
    if (vertexCount > 0)
        createMatrix(vertexCount);
}

Graph::~Graph()
{
    if (matrixSize == 0)
        return;

    for (int i = 0; i < matrixSize; i++)
        delete[] matrix[i];
    delete[] matrix;
    delete[] distance;
    delete[] parent;
}

void Graph::createMatrix(const int &size)
{
    if (matrixSize > 0)
        return;

    matrix = new int*[size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];

    matrixSize = size;
    distance = new int[matrixSize];
    parent = new int[matrixSize];

    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < matrixSize; j++)
            matrix[i][j] = noRoad;
}

bool Graph::loadFromFile(const char *fileName)
{
    FILE *fInput = fopen(fileName, "r");
    if (fInput == NULL)
        return false;

    int edgeCount = 0;
    int size = 0;
    fscanf(fInput, "%d", &size);
    fscanf(fInput, "%d", &edgeCount);

    createMatrix(size);

    int from = 0;
    int where = 0;
    int distance = 0;
    for (int i = 0; i < edgeCount; i++)
    {
        fscanf(fInput, "%d", &from);
        fscanf(fInput, "%d", &where);
        fscanf(fInput, "%d", &distance);

        matrix[from - 1][where - 1] = distance;
        matrix[where - 1][from - 1] = distance;
    }

    fclose(fInput);
    return true;
}

int Graph::getMinVertex(bool *visited)
{
    int next = -1;
    int minDistance = INT_MAX;
    for (int i = 0; i < matrixSize; i++)
        if ((distance[i] != noRoad && !visited[i]) &&
                (distance[i] < minDistance))
        {
            next = i;
            minDistance = distance[i];
        }
    return next;
}

int Graph::min(const int &a, const int b)
{
    return (a < b)? a : b;
}

void Graph::calcDistance()
{
    // Dijkstra
    bool *visited = new bool[matrixSize];
    for (int i = 0; i < matrixSize; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[0] = 0;
    parent[0] = 0;

    int curVertex = 0;
    while (curVertex >= 0)
    {
        visited[curVertex] = true;

        for (int i = 0; i < matrixSize; i++)
            if (matrix[curVertex][i] != noRoad)
                if (distance[curVertex] + matrix[curVertex][i] < distance[i])
                {
                    distance[i] = distance[curVertex] + matrix[curVertex][i];
                    parent[i] = curVertex;
                }

        curVertex = getMinVertex(visited);
    }

    delete[] visited;
}

void Graph::printVertexDistance()
{
    bool *visited = new bool[matrixSize];
    for (int i = 0; i < matrixSize; i++)
        visited[i] = false;

    cout << "City num: - distance to first city: - full path:\n";
    int current = 0;
    while (current >= 0)
    {
        visited[current] = true;
        cout << current + 1 << "  distance: " << distance[current] << " Full path: ";

        int j = current;
        do
        {
            cout << parent[j] + 1 << " ";
            j = parent[j];
        }
        while (j != 0);
        cout << endl;

        current = getMinVertex(visited);
    }
    cout << endl;

    delete[] visited;
}

