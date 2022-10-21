#include <iostream>

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
        std::cout << "Exercise number 1:\n" << "Made by student of group 253502 Anton Hulis\n"
                  << "Number in the list is 7\n" << "TASK: Move an elements of an array on the N positions to right.\n";
        const int k = 5;
        int array[k]{};

        std::cout << "\n \t Type a " << k << " elements of array.(use Enter to separate each element) \n";
        for (int count = 0; count < k; ++count) {
            array[count] = PrintNum();
        }
        int n = 6;

        std::cout << "\n \t Array have " << k << " elements, which are: \n";
        for (int count = 0; count < k; ++count) {
            std::cout << array[count] << " ";
        }
        std::cout << '\n';
        for (int i = 0; i < n; ++i) {
            int tempInt = 0;
            tempInt = array[k - 1];
            for (int count = k - 1; count > 0; --count) {
                array[(count) % k] = array[(count - 1) % k];
            }
            array[0] = tempInt;
        }
        std::cout << "\n \t Array after moving on " << n << " elements to right: \n";
        for (int count = 0; count < k; ++count) {
            std::cout << array[count] << " ";
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
    return 0;
}
