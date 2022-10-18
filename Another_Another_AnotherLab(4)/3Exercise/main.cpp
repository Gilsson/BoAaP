#include <iostream>

int FindMax(int **matrix, size_t N);
int FindMin(int **matrix, size_t N);

int main() {
    int N;
    std::cin >> N;
    int** matrix = new int*[N];
    for(int count = 0; count < N; ++count)
    {
        matrix[count] = new int[N];
    }
    for(int row = 0; row < N; ++row)
    {
        for(int column = 0; column < N; ++column)
        {
            std::cin >> matrix[row][column];
        }
    }
    for(int row = 0; row < N; ++row)
    {
        for(int column = 0; column < N; ++column)
        {
            std::cout << matrix[row][column] << " ";
        }
        std::cout << '\n';
    }
    int MaxRow = FindMax(matrix, N);
    int MinColumn = FindMin(matrix, N);

    long Scalar = 0;
    for(int i = 0; i < N; ++i)
    {
        Scalar += matrix[MaxRow][i] * matrix[i][MinColumn];
    }
    std::cout << "Scalar: " << Scalar;
    for(int row = 0; row < N; ++row)
    {
        delete[] matrix[row];
        matrix[row] = nullptr;
    }
    matrix = nullptr;
    return 0;
}

int FindMax(int **matrix, size_t N)
{
    int MaxElement = -INT32_MAX;
    int Index = 0;
    for(int row = 0; row < N; ++row)
    {
        for(int column = 0; column < N; ++column)
        {
            if(matrix[row][column] > MaxElement)
            {
                MaxElement = matrix[row][column];
                Index = row;
            }
        }
    }
    return Index;
}

int FindMin(int** matrix, size_t N)
{
    int MinElement = INT32_MAX;
    int Index = 0;
    for(int row = 0; row < N; ++row)
    {
        for(int column = 0; column < N; ++column)
        {
            if(matrix[row][column] < MinElement)
            {
                MinElement= matrix[row][column];
                Index = row;
            }
        }
    }
    return Index;
}