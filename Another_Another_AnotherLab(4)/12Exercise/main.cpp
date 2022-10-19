#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int number;
    std::cin >> number;
    int size;
    if(number > 0)
    {
        size = sqrt(number);
    }
    int** table = new int*[size];
    for(int row = 0; row < size; ++row)
    {
        table[row] = new int[size]{};
    }

    int naturalCount = 2;
    table[0][0] = 1;
    for(int row = 0, column = 1; column < size;)
    {
        table[row][column] = naturalCount;
        naturalCount++;
        for(int i = row + 1, j = column; j >= 0; --j)
        {
            if(j == 0 || table[i][j - 1] == 0) {
                table[i][j] = naturalCount;
                if(table[i][j] == number)
                {
                    std::cout << i << " " << j;
                }
                naturalCount++;
            }else
            {
                do {
                    table[i][j] = naturalCount;
                    if(table[i][j] == number)
                    {
                        std::cout << i << " " << j;
                    }
                    ++i;
                    ++naturalCount;
                }
                while(table[i][j - 1] != 0);
                table[i][j] = naturalCount;
                ++naturalCount;
            }
        }
        column++;
    }
    for(int row = 0; row < size; ++row)
    {
        for(int column = 0; column < size; ++column)
        {
            std::cout << std::setw(5) << table[row][column];
        }
        std::cout << '\n';
    }
    return 0;
}
