#include "wordsCalculator.h"

WordsCalculator::WordsCalculator(char fileName[], const int wordsMaxCount)
{
    fInput = fopen(fileName, "r");
    unsigned int fileSize = 0;
    fseek(fInput, 0, SEEK_END);
    fileSize = ftell(fInput);
    rewind(fInput);
    float const alpha = 25.15; // by experiemental results
    int wordsMaxCountDynamic = int(fileSize / alpha);
    hashTable = new HashTable(wordsMaxCountDynamic);

    //
    cout << "Size of input file is: " << fileSize << endl;
    cout << "Alpha = " << alpha << endl;
    cout << "Predicted words count is: " << wordsMaxCountDynamic << endl;
    //
}

WordsCalculator::~WordsCalculator()
{
    fclose(fInput);
    delete hashTable;
}

int WordsCalculator::strLength(const char *string)
{
    int size = 0;
    while ((string[size] != '\0') && (string[size] != '\n'))
        size++;
    return size;
}

void WordsCalculator::toLowerCase(char *string)
{
    int strSize = strLength(string);
    for (int i = 0; i < strSize; i++)
        if ((string[i] >= 'A') && (string[i] <= 'Z'))
            string[i] = char('a' + (string[i] - 'A'));
}

void WordsCalculator::clean(char *word)
{
    for (int i = 0; i < wordMaxSize; i++)
        word[i] = '\0';
}

bool WordsCalculator::isLetter(const char &symbol)
{
    return ((symbol >= 'a') && (symbol <= 'z'));
}

void WordsCalculator::processFile()
{
    int const strMaxSize = 2048;
    int const wordMaxSize = 35;


    if (fInput == NULL)
    {
        cout << "File not found!\n";
        return;
    }

    char word[wordMaxSize] = {};
    int wordSize = 0;
    bool isEditing = false;
    char string[strMaxSize] = {};

    while (!feof(fInput))
    {
        fgets(string, strMaxSize, fInput);
        toLowerCase(string);
        int strSize = strLength(string) + 1;
        for (int i = 0; i < strSize; i++)
        {
            if (isLetter(string[i]))
            {
                word[wordSize++] = string[i];
                isEditing = true;
            }
            else
                if (isEditing)
                    {
                        if (strLength(word) > 2)
                            hashTable->addWord(word);
                        isEditing = false;
                        clean(word);
                        wordSize = 0;
                    }
        }
    }
}

void WordsCalculator::printResults()
{
    if (fInput == NULL)
        return;
    hashTable->printResults();
    hashTable->printStatistics();
    cout << "You can find results in 'output.txt'\n";
}
