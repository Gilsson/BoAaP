#include <iostream>

int main() {
    long long rows, columns, count = 0;
    std::cin >> rows >> columns;
    int** arr = new int* [rows + 2];
    for(long long i = 0; i < rows + 2; ++i)
    {
        arr[i] = new int[columns + 2]{};
    }


    for(int row = 0; row < rows + 2; ++row)
    {
        for(int column = 0; column < columns + 2; ++column)
        {
            arr[row][column] = INT32_MAX;
        }
    }

    for(int row = 1; row < rows + 1; ++row)
    {
        for(int column = 1; column < columns + 1; ++column)
        {
            std::cin >> arr[row][column];
        }
        std::cout << '\n';
    }

    for(int row = 1; row < rows + 1; ++row)
    {
        for(int column = 1; column < columns + 1; ++column)
        {
            std::cout << arr[row][column] << " ";
        }
        std::cout << '\n';
    }

    int MinNum = 0;

    for(long long i = 1; i < rows ; ++i)
    {
        for(long long j = 1; j < columns; j++)
        {
            if(arr[i][j] < arr[i + 1][j] && arr[i][j] < arr[i][j + 1] && arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i][j - 1])
            {
                ++count;
            }
        }
    }
    std::cout << count;
    for(int row = 0; row < rows + 2; row++)
    {
        delete[] arr[row];
        arr[row] = nullptr;
    }
    return 0;
}
