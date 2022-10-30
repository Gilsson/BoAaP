#include <iostream>
#include "dynamicLibrary.h"

int main()
{
    long long size = 0;
    size = PrintNum(true);
    auto* arr = new double[size];
    for(long long i = 0; i < size; ++i)
    {
        arr[i] = PrintNum(false);
    }
    std::cout << recursionCheck(arr, 0, size - 1);
}