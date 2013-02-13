#ifndef COMMENTWRITER_H
#define COMMENTWRITER_H

#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;


class CommentWriter
{
public:
    CommentWriter(const char *fileName);
    ~CommentWriter();
    void writeLineComments();

private:
    FILE *fInput;
    int const maxLineSize;
    bool isSubString;
    bool isBigComment;
    int strLenght(const char *string);
    void processLine(const char *string);
    void writeLineAt(const char *string, const int startIndex);

};

#endif // COMMENTWRITER_H
