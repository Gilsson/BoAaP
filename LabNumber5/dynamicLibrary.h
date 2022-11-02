#ifndef DYNAMIC_LIBRARY_H
#define DYNAMIC_LIBRARY_H

enum Exceptions
{
    LETTER_INPUT,
    WRONG_TYPE_INPUT,
    WRONG_SIGN_POSITION,
    WRONG_POINT_POSITION,
    INCORRECT_DATA,
    EMPTY_STRING,
    WRONG_SPACE_POSITION,
};

long double PrintNum(bool IsSizeInput);

bool recursionCheck(long double* arr, int start, int end);

void PrintInfo();

bool RestartProgram();

void SizeInput(char* str, int& N);

void RecursionOutput(bool output);

void FillElements(long double* arr, int N);
#endif //DYNAMIC_LIBRARY_H
