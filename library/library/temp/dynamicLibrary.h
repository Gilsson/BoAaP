#ifndef DYNAMIC_LIBRARY_H
#define DYNAMIC_LIBRARY_H

#include "../cmake-build-debug/shared_lib_export.h"

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

SHARED_LIB_EXPORT long double PrintNum(bool IsSizeInput);

SHARED_LIB_EXPORT bool recursionCheck(long double* arr, int start, int end);

SHARED_LIB_EXPORT void PrintInfo();

SHARED_LIB_EXPORT bool RestartProgram();

SHARED_LIB_EXPORT void SizeInput(char* str, int& N);

SHARED_LIB_EXPORT void RecursionOutput(bool output);

SHARED_LIB_EXPORT void FillElements(long double* arr, int N);

SHARED_LIB_EXPORT void TaskSolve();
#endif //DYNAMIC_LIBRARY_H
