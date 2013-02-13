#include <iostream>

using namespace std;

struct Element
{
    char symbol;
    int count;
};

int const notExists = -1;
int const empty = 0;

void initArray(Element *array)
{
    array[0].count = empty;
}

int arrSize(Element const *array)
{
    int size = 0;
    while (array[size].count != empty)
        size++;
    return size;
}

int getStringSize(char const *string)
{
    int strSize = 0;
    while (string[strSize] != '\0')
        strSize++;
    return strSize;
}

int findSymb(Element const *array, char const target)
{
    int index = 0;
    int size = arrSize(array);

    while (array[index].symbol != target && index < size)
        index++;

    if (array[index].symbol != target)
        index = notExists;
    return index;
}

void addNew(Element *array, char const newValue)
{
    int size = arrSize(array);
    array[size].symbol = newValue;
    array[size].count = 1;
    size++;
    array[size].count = 0;
}

void countSymbols(Element *array, char const *string)
{
    int strSize = getStringSize(string);
    for (int i = 0; i < strSize; i++)
    {
        int index = findSymb(array, string[i]);
        if (index == notExists)
            addNew(array, string[i]);
        else
            array[index].count++;
    }
}

bool checkEqual (Element const *targetArr, Element const *sourceArr)
{
    int tSize = arrSize(targetArr);
    int sSize = arrSize(sourceArr);

    if (sSize < tSize)
        return false;
    for (int i = 0; i < tSize; i++)
    {
        int index = findSymb(sourceArr, targetArr[i].symbol);
        if (index == notExists || sourceArr[index].count < targetArr[i].count)
            return false;
    }
    return true;
}

bool isEqual(char const *targetStr, char const *sourceStr)
{
    int elementMaxCount = max(getStringSize(targetStr), getStringSize(sourceStr));

    Element *targetArr = new Element[elementMaxCount];
    initArray(targetArr);
    countSymbols(targetArr, targetStr);
    Element *sourceArr = new Element[elementMaxCount];
    initArray(sourceArr);
    countSymbols(sourceArr, sourceStr);

    bool result = checkEqual(targetArr, sourceArr);
    delete[] targetArr;
    delete[] sourceArr;
    return result;
}

int main()
{
    int const stringMaxSize = 255;
    char sourceStr[stringMaxSize] = {};
    char targetStr[stringMaxSize] = {};
    cout << "Write target string:\n";
    cin.getline(targetStr, stringMaxSize);
    cout << "Write source string:\n";
    cin.getline(sourceStr, stringMaxSize);

    if (isEqual(targetStr, sourceStr))
        cout << "You can make target-string from source-string chars\n";
    else
        cout << "You CAN'T make target-string from source-string chars!\n";

    return 0;
}

