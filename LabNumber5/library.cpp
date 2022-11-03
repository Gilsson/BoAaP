#include "library.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>

long long PrintNum(bool IsSizeInput)
{
    while (true) {
        int size = 0;
        long long PointIndex = -1;
        long long buff = 10132;
        long double output = 0;
        bool Sign = true;                   // true = +, false = -
        char *input = new char[buff]{0};
        scanf("%[^\n]%*c", input);
        try{
            if(strlen(input) == 0) {
                throw EMPTY_STRING;
            }
            for (int i = 0; i < buff; ++i) {
                if (input[i] == 0) {
                    break;
                }
                if (input[i] == int('-')) {
                    if (i == 0) {
                        Sign = false;
                        input[i] = '0';
                        i--;
                        continue;
                    } else {
                        throw WRONG_SIGN_POSITION;
                    }
                }
                if(input[i] == int(' '))
                {
                    throw WRONG_SPACE_POSITION;
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
                if (PointIndex != -1 && IsSizeInput) {
                    for (int j = PointIndex + 1; j <= size; ++j) {
                        if (input[j] != int('0')) {
                            throw WRONG_TYPE_INPUT;
                        }
                    }
                }
                ++size;
            }
            if (PointIndex != -1) {
                if(Sign == false && size == 0){
                    throw WRONG_SIGN_POSITION;
                }
                for (long long i = PointIndex - 1; i >= 0; --i) {
                    output += (input[i] - '0') * powl(10, PointIndex - i - 1);
                }
                for (long long i = PointIndex + 1; i < size; ++i) {
                    output += (input[i] - '0') * powl(1 / 10.0, i - PointIndex);
                }
            } else {
                if(Sign == false && size == 0){
                    throw WRONG_SIGN_POSITION;
                }
                for (long long i = size - 1; i >= 0; --i) {
                    output += (input[i] - '0') * powl(10, size - i - 1);
                }
            }
            if(Sign) {
                if(IsSizeInput) {
                    if (output < 1 || output > 10000) {
                        throw INCORRECT_DATA;
                    }
                }
                if(output < 2e18 || output > -2e18)
                    return output;
            }
            else{
                if(IsSizeInput) {
                    if (-output < 1) {
                        throw INCORRECT_DATA;
                    }
                }
                if(output < 2e18 || output > -2e18)
                    return -output;
            }
        }catch(Exceptions err)
        {
            char *wrongInput = new char[1000];
            char *temp = new char[1];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            switch (err){
                case (WRONG_TYPE_INPUT):
                    std::cerr << "Expected Int type.\n";
                    std::cerr << "Please, input the number one more time.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (INCORRECT_DATA):
                    std::cerr << "Incorrect size.\n";
                    std::cerr << "Please, input the number one more time.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (WRONG_POINT_POSITION):
                    std::cerr << "Incorrect point position.\n";
                    std::cerr << "Please, input the number one more time.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (WRONG_SIGN_POSITION):
                    std::cerr << "Incorrect sign position.\n";
                    std::cerr << "Please, input the number one more time.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (LETTER_INPUT):
                    std::cerr << "Expected number, not letters.\n";
                    std::cerr << "Please, input the number one more time.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (EMPTY_STRING):
                    std::cerr << "Empty string.\n";
                    std::cerr << "Please, input the number one more time.\n";
                    scanf("%*1[\n]", temp);
                    break;
                case (WRONG_SPACE_POSITION):
                    std::cerr << "Expect only 1 number(wrong space position).\n";
                    std::cerr << "Please, input the number one more time.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                default:
                    break;
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

            delete[] wrongInput;
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

void PrintInfo()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    std::cout << "FIRST EXERCISE(number 7 in the list):\n"
                 "Create two 2-digit dynamic array-matrix with size k*k.\n"
                 "Fill array, according to the formula\n"
                 "Was created by: ";
    std::cout << "Anton Gulis\n";
    std::cout << "To start the program, type ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    std::cout << "Enter.\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    while(true) {
        char *temp = new char[1]{0};
        scanf("%[^\n]%*c", temp);
        if(strlen(temp) == 0) {
            char* temp2 = new char[1];
            scanf("%*1[\n]", temp2);
            return;
        }
    }
}

bool RestartProgram(){
    char* temp = new char[1];
    std::cout << "To repeat the program, type Y:\n";
    std::cin >> temp;
    char* temp2 = new char[1];
    scanf("%*1[\n]", temp2);
    if(*temp != 'y' && *temp != 'Y')
    {
        return true;
    }
    return false;
}

void SizeInput(char* str, int& N)
{
    std::cout << "Print size of the " << str << " matrix: \n";
    N = PrintNum(true);
}


void SolveTask()
{
    while(true) {
        std::cout << std::fixed;
        long double **matrixA = nullptr;
        long double **matrixB = nullptr;
        int Size;
        SizeInput("first and second", Size);
        matrixA = FillMatrix(Size, true);
        matrixB = FillMatrix(Size, false);
        showMatrix(matrixA, Size);
        showMatrix(matrixB, Size);
        mainDiagonal(matrixA, Size);
        mainDiagonal(matrixB, Size);
        sideDiagonal(matrixA, Size);
        sideDiagonal(matrixB, Size);
        if (RestartProgram())
            break;
    }
}

