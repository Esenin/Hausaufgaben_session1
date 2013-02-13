#ifndef CALCTREE_H
#define CALCTREE_H

#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

int const strMaxLen = 255;

class CalcTree
{
public:
    CalcTree();
    ~CalcTree();
    void setNewTree(char string[]);
    void printTree();
    double calculateTree();

private:
    struct TreeNode;
    enum Operators
    {
        plus,
        minus,
        multiply,
        divide
    };

    TreeNode *root;
    int strSize(const char *string);
    int tenPower(int high);
    bool isOperator(const char &symbol);
    bool isDigit(const char &symbol);
    bool isLeftNext(TreeNode *current);
    Operators getOperator(const char &symbol);
    char operatorToChar(Operators const &action);

    void makeOperator(TreeNode *&current, const char &newOperator);
    void makeFigure(TreeNode *&current, char *figure, int length);
    int addNode(TreeNode *&current, const char *string, int curPos);
    void writeSubTree(TreeNode *current);
    double calculate(double const &first, double const &second, Operators const &action);
    double calcSubTree(TreeNode *current);
    void deleteSubTree(TreeNode *&current);
};

#endif // CALCTREE_H
