#ifndef LABNUMBER5_4TASK_H
#define LABNUMBER5_4TASK_H

#include <iostream>
#include <iomanip>
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
    TOO_BIG_VALUE,
};

long double PrintNum(bool IsSizeInput = false)
{
    while (true) {
        int size = 0;
        long long PointIndex = -1;
        long long buff = 10132;
        long double output = 0;
        bool Sign = true;        // true = +, false = -
        bool WrongSign = false;
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
                if (input[i] == int('-') || input[i] == int('+')) {
                    if (i == 0 && input[i] == int('-')) {
                        Sign = false;
                        input[i] = '0';
                        ++size;
                        continue;
                    } else if(i == 0 && input[i] == int('+'))
                    {
                        if(Sign == false) {
                            throw WRONG_SIGN_POSITION;
                        }
                        Sign = true;
                        input[i] = '0';
                        WrongSign = true;
                        ++size;
                        continue;
                    }
                    else{
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
                if((Sign == false || WrongSign) && size == 1){
                    throw WRONG_SIGN_POSITION;
                }
                for (long long i = PointIndex - 1; i >= 0; --i) {
                    output += (input[i] - '0') * powl(10, PointIndex - i - 1);
                }
                for (long long i = PointIndex + 1; i < size; ++i) {
                    output += (input[i] - '0') * powl(1 / 10.0, i - PointIndex);
                }
            } else {
                if((Sign == false || WrongSign) && size == 1){
                    throw WRONG_SIGN_POSITION;
                }
                for (long long i = size - 1; i >= 0; --i) {
                    output += (input[i] - '0') * powl(10, size - i - 1);
                }
            }
            if (Sign) {
                if (IsSizeInput) {
                    if (output < 1 || output > 10000) {
                        throw INCORRECT_DATA;
                    }
                }
                if (size < 300 || output < 1e300)
                    return output;
                else{
                    throw TOO_BIG_VALUE;
                }
            } else {
                if (IsSizeInput) {
                    if (-output < 1) {
                        throw INCORRECT_DATA;
                    }
                }
                if (size < 300 || output < 1e300)
                    return -output;
                else
                    throw TOO_BIG_VALUE;
            }
        }catch(Exceptions err)
        {
            char *wrongInput = new char[1000];
            char *temp = new char[1];
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
                case(TOO_BIG_VALUE):
                    std::cerr << "The value is too large.\n";
                    std::cerr << "Please, input the number one more time.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                default:
                    break;
            }
            delete[] wrongInput;
        }
    }
}

void nullElements(long double** arr, const int N, const int M)
{
    int count = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(arr[i][j] < 0.0000001 && arr[i][j] > -0.000001){
                ++count;
                std::cout << "Index of NULL: [" << i << "] [" << j <<"].\n";
            }
        }
    }
    std::cout << "Number of NULL elements: " << count << "\n";
}

auto reverseArray(long double** arr, int N, int M){
    auto newArr = new long double*[N];
    for(int i = 0; i < N; ++i){
        newArr[i] = new long double[M];
    }
    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
        {
            newArr[N - 1 - i][M - 1 - j] = arr[i][j];
        }
    }
    return newArr;
}

void showMatrix(long double** matrix, int N, int M)
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << std::setw(10) << matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void PrintInfo()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    std::cout << "FOURTH EXERCISE:\n"
                 "Create two-digit real-type matrix A of size N x K.\n"
                 "Input elements from the keyboard.\n"
                 "Found NULL elements in the matrix. Count them and print their indexes.\n"
                 "Reverse the elements of the matrix and print on the screen.\n"
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
        system("cls");
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

long double** FillMatrix(const long long N, const long long K)
{
    auto** matrix = new long double * [N];
    for(int i = 0; i < N; ++i)
    {
        matrix[i] = new long double [K];
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

void SolveTask()
{
    while(true) {
        int N = 1, M = 1;
        SizeInput("matrix", N, M);
        auto array = FillMatrix(N, M);
        nullElements(array, N, M);
        array = reverseArray(array, N, M);
        showMatrix(array, N, M);
        if(RestartProgram())
            break;
    }
}


#endif //LABNUMBER5_4TASK_H
