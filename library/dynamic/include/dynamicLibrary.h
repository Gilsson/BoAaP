#ifdef MYLIBAPI

#ifndef DYNAMIC_LIBRARY_H
#define DYNAMIC_LIBRARY_H

#include "../cmake-build-debug/shared_lib_export.h"

MYLIBAPI enum Exceptions
{
    LETTER_INPUT,
    WRONG_TYPE_INPUT,
    WRONG_SIGN_POSITION,
    WRONG_POINT_POSITION,
    INCORRECT_DATA,
    EMPTY_STRING,
    WRONG_SPACE_POSITION,
};

MYLIBAPI long double PrintNum(bool IsSizeInput);

MYLIBAPI bool recursionCheck(long double* arr, int start, int end);

MYLIBAPI void PrintInfo();

MYLIBAPI bool RestartProgram();

MYLIBAPI void SizeInput(char* str, int& N);

MYLIBAPI void RecursionOutput(bool output);

MYLIBAPI void FillElements(long double* arr, int N);

MYLIBAPI void TaskSolve();
#endif //DYNAMIC_LIBRARY_H
