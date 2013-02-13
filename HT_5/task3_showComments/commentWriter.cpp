#include "commentWriter.h"

CommentWriter::CommentWriter(char const *fileName) :
    maxLineSize(255),
    isSubString(false),
    isBigComment(false)
{
    fInput = fopen(fileName, "r");
    if (fInput == NULL)
        cout << "No file '" << fileName << "' existed!\n";
}

CommentWriter::~CommentWriter()
{
    fclose(fInput);
}

int CommentWriter::strLenght(const char *string)
{
    int size = 0;
    while (string[size] != '\0')
        size++;
    return size;
}

void CommentWriter::writeLineAt(char const *string, int const startIndex)
{
    int strSize = strLenght(string);
    if (strSize - startIndex <= 1)
        return;
    for (int i = startIndex; i < strSize; i++)
        cout << string[i];
}

void CommentWriter::processLine(char const *string)
{
    for (int i = 0; i < (strLenght(string) - 1); i++)
    {
        if (string[i] == '"')
            isSubString = !isSubString;
        if ((string[i] == '*') && (string[i + 1] == '/'))
            isBigComment = false;

        if (isBigComment || isSubString)
            continue;

        if ((string[i] == '/') && (string[i + 1] == '*'))
            isBigComment = true;

        if ((string[i] == string[i + 1]) && (string[i] == '/'))
        {
            writeLineAt(string, i + 2);
            break;
        }
    }

}


void CommentWriter::writeLineComments()
{
    if (fInput == NULL)
        return;

    cout << "---- Line comments in file are:\n";
    char currentLine[maxLineSize];

    while (!feof(fInput))
    {
        fgets(currentLine, maxLineSize, fInput);
        processLine(currentLine);
        isSubString = false;
    }
    cout << "---- End of file\n";
}
