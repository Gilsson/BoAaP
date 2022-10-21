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

long long PrintNum()
{
    long long output = 0;
    bool Sign = true;                   // true = +, false = -
    while(true) {
        int size = 0;
        bool IsWrongInput = false;
        long long PointIndex = -1;
        char* input = new char[25];
        for (int i = 0; i < 25; ++i) {
            std::cin >> input[i];
            if (input[i] == 45) {
                if (i == 0) {
                    Sign = false;
                    continue;
                } else {
                    std::cout << "Wrong Input\n";
                    IsWrongInput = true;
                    break;
                }
            }
            while ((input[i] < int('0') || input[i] > int('9')) && input[i] != int('.')) {
                std::cout << "Wrong Input\n";
                IsWrongInput = true;
                break;
            }
            if (input[i] == int('.')) {
                for (int j = 0; j < i; ++j) {
                    if (input[j] == int('.')) {
                        std::cout << "Wrong Input!\n";
                        IsWrongInput = true;
                    }
                }
            }
            if(PointIndex == -1) {
                for (int j = 0; j <= size; ++j) {
                    if (input[j] == int('.'))
                        PointIndex = j;
                }
            }
            if(PointIndex != -1) {
                for (int j = PointIndex + 1; j <= size; ++j) {
                    if (input[j] != int('0')) {
                        std::cout << "Wrong input!\n";
                        IsWrongInput = true;
                        break;
                    }
                }
            }
            if (!IsWrongInput) {
                ++size;
            } else {
                break;
            }
            if (std::cin.peek() == '\n') {
                break;
            }
        }
        if(IsWrongInput)
        {
            delete[] input;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please, input the number one more time.\n";
        }
        else
        {
            if(PointIndex != -1) {
                for (int i = PointIndex - 1; i >= 0; --i) {
                    output += (input[i] - '0') * powl(10, PointIndex - i - 1);
                }
            }else
            {
                for (int i = size - 1; i >= 0; --i) {
                    output += (input[i] - '0') * powl(10, size - i - 1);
                }

            }
            break;
        }
    }
    return output;
}

int main() {
    while(true) {
        std::cout << "Exercise number 13:\n" << "Made by student of group 253502 Anton Hulis\n"
                  << "Number in the list is 7\n" << "TASK: Construct a magic square.\n";
        std::cout << "\n \tTo construct magic square input his size. It should be more then 2.\n";
        long long size = PrintNum();
        while(size < 3) {
            std::cout << "Input the right size of the square!(>=3)\n";
            size = PrintNum();
        }
        auto magicSquare = (long long **) malloc(size * sizeof(long long *));
        for (int row = 0; row < size; ++row) {
            magicSquare[row] = (long long *) malloc(size * sizeof(long long));
        }
        for (long long rows = 0; rows < size; ++rows) {
            for (long long columns = 0; columns < size; ++columns) {
                magicSquare[rows][columns] = 0;
            }
        }
        long long count = 1;
        if (size % 2 != 0) { // odd
            FillSquare(magicSquare, 0, 0, size, count);
            PrintSquare(magicSquare, size);
        } else if (size % 4 == 2) // even odd
        {
            FillSquare(magicSquare, 0, 0, size / 2, count);
            FillSquare(magicSquare, size / 2, size / 2, size / 2, count);
            FillSquare(magicSquare, 0, size / 2, size / 2, count);
            FillSquare(magicSquare, size / 2, 0, size / 2, count);
            Transparent(magicSquare, size);
            PrintSquare(magicSquare, size);
        } else {
            EvenEvenFill(magicSquare, size);
            PrintSquare(magicSquare, size);
        }
        MagicCheck(magicSquare, size);
        for (long long rows = 0; rows < size; ++rows) {
            free(magicSquare[rows]);
        }
        free(magicSquare);
        std::cout << "\n \t \tDo you want to proceed? (if yes, print y, else, print any other symbol\n";
        char Proceed;
        std::cin >> Proceed;
        if(Proceed != 'y')
        {
            break;
        }
        system("cls");
    }

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
    std::cout << "\n \t It is our magic square of size " << size << '\n';

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
    std::cout << "\n \t Check if our square is magic(both sum of rows and column are equals)\n";
    long long sum = (size * (size * size + 1)) / 2;
    for(long long iterator = 0; iterator < size - 1; ++iterator)
    {
        if(sum != CheckColumn(magicSquare, size, iterator) || sum != CheckRow(magicSquare, size, iterator))
        {
            std::cout << "This square is not magic!" << '\n';
        }
    }
    std::cout << "This square is magic! \n";
    std::cout << "The sum should be: " << sum << "\n";
    std::cout << "The sum is: " << CheckRow(magicSquare,size, 0) << '\n';
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
