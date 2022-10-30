#include <iostream>
#include <cmath>
#include <limits>

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

int main() {
    while(true) {
        std::cout << "Exercise number 9:\n" << "Made by student of group 253502 Anton Hulis\n"
                  << "Number in the list is 7\n" << "TASK: We have 3-digit array of int. Define the largest(biggest sum of elements) diagonal the array\n";
        std::cout << "\n \t N is the size of our array. Input N.\n";
        int n;
        n = PrintNum();
        int ***cube = nullptr;
        cube = (int ***) malloc(n * sizeof(int **));
        for (int row = 0; row < n; ++row) {
            cube[row] = (int **) malloc(n * sizeof(int *));
            for (int column = 0; column < n; ++column) {
                cube[row][column] = (int *) malloc(n * sizeof(int));
            }
        }
        std::cout << "\n \t \t Print the elements of the array (use Enter to separate each number). \n";
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                for (int layer = 0; layer < n; ++layer) {
                    cube[row][column][layer] = PrintNum();
                }
            }
        }
        std::cout << "\n \t \t Elements of the array:  \n";
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                for (int layer = 0; layer < n; ++layer) {
                    std::cout<<"array["<<row<<"]["<<column<<"]["<<layer<<"] = "<<cube[row][column][layer]<<"\n";
                }
            }
        }
        int diag_num = 0;
        int diag_sum = 0;
        int max_diag_sum = 0;
        int max_diag_num = 0;
        for (int elem = 0; elem < n; ++elem) {
            diag_sum += cube[elem][elem][elem];
            diag_num = 1;                               // from (0,0,0) to (n-1, n-1, n-1)
        }
        if (diag_sum >= max_diag_sum) {
            max_diag_sum = diag_sum;
            max_diag_num = diag_num;
        }
        diag_sum = 0;
        diag_num = 0;
        for (int elem = n - 1; elem >= 0; --elem) {
            diag_sum += cube[elem][elem][n - 1 - elem];
            diag_num = 2;                             // from (n-1, n-1, 0) to (0, 0, n - 1)
        }
        if (diag_sum >= max_diag_sum) {
            max_diag_sum = diag_sum;
            max_diag_num = diag_num;
        }
        diag_sum = 0;
        diag_num = 0;
        for (int elem = n - 1; elem >= 0; --elem) {
            diag_sum += cube[elem][n - 1 - elem][n - 1 - elem];
            diag_num = 3;                             // from (n-1, 0, 0) to (0, n - 1, n - 1)
        }
        if (diag_sum >= max_diag_sum) {
            max_diag_sum = diag_sum;
            max_diag_num = diag_num;
        }
        diag_sum = 0;
        diag_num = 0;
        for (int elem = n - 1; elem >= 0; --elem) {
            diag_sum += cube[n - 1 - elem][elem][n - 1 - elem];
            diag_num = 4;                             // from (0, n-1, 0) to (n - 1, 0, n - 1)
        }
        if (diag_sum >= max_diag_sum) {
            max_diag_sum = diag_sum;
            max_diag_num = diag_num;
        }
        switch (max_diag_num) {
            case 1:
                std::cout << "\n \t The largest diagonal number is: ";
                std::cout << max_diag_num << '\n';
                std::cout << "\n \t Elements of this diagonal: \n";
                for (int elem = 0; elem < n - 1; ++elem) {
                    std::cout << cube[elem][elem][elem] << " ";
                }
                break;
            case 2:
                std::cout << "\n \t The largest diagonal number is: ";
                std::cout << max_diag_num << '\n';
                std::cout << "\n \t Elements of this diagonal: \n";
                for (int elem = n - 1; elem >= 0; --elem) {
                    std::cout << cube[elem][elem][n - 1 - elem] << " ";
                }
                break;
            case 3:
                std::cout << "\n \t The largest diagonal number is: ";
                std::cout << max_diag_num << '\n';
                std::cout << "\n \t Elements of this diagonal: \n";
                for (int elem = n - 1; elem >= 0; --elem) {
                    std::cout << cube[elem][n - 1 - elem][n - 1 - elem] << " ";
                }
                break;
            case 4:
                std::cout << "\n \t The largest diagonal number is: ";
                std::cout << max_diag_num << '\n';
                std::cout << "\n \t Elements of this diagonal: \n";
                for (int elem = n - 1; elem >= 0; --elem) {
                    std::cout << cube[n - 1 - elem][elem][n - 1 - elem] << " ";
                }
                break;
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
