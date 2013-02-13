#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H

#include <stdlib.h> //for NULLptr
#include <iostream>

using std::cout;
using std::endl;

class BinSearchTree
{
public:
    BinSearchTree();
    ~BinSearchTree();

    void add(int const newValue);
    bool isExists(int const value);
    bool remove(int const value);
    void writeAll(bool increasingOrder = true);

private:
    struct TreeNode;

    TreeNode *root;
    TreeNode *createNode(const int &value);
    void addTo(TreeNode *&current, int const &newValue);
    void writeValues(TreeNode *current, bool increasingOrder = true);
    bool isLeaf(TreeNode *target);
    bool hasOneChild(TreeNode *target);
    int popMostLeftChild(TreeNode *&current);
    void deleteLeaf(TreeNode *&target);
    void deleteNode(TreeNode *&node, int const &value);
    void deleteAllNode(TreeNode *current);
};

#endif // BINSEARCHTREE_H
