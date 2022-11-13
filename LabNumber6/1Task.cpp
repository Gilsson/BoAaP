#include <iostream>
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
    TOO_BIG_VALUE,
};

char* PrintString(bool IsSizeInput) {
    while (true) {
        int size = 0;
        long long PointIndex = -1;
        int SignIndex = -1;
        int StartIndex = -1;                // The start of the fixed-point number
        long long buff = 80;
        char *output = new char[buff];
        bool WrongSign = false;
        bool Sign = true;                   // true = +, false = -
        char *input = new char[buff]{0};
        try {
            /*if (strlen(input) == 0) {
                throw EMPTY_STRING;
            }*/
            for (int i = 0; i < buff; ++i) {
                input[i] = getchar();
                if (input[i] == '\\') {
                    char temp = getchar();
                    if (temp != int('0'))
                        throw WRONG_SIGN_POSITION;
                    else {
                        return output;
                        break;
                    }
                }
                if (input[i] == int('-') || input[i] == int('+')) {
                    SignIndex = i;
                    size = 1;
                    continue;
                }
                if (input[i] >= int('0') && input[i] <= int('9')) {
                    if (StartIndex == -1) {
                        StartIndex = i;
                    }
                    ++size;
                }
                /*if(input[i] == int('0'))
                {
                    if(StartIndex != -1)
                    for(int i = 0; i < size; ++i)
                    {
                        if()
                    }
                }*/
                if (input[i] == int(' ')) {
                    throw WRONG_SPACE_POSITION;
                }
                if (input[i] == int('.') || input[i] == int(',')) {
                    if (PointIndex != -1) {

                    } else if (StartIndex != -1) {
                        ++size;
                        PointIndex = i;
                    } else {
                        ++size;
                        continue;
                    }
                }
                if ((input[i] < int('0') || input[i] > int('9')) && input[i] != int('.') && input[i] != int(',')
                    && (input[i] < int('a') || input[i] > int('z')) && ((input[i] < int('A') || input[i] > int('Z')))) {
                    throw LETTER_INPUT;
                }
                if ((input[i] >= int('a') && input[i] <= int('z')) ||
                    ((input[i] >= int('A') && input[i] <= int('Z')))) {
                    if (SignIndex != -1 && StartIndex != -1 && StartIndex < PointIndex) {
                        for (int j = 0; i < size; ++i) {
                            output[j] = input[SignIndex + j];
                        }
                    } else if (StartIndex != -1 && StartIndex < PointIndex) {
                        for (int j = 0; i < size; ++i) {
                            output[j] = input[StartIndex + j];
                        }
                    }
                    SignIndex = -1;
                    StartIndex = -1;
                    PointIndex = -1;
                    size = 0;
                }
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
                    std::cerr << "Not expected symbol was founded.\n";
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
                case (TOO_BIG_VALUE):
                    std::cerr << "The value is too large.\n";
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



int main() {

    PrintString(true);
    return 0;
}
