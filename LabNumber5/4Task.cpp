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
};

long double PrintNum(bool IsSizeInput = false)
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
                if(output < 2e18 || output > -2e18)
                return output;
            }
            else{
                if(IsSizeInput) {
                    if (-output < 2) {
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
                    scanf("%*[\n]", temp);
                    break;
                case (WRONG_SPACE_POSITION):
                    std::cerr << "Expect only 1 number(wrong space position).\n";
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

int nullElements(long double** arr, const int N, const int M)
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
    return count;
}

auto reverseArray(long double** arr, int N, int M){
    auto newArr = new long double*[N];
    for(int i = 0; i < M; ++i){
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

auto FillMatrix(int N, int M)
{
    auto array = new long double *[N];
    for (int i = 0; i < N; ++i)
    {
        array[i] = new long double[M];
    }
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j)
        {
            array[i][j] = PrintNum();
        }
    }
    return array;
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

int main() {

    int N = 1, M = 1;
    N = PrintNum(true);
    M = PrintNum(true);
    auto array = FillMatrix(N, M);
    nullElements(array, N, M);
    array = reverseArray(array, N, M);
    showMatrix(array, N, M);
    return 0;
}