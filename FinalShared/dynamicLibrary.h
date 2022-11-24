#ifndef DYNAMIC_LIBRARY_H
#define DYNAMIC_LIBRARY_H

extern "C" __declspec(dllexport) enum Exceptions
{
    LETTER_INPUT,
    WRONG_TYPE_INPUT,
    WRONG_SIGN_POSITION,
    WRONG_POINT_POSITION,
    INCORRECT_DATA,
    EMPTY_STRING,
    WRONG_SPACE_POSITION,
    TOO_BIG_VALUE,
};

extern "C" __declspec(dllexport) long double PrintNum(bool IsSizeInput);

extern "C" __declspec(dllexport) bool recursionCheck(long double* arr, int start, int end);

extern "C" __declspec(dllexport) void PrintInfo();

extern "C" __declspec(dllexport) bool RestartProgram();

extern "C" __declspec(dllexport) void SizeInput(char* str, int& N);

extern "C" __declspec(dllexport) void RecursionOutput(bool output);

extern "C" __declspec(dllexport) void FillElements(long double* arr, int N);

extern "C" __declspec(dllexport) void TaskSolve();
#endif //DYNAMIC_LIBRARY_H
