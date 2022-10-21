#include <iostream>
#include <iomanip>

long long PrintNum()
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


int main() {
    while(true) {
        std::cout << "Exercise number 2:\n" << "Made by student of group 253502 Anton Hulis\n"
                  << "Number in the list is 7\n"
                  << "TASK: Find out the largest element which lies under the secondary diagonal.\n";
        const int n = 4, k = 5;
        int matrix[n][k]{{1, 0,  2,   3,  -8},
                         {4, 13, 123, 32, 321},
                         {2, 14, 18,  0,  -32},
                         {8, 3,  24,  40, -41}};
        /*for(int row = 0; row < n; ++row)
        {
            for(int column = 0; column < k; ++column)
            {
                std::cin >> matrix[row][column];
            }
        }*/
        std::cout << "\n \t \t Elements of an array:\n";
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < k; ++column) {
                std::cout << std::setw(4) << matrix[row][column] << " ";
            }
            std::cout << std::endl;
        }
        int maxInt = -INT32_MAX;
        std::cout << std::endl;
        for (int row = n - 1; row >= 0; --row) {
            for (int column = n - row; column < k; ++column) {
                if (matrix[row][column] > maxInt) {
                    maxInt = matrix[row][column];
                }
            }
        }
        if (maxInt == -INT32_MAX) {
            std::cout << "The largest element is undefined!\n";
        } else {
            std::cout << "The largest element: " << maxInt;
        }
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
