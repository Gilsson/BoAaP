#include <iostream>
#include "dynamicLibrary.h"

int main()
{
    PrintInfo();
    while(true)
    {
    int size = 0;
    SizeInput("array", size);
    auto* arr = new long double[size];
    FillElements(arr, size);
    RecursionOutput(recursionCheck(arr, 0, size - 1));
    if(RestartProgram())
        break;
    }
    system("pause");
    return 0;
}