//
// Created by Gilsson on 11/3/2022.
//

#ifndef LABNUMBER5_3TASK_H
#define LABNUMBER5_3TASK_H


#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <Windows.h>

enum Exceptions
{
    LETTER_INPUT,
    WRONG_TYPE_INPUT,
    WRONG_SIGN_POSITION,
    WRONG_POINT_POSITION,
    INCORRECT_DATA,
    EMPTY_STRING,
    WRONG_SPACE_POSITION,
};

long double PrintNum(bool IsSizeInput) {
    while (true) {
        int size = 0;
        long long PointIndex = -1;
        long long buff = 10132;
        long double output = 0;
        bool Sign = true;                   // true = +, false = -
        char *input = new char[buff]{0};
        scanf("%[^\n]%*c", input);
        try {
            if (strlen(input) == 0) {
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
                        continue;
                    } else {
                        throw WRONG_SIGN_POSITION;
                    }
                }
                if (input[i] == int(' ')) {
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
            if (Sign) {
                if (IsSizeInput) {
                    if (output < 2 || output > 10000) {
                        throw INCORRECT_DATA;
                    }
                }
                if (output < 2e18 || output > -2e18)
                    return output;
            } else {
                if (IsSizeInput) {
                    if (-output < 2) {
                        throw INCORRECT_DATA;
                    }
                }
                if (output < 2e18 || output > -2e18)
                    return -output;
            }
        } catch (Exceptions err) {
            char *wrongInput = new char[1000];
            char *temp = new char[1];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            switch (err) {
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

long long** FillMatrix(const long long N, const long long K)
{
    auto** matrix = new long long * [N];
    for(int i = 0; i < N; ++i)
    {
        matrix[i] = new long long [K];
    }
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < K; ++j)
        {
            std::cout << "Print [" << i << "][" << j << "] element of matrix\n";
            matrix[i][j] = PrintNum(false);
        }
    }
    return matrix;
}


long long *FillVector(long long **matrix, long long &vecSize) {
    try {
        auto *vector = new long long[vecSize];
        int newVecSize = 0;
        if(vecSize <= 0)
            throw vecSize;
        for (int i = 0, vectorCount = 0; i < vecSize; ++i) {
            if (matrix[i][i] != 0 && matrix[i][i] % 2 == 0) {
                vector[vectorCount] = matrix[i][i];
                ++vectorCount;
                newVecSize++;
            }
        }
        if (newVecSize <= 0)
            throw newVecSize;
        auto *newVector = new long long[newVecSize];
        for(int i = 0; i < newVecSize; ++i)
        {
            newVector[i] = vector[i];
        }
        vecSize = newVecSize;
        return newVector;
    }
    catch (int err) {
        std::cout << "Incorrect array size: " << err << '\n';
        std::cout << "Try with another input!\n";
        auto* newVec = new long long[vecSize];
        for(int i = 0; i < vecSize; ++i){
            newVec[i] = 0;
        }
        return newVec;
    }
}


void showVector(long long* vector, size_t vecSize)
{
    std::cout << "Array from the main diagonal:\n";
    long long multiply = 1;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    for(int i = 0; i < vecSize; ++i)
    {
        std::cout << std::setw(4) << vector[i] << " ";
        multiply *= vector[i];
    }
    std::cout << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    std::cout << "Multiply of elements in the array: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    std::cout << multiply;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    std::cout << std::endl;
}

void PrintInfo()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    std::cout << "THIRD EXERCISE:\n"
                 "Create two-digit matrix A of size N x K.\n"
                 "Input elements from the keyboard.\n"
                 "Create dynamic array from the elements, located on the main diagonal of matrix\n"
                 "and that are even. Count the multiply of elements in array.\n"
                 "Was created by: ";
    std::cout << "Anton Gulis\n";
    std::cout << "To start the program, type ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    std::cout << "Enter.\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    while(true)
    {
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
    std::cout << "To repeat the program, type";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    std::cout << " Y:\n" ;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    std::cin >> temp;
    char* temp2 = new char[1];
    scanf("%*1[\n]", temp2);
    if(*temp != 'y' && *temp != 'Y')
    {
        return true;
    }
    return false;
}

void SizeInput(char* str, int& N, int& K)
{
    std::cout << "Size of the " << str << ": ";
    std::cout << "\nPrint the number of row:\n";
    N = PrintNum(true);
    std::cout << "\nPrint the number of columns:\n";
    K = PrintNum(true);
}

void SolveTask(){
    while(true)
    {
        int N = 0, K = 0;
        SizeInput("matrix", N, K);
        long long **matrix = nullptr;
        matrix = FillMatrix(N, K);
        long long vecSize = N <= K ? N : K;
        long long *newVector = nullptr;
        newVector = FillVector(matrix, vecSize);
        showVector(newVector, vecSize);
        if(RestartProgram())
            break;
    }
}
#endif //LABNUMBER5_3TASK_H
