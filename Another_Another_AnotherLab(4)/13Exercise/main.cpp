#include <iostream>
#include <iomanip>
#include "malloc.h"

void FillSquare(long long** magicSquare,  long long row, long long column, long long size, long long& count);

void PrintSquare(long long **magicSquare, long long size);

void Transparent(long long** magicSquare, long long size);

void MagicCheck(long long** magicSquare,  long long size);

long long CheckColumn(long long** magicSquare, long long size, long long index);

long long CheckRow(long long** magicSquare, long long size, long long index);

void EvenEvenFill(long long** magicSquare, long long size);

int main() {
    long long size;
    std::cin >> size;
    auto magicSquare = (long long**) malloc(size * sizeof(long long*));
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
    long long count = 1;
    if(size % 2 != 0) { // odd
        FillSquare(magicSquare, 0, 0, size, count);
        PrintSquare(magicSquare, size);
    }else if(size % 4 == 2) // even odd
    {
        FillSquare(magicSquare, 0, 0, size / 2,  count);
        FillSquare(magicSquare, size / 2, size / 2, size / 2, count);
        FillSquare(magicSquare, 0, size / 2, size / 2, count);
        FillSquare(magicSquare, size / 2, 0, size / 2, count);
        Transparent(magicSquare, size);
        PrintSquare(magicSquare, size);
    }
    else{
        EvenEvenFill(magicSquare, size);
        PrintSquare(magicSquare, size);
    }
    MagicCheck(magicSquare, size);
    for(long long rows = 0; rows < size; ++rows)
    {
        free(magicSquare[rows]);
    }
    free(magicSquare);
    system("pause");
    return 0;
}

void FillSquare(long long** magicSquare, long long row, long long column, long long size, long long& count) {
    if(size % 4 == 2)
    {
        long long square = 1;
        row = 0, column = size / 2;
            magicSquare[row][column] = count;
            ++count;
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
    if (size % 2 != 0) {
        long long new_row = 0, new_column = size / 2;
        magicSquare[row + new_row][column + new_column] = count;
        ++count;
        for(long long i = 1; i < size * size; ++i){
            if (new_row == 0 && new_column == size - 1) {
                new_row++;
            } else if (new_row == 0) {
                new_row = size - 1;
                new_column++;
            } else if (new_column == size - 1) {
                new_column = 0;
                new_row--;
            } else {
                new_row--;
                new_column++;
            }
            if (magicSquare[row + new_row][column + new_column] == 0) {
                magicSquare[row + new_row][column + new_column] = count;
                ++count;
            } else {
                new_row += 2, new_column -= 1;
                magicSquare[new_row + row][new_column + column] = count;
                ++count;
            }
        }
    }
}
void PrintSquare(long long **magicSquare, long long size)
{

    for(long long rows = 0; rows < size; ++rows)
    {
        for(long long columns = 0; columns < size; ++columns)
        {
            std::cout << std::setw(4) << magicSquare[rows][columns] << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void Transparent(long long** magicSquare, long long size)
{
    if(size > 6)
    {
        long long column = size / 2 - 3;
        long long new_column = size / 2 - column / 2;
        while (new_column < size / 2 + column / 2) {
            for (long long iterator = 0; iterator < size / 2; ++iterator) {
                long long temp = magicSquare[iterator][new_column];
                magicSquare[iterator][new_column] = magicSquare[iterator + size / 2][new_column];
                magicSquare[iterator + size / 2][new_column] = temp;
            }
            new_column++;
        }
        for(long long iterator = 1; iterator < size / 2 - 1; ++iterator)
        {
            long long temp = magicSquare[iterator][1];
            magicSquare[iterator][1] = magicSquare[iterator + size / 2][1];
            magicSquare[iterator + size / 2][1] = temp;
        }
        long long temp = magicSquare[0][0];
        magicSquare[0][0] = magicSquare[size / 2][0];
        magicSquare[size / 2][0] = temp;
        temp = magicSquare[size / 2 - 1][0];
        magicSquare[size / 2 - 1][0] = magicSquare[size - 1][0];
        magicSquare[size - 1][0] = temp;
    }
}

void MagicCheck(long long** magicSquare, long long size)
{
    long long sum = (size * (size * size + 1)) / 2;
    for(long long iterator = 0; iterator < size - 1; ++iterator)
    {
        if(sum != CheckColumn(magicSquare, size, iterator) || sum != CheckRow(magicSquare, size, iterator))
        {
            std::cout << "This square is not magic!" << '\n';
        }
    }
    std::cout << "This square is magic! \n";
}
long long CheckColumn(long long** magicSquare, long long size, long long index)
{
    unsigned long long sum = 0;
    for(long long row = 0; row < size; ++row)
    {
        sum += magicSquare[row][index];
    }
    return sum;
}

long long CheckRow(long long** magicSquare, long long size, long long index)
{
    unsigned long long sum = 0;
    for(long long column = 0; column < size; ++column)
    {
        sum += magicSquare[index][column];
    }
    return sum;
}

void EvenEvenFill(long long** magicSquare, long long size)
{
    long long count = 1;
    for(long long row = 0; row < size; ++row)
    {
        for(long long column = 0; column < size; ++column)
        {
            if((row + 1) % 4 == 1 || (row + 1) % 4 == 0) {
                if ((column + 1) % 4 == 2) {
                    magicSquare[row][column] = size * size - count + 1;
                    magicSquare[row][++column] = size * size - ++count + 1;
                } else {
                    magicSquare[row][column] = count;
                }
            }
            else{

                if ((column + 1) % 4 == 2) {
                    magicSquare[row][column] = count;
                    magicSquare[row][++column] = ++count;
                } else {
                    magicSquare[row][column] = size * size - count + 1;
                }
            }
            ++count;
        }
    }
}
