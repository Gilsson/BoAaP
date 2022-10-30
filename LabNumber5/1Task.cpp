#include <iostream>
#include <cmath>
#include "library.h"

int main() {
    std::cout << std::fixed;
    long double** matrixA = nullptr;
    long double** matrixB = nullptr;

    size_t Size = PrintNum();
    matrixA = FillMatrix(Size, true);
    matrixB = FillMatrix( Size, false);
    showMatrix(matrixA, Size);
    showMatrix(matrixB, Size);
    mainDiagonal(matrixA, Size);
    mainDiagonal(matrixB, Size);
    sideDiagonal(matrixA, Size);
    sideDiagonal(matrixB, Size);
    system("pause");
    return 0;
}
