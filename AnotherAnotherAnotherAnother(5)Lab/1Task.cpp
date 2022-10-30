#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

long double PrintNum()
{
    long long output = 0;
    bool Sign = true;                   // true = +, false = -
    while(true) {
        int size = 0;
        bool IsWrongInput = false;
        long long PointIndex = -1;
        long long buff = 113200132;
        char* input = new char[buff];
        for (int i = 0; i < buff; ++i) {
            std::cin >> input[i];
            if (input[i] == int('-')) {
                if (i == 0) {
                    Sign = false;
                    input[i] = 0;
                    i--;
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
            if(std::cin.peek() == ' ')
            {
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
                for(int i = PointIndex + 1; i < size; ++i)
                {
                    output += (input[i] - '0') * powl(1 / 10.0, i - PointIndex);
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
    if(Sign)
        return output;
    else{
        return -output;
    }
}

long double** FillMatrix( size_t N, bool bParam = true)
{
    long double** matrix = new long double * [N];
    for(int i = 0; i < N; ++i)
    {
        matrix[i] = new long double [N];
    }
    if(bParam) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                matrix[i][j] = (powl(i, 2) + powl(j, 2)) / (i + j + 1);
            }
        }
    }
    else{
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if(j <= 8)
                    matrix[i][j] = (powl(i, 2) + powl(j, 2));
                else if(j > 8)
                    matrix[i][j] = (powl(i, 2) + powl(j, 2)) / 2.0;
            }
        }
    }
    return matrix;
}

void mainDiagonal(long double** matrix, size_t N) {
    long double sum = 0;
    for (long long i = 0; i < N; ++i) {
        sum += matrix[i][i];
    }
    std::cout << "Main diagonal: " << sum << '\n';
}

void sideDiagonal(long double** matrix, size_t N)
{
    long double sum = 0;
    for(long long i = N - 1; i >= 0; --i)
    {
        sum += matrix[i][i];
    }
    std::cout << "Side diagonal: " << sum << '\n';
}

void showMatrix(long double** matrix, size_t N)
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(10) << matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

int main() {
    std::cout << std::fixed;
    long double** matrixA = nullptr;
    long double** matrixB = nullptr;
    size_t Size = PrintNum();
    matrixA = FillMatrix(Size);
    matrixB = FillMatrix( Size, false);
    showMatrix(matrixA, Size);
    showMatrix(matrixB, Size);
    mainDiagonal(matrixA, Size);
    mainDiagonal(matrixB, Size);
    sideDiagonal(matrixA, Size);
    sideDiagonal(matrixB, Size);
    return 0;
}
