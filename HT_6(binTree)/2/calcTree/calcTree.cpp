#include "calcTree.h"

struct CalcTree::TreeNode
{
    int figure;
    Operators action;
    bool isOperator;
    TreeNode *leftChild;
    TreeNode *rightChild;
};

CalcTree::CalcTree() :
    root(NULL)
{
}

CalcTree::~CalcTree()
{
    deleteSubTree(root);
    root = NULL;
}

void CalcTree::deleteSubTree(TreeNode *&current)
{
    if (current->leftChild != NULL)
        deleteSubTree(current->leftChild);
    if (current->rightChild != NULL)
        deleteSubTree(current->rightChild);
    delete current;
}

char CalcTree::operatorToChar(const Operators &action)
{
    switch (action)
    {
    case plus:
        return '+';
    case minus:
        return '-';
    case multiply:
        return '*';
    case divide:
        return '/';
    }
    return '\0';
}

int CalcTree::tenPower(int high)
{
    if (high == 0)
        return 1;

    int result = 10;
    while (high > 1)
    {
        if (high % 2)
        {
            result *= 10;
            high--;
        }
        else
        {
            result *= result;
            high /= 2;
        }
    }
    return result;
}

CalcTree::Operators CalcTree::getOperator(char const &symbol)
{
    switch (symbol)
    {
    case '+':
    {
        return plus;
    }
    case '-':
    {
        return minus;
    }
    case '*':
    {
        return multiply;
    }
    case '/':
    {
        return divide;
    }
    default:
    {
        return plus;
        break;
    }
    }
}

int CalcTree::strSize(char const *string)
{
    int size = 0;
    while (string[size] != '\0')
        size++;
    return size;
}

bool CalcTree::isDigit(char const &symbol)
{
    return (symbol >= '0' && symbol <= '9');
}

bool CalcTree::isOperator(char const &symbol)
{
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

bool CalcTree::isLeftNext(TreeNode *current)
{
    return (current->leftChild == NULL);
}

void CalcTree::makeOperator(TreeNode *&current, char const &newOperator)
{
    current = new TreeNode;
    current->action = getOperator(newOperator);
    current->isOperator = true;
    current->figure = 0;
    current->leftChild = NULL;
    current->rightChild = NULL;
}

void CalcTree::makeFigure(TreeNode *&current, char *figure, int length)
{
    int value = 0;
    for (int i = 0; i < length; i++)
        value += (figure[i] - '0') * tenPower(length - i - 1);

    current = new TreeNode;
    current->figure = value;
    current->isOperator = false;
    current->action = plus;
    current->leftChild = NULL;
    current->rightChild = NULL;
}

void CalcTree::setNewTree(char string[])
{
    int const firstCharPos = 1;
    addNode(root, string, firstCharPos);
}


int CalcTree::addNode(TreeNode *&current, char const *string, int curPos)
{
    int strLen = strSize(string);
    bool isEditing = false;
    char word[strMaxLen] = {};
    int wordSize = 0;


    while (curPos < strLen)
    {
        if (isOperator(string[curPos]))
            makeOperator(current, string[curPos]);
        if (isDigit(string[curPos]))
        {
            isEditing = true;
            word[wordSize++] = string[curPos];
        }
        else
            if (isEditing)
            {
                if (isLeftNext(current))
                    makeFigure(current->leftChild, word, wordSize);
                else
                    makeFigure(current->rightChild, word, wordSize);
                isEditing = false;
                wordSize = 0;
            }
        if (string[curPos] == '(')
        {
            if (isLeftNext(current))
                curPos = addNode(current->leftChild, string, curPos + 1);
            else
                curPos = addNode(current->rightChild, string, curPos + 1);
        }
        else
            if (string[curPos] == ')')
                return curPos;
        curPos++;
    }
    return curPos;
}


void CalcTree::writeSubTree(TreeNode *current)
{
    if (current->leftChild != NULL)
    {
        cout << "(";
        writeSubTree(current->leftChild);
    }
    if (current->rightChild != NULL)
        writeSubTree(current->rightChild);
    if (current->isOperator)
        cout << operatorToChar(current->action) << ")";
    else
        cout << current->figure << " ";
}

void CalcTree::printTree()
{
    writeSubTree(root);
    cout << endl;
}

double CalcTree::calculate(const double &first, const double &second, const Operators &action)
{
    double zero = 1e-15;
    switch (action)
    {
    case plus:
        return first + second;
    case minus:
        return first - second;
    case multiply:
        return first * second;
    case divide:
    {
        if (second < zero)
            return 0;
        else
            return first / second;
    }
    }
    return 0;
}

double CalcTree::calcSubTree(TreeNode *current)
{
    if(current->isOperator)
        return calculate(calcSubTree(current->leftChild), calcSubTree(current->rightChild), current->action);
    else
        return current->figure;
}

double CalcTree::calculateTree()
{
    return calcSubTree(root);
}


