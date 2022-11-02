#include <iostream>
#include <cmath>
#include "library.h"

int main() {
    PrintInfo();
    while(true) {
        std::cout << std::fixed;
        long double **matrixA = nullptr;
        long double **matrixB = nullptr;
        int Size;
        SizeInput("first and second", Size);
        matrixA = FillMatrix(Size, true);
        matrixB = FillMatrix(Size, false);
        showMatrix(matrixA, Size);
        showMatrix(matrixB, Size);
        mainDiagonal(matrixA, Size);
        mainDiagonal(matrixB, Size);
        sideDiagonal(matrixA, Size);
        sideDiagonal(matrixB, Size);
        if(RestartProgram())
            break;
    }
    system("pause");
    return 0;
}
