#include <iostream>
#include <iomanip>
#include "malloc.h"

int main() {
    long long size;
    std::cin >> size;
    long long** magicSquare = (long long**) malloc(size * sizeof(long long*));
    for(int row = 0; row < size; ++row)
    {
        magicSquare[row] = (long long*) malloc(size * sizeof(long long));
    }
    for(long long rows = 0; rows < size; ++rows)
    {
        for(long long columns = 0; columns < size; ++columns)
        {
            magicSquare[rows][columns] = 0;
        }
    }
    if(size % 2 != 0) {
        long long count = 2, row = 0, column = size / 2;
        magicSquare[row][column] = 1;
        while (count <= size * size) {
            if (row == 0 && column == size - 1) {
                row++;
            } else if (row == 0) {
                row = size - 1;
                column++;
            } else if (column == size - 1) {
                column = 0;
                row--;
            } else {
                row--;
                column++;
            }
            if (magicSquare[row][column] == 0) {
                magicSquare[row][column] = count;
                ++count;
            } else {
                magicSquare[row += 2][column -= 1] = count;
                ++count;
            }

        }
    }
    for(long long rows = 0; rows < size; ++rows)
    {
        for(long long columns = 0; columns < size; ++columns)
        {
            std::cout << std::setw(4) << magicSquare[rows][columns] << " ";
        }
        std::cout << '\n';
    }
    for(long long rows = 0; rows < size; ++rows)
    {
        free(magicSquare[rows]);
    }
    free(magicSquare);
    system("pause");
    return 0;
}
