#ifndef DYNAMIC_LIBRARY_H
#define DYNAMIC_LIBRARY_H

#include "cmake-build-debug/mydynamiclib_export.h"

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

MYDYNAMICLIB_EXPORT long double PrintNum(bool IsSizeInput);

MYDYNAMICLIB_EXPORT bool recursionCheck(long double* arr, int start, int end);

MYDYNAMICLIB_EXPORT void PrintInfo();

MYDYNAMICLIB_EXPORT bool RestartProgram();

MYDYNAMICLIB_EXPORT void SizeInput(char* str, int& N);

MYDYNAMICLIB_EXPORT void RecursionOutput(bool output);

MYDYNAMICLIB_EXPORT void FillElements(long double* arr, int N);

MYDYNAMICLIB_EXPORT void TaskSolve();
#endif //DYNAMIC_LIBRARY_H
