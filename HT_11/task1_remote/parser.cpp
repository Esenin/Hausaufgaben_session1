#include "parser.h"
#include <iostream>
#include <stdio.h>
using namespace std;

bool parser(FILE *file)
{
    char c = fgetc(file);

    return (addition(file, c) && c == '\n');  // Need to check, that all file processed
}

// ÑËÎÆÅÍÈÅ


bool addition(FILE* file, char& c) // E->TE'
{
    return (multiplication(file, c) && additionHelp(file, c));
}

bool additionHelp(FILE* file, char& c) // E'->+TE'|e
{
    if ((c =='+') || (c == '-'))
    {
        c = fgetc(file);
        if (multiplication(file, c) && (additionHelp(file, c)))
            return true;
        else
        {
            ungetc(c, file);
            return false;
        }
    }
    else
        return true; // right eps escape
}

// ÓÌÍÎÆÅÍÈÅ

bool multiplication(FILE* file, char& c) // T->ÑT'
{
    return(bracketsAndTokens(file, c) && multiplicationHelp(file, c));
}
bool multiplicationHelp(FILE* file, char& c)// T'->*ÑT'|e
{
    if ((c =='*') || (c == '/'))
    {
        c = fgetc(file);
        if (bracketsAndTokens(file, c) && (multiplicationHelp(file, c)))
            return true;
        else
        {
            ungetc(c,file);
            return false;
        }
    }
    else
        return true; // that's right
}

// ÑÊÎÁÊÈ È ÒÎÊÅÍÛ

bool bracketsAndTokens(FILE* file, char& c) // F->(E)|id
{

    //bool flag = true;
    //cout << "ryhfh: " << c << endl;
    if (c == '(')
    {
        c = fgetc(file);

        bool res = (addition(file, c));

        if (res && c == ')')
        {
            c = fgetc(file);
            //cout << "DAAAAAAAA";
            return true;
        }
        else
            return false;
    }
    else
    {
        bool result = (floatAutomatic(file, c));
        return result;
    }
}

bool floatAutomatic(FILE* file, char& c)
{
    //char c;

    //c = fgetc(file);
    if (c == '-')
        c = fgetc(file);
    if (!((c >= '0') && (c <= '9')))
        return false;

    enum Position{numberBeforePoint, point, eNumber, numberAfterPoint, signAfterE, degree};
    Position position = numberBeforePoint;

    cout << endl << "c: " << c << "position" << position << endl;
    while((!feof(file) && (c != '/') && (c != '*') && (c != '(') && (c != ')') && (c != '+') && (c != '-')) || ((position == signAfterE) && ((c == '+')||(c == '-'))))
    {
        //cout << endl << "c: " << c << "position" << position << endl;
        c = fgetc(file);
        cout << endl << "c: " << c << "position" << position << endl;

        switch(position)
        {
        case numberBeforePoint:
        {
            if ((c >= '0') && (c <= '9'))
                position = numberBeforePoint;
            else if (c == '.')
                position = point;
            else if (c == 'e')
                position = eNumber;
            else if ((c != '\n') && ((int)c != -1) && (c != '+') && (c != '-') && (c != '/') && (c != '*') && (c != '(') && (c != ')'))
                return false;
            break;
        }
        case point:
        {
            if ((c >= '0') && (c <= '9'))
                position = numberAfterPoint;
            else
                return false;
            break;
        }
        case numberAfterPoint:
        {
            if ((c >= '0') && (c <= '9'))
                position = numberAfterPoint;
            else if (c == 'e')
                position = eNumber;
            else if ((c != '\n') && ((int)c != -1) && (c != '+') && (c != '-') && (c != '/') && (c != '*') && (c != '(') && (c != ')'))
                return false;
            break;
        }
        case eNumber:
        {
            if ((c >= '0') && (c <= '9'))
                position = degree;
            else if ((c == '-') || (c == '+'))
                position = signAfterE;
            else
                return false;
            break;
        }
        case signAfterE:
        {
            if ((c >= '0') && (c <= '9'))
                position = degree;
            else
                return false;
            break;
        }
        case degree:
        {
            if (!((c >= '0') && (c <= '9')) && (c != '\n') && ((int)c != -1) && (c != '+') && (c != '-') && (c != '/') && (c != '*'))
                return false;
            break;
        }

        }
    }

    return true;
}
