#include <iostream>

int FindMaxElementAbove(int **c_matrix, size_t lower_row, size_t right_column);

int main() {
    int N, M;
    std::cin >> N >> M;
    int** matrix = new int*[N];
    for(int row = 0; row < N; ++row)
    {
        matrix[row] = new int[M];
    }
    for(int row = 0; row < N; ++row)
    {
        for(int column = 0; column < M; ++column)
        {
            std::cin >> matrix[row][column];
        }
    }

    int** B = new int*[N];
    for(int row = 0; row < N; ++row)
    {
        B[row] = new int[M];
    }
    for(int row = 0; row < N; ++row)
    {
        for(int column = 0; column < M; ++column)
        {
            B[row][column] = FindMaxElementAbove(matrix, row, column);
        }
    }

    for(int row = 0; row < N; ++row)
    {
        for(int column = 0; column < M; ++column)
        {
            std::cout << B[row][column] << " ";
        }
        std::cout << '\n';
    }
    for(int row = 0; row < N; ++row)
    {
        delete[] matrix[row];
        delete[] B[row];
        matrix[row] = nullptr;
        B[row] = nullptr;
    }
    return 0;
}

int FindMaxElementAbove(int **c_matrix, size_t lower_row, size_t right_column)
{
    int maxElement = -INT32_MAX;

    for(int row = 0; row <= lower_row; ++row)
    {
        for(int column = 0; column <= right_column; ++column)
        {
            if(maxElement < c_matrix[row][column])
            {
                maxElement = c_matrix[row][column];
            }
        }
    }
    return maxElement;
}