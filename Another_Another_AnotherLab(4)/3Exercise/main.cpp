#include <iostream>

long double PrintNum()
{
    long long output = 0;
    bool Sign = true;                   // true = +, false = -
    while(true) {
        int size = 0;
        bool IsWrongInput = false;
        long long PointIndex = -1;
        char* input = new char[25];
        for (int i = 0; i < 25; ++i) {
            std::cin >> input[i];
            if (input[i] == 45) {
                if (i == 0) {
                    Sign = false;
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
            /*if(PointIndex != -1) {
                for (int j = PointIndex + 1; j <= size; ++j) {
                    if (input[j] != int('0')) {
                        std::cout << "Wrong input!\n";
                        IsWrongInput = true;
                        break;
                    }
                }
            }*/
            if (!IsWrongInput) {
                ++size;
            } else {
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
            }else
            {
                for (int i = size - 1; i >= 0; --i) {
                    output += (input[i] - '0') * powl(10, size - i - 1);
                }

            }
            break;
        }
    }
    return output;
}

int FindMax(int **matrix, size_t N);
int FindMin(int **matrix, size_t N);

int main() {
    while(true) {
        std::cout << "Exercise number 3:\n" << "Made by student of group 253502 Anton Hulis\n"
                  << "Number in the list is 7\n" << "TASK: Input an float matrix N x N and find scalar product of the row with the largest element on the column with the smallest element.\n";
        std::cout << "\n \t Input N(size of matrix).\n";
        int N;
        std::cin >> N;
        int **matrix = new int *[N];
        for (int count = 0; count < N; ++count) {
            matrix[count] = new int[N];
        }
        std::cout << "\n \t \t Input elements of matrix(use Enter to separate each element): \n";
        for (int row = 0; row < N; ++row) {
            for (int column = 0; column < N; ++column) {
                matrix[row][column] = PrintNum();
            }
        }
        std::cout << "\n \t \t Elements of matrix: \n";
        for (int row = 0; row < N; ++row) {
            for (int column = 0; column < N; ++column) {
                std::cout << '\t' << matrix[row][column] << " ";
            }
            std::cout << '\n';
        }
        int MaxRow = FindMax(matrix, N);
        int MinColumn = FindMin(matrix, N);

        std::cout << "\n \t Index of row with the largest element: " << MaxRow << "\n \t Index of column with the smallest element: " << MinColumn << "\n";
        long long Scalar = 0;
        for (int i = 0; i < N; ++i) {
            Scalar += matrix[MaxRow][i] * matrix[i][MinColumn];
        }
        std::cout << "\n \t Scalar product: " << Scalar << '\n';
        for (int row = 0; row < N; ++row) {
            delete[] matrix[row];
            matrix[row] = nullptr;
        }
        matrix = nullptr;
        std::cout << "\n \t \tDo you want to proceed? (if yes, print y, else, print any other symbol\n";
        char Proceed;
        std::cin >> Proceed;
        if(Proceed != 'y')
        {
            break;
        }
        system("cls");
    }
    system("pause");
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