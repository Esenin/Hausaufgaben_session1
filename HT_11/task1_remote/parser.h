#pragma once
#include <stdio.h>

bool parser(FILE* file);
bool floatAutomatic(FILE* file, char& c);

bool addition(FILE* file, char& c);
bool additionHelp(FILE* file, char& c);
bool multiplication(FILE* file, char& c);
bool multiplicationHelp(FILE* file, char& c);
bool bracketsAndTokens(FILE* file, char& c);
