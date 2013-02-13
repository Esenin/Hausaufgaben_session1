#ifndef CHARLINE_H
#define CHARLINE_H

class CharLine
{
public:
    CharLine(const char *source);
    CharLine(const int source);
    CharLine();
    ~CharLine();

    int getLength() const;
    int getArrLen() const;
    char atPosition(const int &index) const;
    void setAtPosition(const char symbol, const int index);
    void pushBack(const char symbol);
    void pushForward(const char symbol);
    char* toCharArray() const;
    int toInteger() const;
    bool isEqual(const char string[]) const;

private:
    static const int blockSize = 50;
    char *string;
    int size;
    int stringLen;

    static int getStrSize(const char *string);
    void reconstruct();
};

#endif // CHARLINE_H
