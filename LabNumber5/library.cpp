#include "library.h"
#include <iostream>
#include <iomanip>

long double PrintNum(bool IsSizeInput = false)
{
    while (true) {
        try{
            int size = 0;
            //bool IsWrongInput = false;
            long long PointIndex = -1;
            long long buff = 113200132;
            long long output = 0;
            bool Sign = true;                   // true = +, false = -
            char *input = new char[buff];

            for (int i = 0; i < buff; ++i) {
                std::cin >> input[i];
                if (input[i] == int('-') && Sign) {
                    if (i == 0) {
                        Sign = false;
                        input[i] = 0;
                        i--;
                        continue;
                    } else{
                        throw WRONG_SIGN_POSITION;
                    }
                }
                if ((input[i] < int('0') || input[i] > int('9')) && input[i] != int('.')) {
                    throw LETTER_INPUT;
                }

                if (input[i] == int('.')) {
                    for (int j = 0; j < i; ++j) {
                        if (input[j] == int('.')) {
                            throw WRONG_POINT_POSITION;
                        }
                    }
                }
                if (PointIndex == -1) {
                    for (int j = 0; j <= size; ++j) {
                        if (input[j] == int('.'))
                            PointIndex = j;
                    }
                }
                /*if (PointIndex != -1) {
                    for (int j = PointIndex + 1; j <= size; ++j) {
                        if (input[j] != int('0')) {
                            throw WRONG_TYPE_INPUT;
                        }
                    }
                }*/
                ++size;
                if (std::cin.peek() == ' ') {
                    break;
                }
                if (std::cin.peek() == '\n') {
                    break;
                }
            }
            if (PointIndex != -1) {
                for (long long i = PointIndex - 1; i >= 0; --i) {
                    output += (input[i] - '0') * powl(10, PointIndex - i - 1);
                }
                for (long long i = PointIndex + 1; i < size; ++i) {
                    output += (input[i] - '0') * powl(1 / 10.0, i - PointIndex);
                }
            } else {
                for (long long i = size - 1; i >= 0; --i) {
                    output += (input[i] - '0') * powl(10, size - i - 1);
                }
            }
            if(Sign) {
                if(IsSizeInput) {
                    if (output < 2 || output > 10000) {
                        throw INCORRECT_DATA;
                    }
                }
                return output;
            }
            else{
                if(IsSizeInput) {
                    if (-output < 2) {
                        throw INCORRECT_DATA;
                    }
                }
                return -output;
            }
        }catch(Exceptions err)
        {
            char* wrongInput = new char[1000];
            for(int i = 0; std::cin.peek() != '\n'; ++i)
            {
                std::cin >> wrongInput[i];
            }
            switch (err) {
                case (WRONG_TYPE_INPUT): {
                    std::cout << "Expected Int type.\n";
                    break;
                }
                case (INCORRECT_DATA): {
                    std::cout << "Incorrect size.\n";
                    break;
                }
                case (WRONG_POINT_POSITION): {
                    std::cout << "Incorrect point position.\n";
                    break;
                }
                case (WRONG_SIGN_POSITION):
                {
                    std::cout << "Incorrect sign position.\n";
                    break;
                }
                case (LETTER_INPUT):
                {
                    std::cout << "Expected number, not letters.\n";
                    break;
                }
                default:
                    break;
            }
            std::cout << "Please, input the number one more time.\n";
        }
    }
}

long double** FillMatrix( long long N, bool bParam = true)
{
    auto** matrix = new long double * [N];
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
