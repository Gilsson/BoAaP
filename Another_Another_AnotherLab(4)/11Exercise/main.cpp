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
        std::cout << "Exercise number 11:\n" << "Made by student of group 253502 Anton Hulis\n"
                  << "Number in the list is 7\n" << "TASK: Fill the field of the sapper game.\n";
        std::cout << "\n \t(Use Enter to separate each number)To construct field input his size. Int N and M.\n";
        int N = PrintNum(), M = PrintNum();
        char **field = new char *[N + 2];
        for (int row = 0; row < N + 2; ++row) {
            field[row] = new char[M + 2];
        }
        for (int row = 0; row < N + 2; ++row) {
            for (int column = 0; column < M + 2; ++column) {
                field[row][column] = '.';
            }
        }

        std::cout << "\n \t \t Now input the field. * is a bomb and . is an empty square.\n";
        for (int row = 1; row <= N; ++row) {
            for (int column = 1; column <= M; ++column) {
                std::cin >> field[row][column];
                while(field[row][column] != '*' && field[row][column] != '.')
                {
                    std::cout << "\t Wrong input! * is a bomb and . is an empty square.\n";
                    std::cin >> field[row][column];
                }
            }
        }
        std::cout << "\t Our field: \n";
        for (int row = 1; row <= N; ++row) {
            for (int column = 1; column <= M; ++column) {
                std::cout << field[row][column] << " ";
            }
            std::cout << "\n";
        }
        for (int row = 1; row <= N; ++row) {
            int numOfBombsAround = 0;
            for (int column = 1; column <= M; ++column) {
                if (field[row][column] != '*') {
                    for (int k = row - 1; k <= row + 1; ++k) {
                        for (int j = column - 1; j <= column + 1; ++j) {
                            if (field[k][j] == '*') {
                                numOfBombsAround++;
                            }
                        }
                    }
                    field[row][column] = '0' + numOfBombsAround;
                }
                numOfBombsAround = 0;
            }

        }
        std::cout << "\n \t \t Sapper game field, which is filling with the number of near standing bombs : \n";
        for (int row = 1; row <= N; ++row) {
            for (int column = 1; column <= M; ++column) {
                std::cout << field[row][column] << " ";
            }
            std::cout << "\n";
        }
        for (int row = 0; row < N + 2; ++row) {
            delete[] field[row];
            field[row] = nullptr;
        }
        std::cout << "\n \t \tDo you want to proceed? (if yes, print y, else, print any other symbol\n";
        char Proceed;
        std::cin >> Proceed;
        if(Proceed != 'y')
        {
            break;
        }
        system("cls");
        system("sls");
    }
    system("pause");
    return 0;
}
