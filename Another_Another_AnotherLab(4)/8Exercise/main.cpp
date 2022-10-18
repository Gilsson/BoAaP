#include <iostream>

int** InitializeMatrix(int** matrix, size_t rows, size_t columns);
void PrintMatrix(int** matrix, size_t rows, size_t columns);

int main() {
    int N1, M1;
    std::cin >> N1 >> M1;
    int N2, M2;
    std::cin >> N2 >> M2;
    int** matrix_A = new int*[N1];
    for(int row = 0; row < N1; ++row)
    {
        matrix_A[row] = new int[M1];
    }
    int** matrix_B = new int*[N2];
    for(int row = 0; row < N2; ++row)
    {
        matrix_B[row] = new int[M2];
    }
    matrix_A = InitializeMatrix(matrix_A, N1, M1);
    matrix_B = InitializeMatrix(matrix_B, N2, M2);

    int** multiplication = new int*[N1];
    for(int row = 0; row < N1; ++row)
    {
        multiplication[row] = new int[M2];
    }
    for(int i = 0; i < N1; ++i)
    {
        int sum = 0;
        for(int j = 0; j < M2; ++j)
        {
            for(int k = 0; k < M1; ++k) {
                sum += matrix_A[i][k] * matrix_B[k][j];
            }
            multiplication[i][j] = sum;
            sum = 0;
        }
    }
    PrintMatrix(multiplication, N1, M2);
    return 0;
}

int** InitializeMatrix(int** matrix, size_t rows, size_t columns)
{
    for(int row = 0; row < rows; ++row)
    {
        for(int column = 0; column < columns; ++column)
        {
            std::cin >> matrix[row][column];
        }
    }
    return matrix;
}

void PrintMatrix(int** matrix, size_t rows, size_t columns)
{
    for(int row = 0; row < rows; ++row)
    {
        for(int column = 0; column < columns; ++column)
        {
            std::cout << matrix[row][column] << " ";
        }
        std::cout << '\n';
    }
}