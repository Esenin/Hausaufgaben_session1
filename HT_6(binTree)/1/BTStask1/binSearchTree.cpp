#include "binSearchTree.h"

struct BinSearchTree::TreeNode
{
    int value;
    TreeNode *leftChild;
    TreeNode *rightChild;
};

BinSearchTree::BinSearchTree() :
    root(NULL)
{
}

BinSearchTree::~BinSearchTree()
{
    deleteAllNode(root);
}

void BinSearchTree::deleteAllNode(TreeNode *current)
{
    if (current == NULL)
        return;

    deleteAllNode(current->rightChild);
    deleteAllNode(current->leftChild);

    delete current;
    current = NULL;
}

BinSearchTree::TreeNode *BinSearchTree:: createNode(const int &value)
{
    TreeNode *newNode = new TreeNode;
    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

void BinSearchTree::addTo(TreeNode *&current, const int &newValue)
{
    if (current == NULL)
        current = createNode(newValue);

    if (current->value == newValue)
        return;

    if (newValue < current->value)
        addTo(current->leftChild, newValue);
    if (newValue > current->value)
        addTo(current->rightChild, newValue);
}

void BinSearchTree::add(const int newValue)
{
    addTo(root, newValue);
}

void BinSearchTree::writeValues(TreeNode *current, bool increasingOrder)
{
    if (current == NULL)
        return;

    writeValues((increasingOrder)? current->leftChild : current->rightChild,
                increasingOrder);
    cout << current->value << " ";
    writeValues((increasingOrder)? current->rightChild : current->leftChild,
                increasingOrder);
}

void BinSearchTree::writeAll(bool increasingOrder)
{
    if (root != NULL)
    {
        writeValues(root, increasingOrder);
        cout << endl;
    }
    else
        cout << "Tree is empty...\n";
}

bool BinSearchTree::isExists(const int value)
{
    TreeNode *temp = root;
    while (temp != NULL)
    {
        if (temp->value == value)
            return true;
        if (value < temp->value)
            temp = temp->leftChild;
        else
            temp = temp->rightChild;
    }
    return false;
}

bool BinSearchTree::isLeaf(TreeNode *target)
{
    return (target->leftChild == NULL && target->rightChild == NULL);
}

bool BinSearchTree::hasOneChild(TreeNode *target)
{
    return ((target->leftChild == NULL) ^ (target->rightChild == NULL));
}

void BinSearchTree::deleteLeaf(TreeNode *&target)
{
    delete target;
    target = NULL;
}

int BinSearchTree::popMostLeftChild(TreeNode *&current)
{
    if(current->leftChild != NULL)
        return popMostLeftChild(current->leftChild);
    else
    {
        int result = current->value;
        TreeNode *temp = current;
        current = current->rightChild;
        delete temp;
        return result;
    }
}

void BinSearchTree::deleteNode(TreeNode *&node, const int &value)
{
    if (value < node->value)
        deleteNode(node->leftChild, value);
    if (value > node->value)
        deleteNode(node->rightChild, value);

    if (node->value == value)
    {
        if (isLeaf(node))
                deleteLeaf(node);
        else
            if (hasOneChild(node))
            {
                TreeNode *temp = node;
                if (node->leftChild == NULL)
                    node = node->rightChild;
                else
                    node = node->leftChild;
                delete temp;
            }
        else
            node->value = popMostLeftChild(node->rightChild);
    }
}

bool BinSearchTree::remove(const int value)
{
    if (isExists(value))
    {
        deleteNode(root, value);
        return true;
    }
    return false;
}
