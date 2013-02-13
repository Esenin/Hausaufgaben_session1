#include "parser.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int x;
    cin >>x;

    FILE* file = fopen("file.txt", "r");

    if (parser(file))
        cout << "String in file belongs to our language.";
    else
        cout << "String in file DOES NOT belong to our language.";

    fclose(file);
    
    return 0;
}
