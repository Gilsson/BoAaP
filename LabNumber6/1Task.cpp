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

char* PrintString(char* output) {
    while (true) {
        int size = 0;
        long long PointIndex = -1;
        int SignIndex = -1;
        int StartIndex = -1;                // The start of the fixed-point number
        long long buff = 80;
        int point_count = 0;
        int returned_size = 0;
        int returned_last_element = 0;
        char* returned = new char[buff];
        //char *output = new char[buff];
        bool WrongSign = false;
        bool Sign = true;                   // true = +, false = -
        char *input = new char[buff]{0};
        try {
            /*if (strlen(input) == 0) {
                throw EMPTY_STRING;
            }*/
            for (int i = 0; i < buff; ++i) {
                input[i] = getchar();
                if (i == 79 && input[i] != '\n') {
                    throw TOO_BIG_VALUE;
                }
                if (input[i] == '\n') {
                    if (SignIndex != -1 && StartIndex != -1 && StartIndex < PointIndex) {
                        for (int j = 0; j < size; ++j) {
                            output[j] = input[SignIndex + j];
                            returned[returned_last_element] = output[j];
                            ++returned_last_element;
                        }
                    } else if (StartIndex != -1 && StartIndex < PointIndex) {
                        for (int j = 0; j < size; ++j) {
                            output[j] = input[StartIndex + j];
                            returned[returned_last_element] = output[j];
                            ++returned_last_element;
                        }
                    } else if (StartIndex != -1) {
                        /*for (int j = 0; j < size; ++j) {
                            output[j] = input[StartIndex + j];
                            returned[returned_last_element] = output[j];
                            ++returned_last_element;
                        }*/
                        returned_size -= size;
                    }
                    returned[returned_last_element] = int(' ');
                    ++returned_last_element;
                    ++returned_size;
                    output[size] = '\0';
                    returned[returned_size] = '\0';
                    if (returned_size != 0)
                        return returned;
                    else {
                        output[0] = '\0';
                        throw EMPTY_STRING;
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
                    ++returned_size;
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
                        throw WRONG_POINT_POSITION;
                    } else if (StartIndex != -1) {
                        ++size;
                        ++returned_size;
                        PointIndex = i;
                    } else {
                        ++size;
                        ++returned_size;
                        continue;
                    }
                    ++point_count;
                }
                if ((input[i] < int('0') || input[i] > int('9')) && input[i] != int('.') && input[i] != int(',')
                    && (input[i] < int('a') || input[i] > int('z')) && ((input[i] < int('A') || input[i] > int('Z')))) {
                    throw LETTER_INPUT;
                }
                if ((input[i] >= int('a') && input[i] <= int('z')) ||
                    ((input[i] >= int('A') && input[i] <= int('Z')))) {
                    if (SignIndex != -1 && StartIndex != -1 && StartIndex < PointIndex) {
                        for (int j = 0; j < size; ++j) {
                            output[j] = input[SignIndex + j];
                            returned[returned_last_element] = output[j];
                            ++returned_last_element;
                        }
                        returned[returned_last_element] = int(' ');
                        ++returned_last_element;
                        ++returned_size;
                    } else if (StartIndex != -1 && StartIndex < PointIndex) {
                        for (int j = 0; j < size; ++j) {
                            output[j] = input[StartIndex + j];
                            returned[returned_last_element] = output[j];
                            ++returned_last_element;
                        }
                        returned[returned_last_element] = int(' ');
                        ++returned_last_element;
                        ++returned_size;
                    }else{
                        returned_size -= size;
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
                    scanf("%*[\n]", wrongInput);
                    break;
                case (INCORRECT_DATA):
                    std::cerr << "Incorrect size.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (WRONG_POINT_POSITION):
                    std::cerr << "Incorrect point position.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (WRONG_SIGN_POSITION):
                    std::cerr << "Incorrect sign position.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (LETTER_INPUT):
                    std::cerr << "Not expected symbol was founded.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (EMPTY_STRING):
                    std::cerr << "Empty string.\n";
                    std::cerr << "Please, input the number one more time.\n";
                    scanf("%*1[\n]", temp);
                    break;
                case (WRONG_SPACE_POSITION):
                    std::cerr << "Expect only 1 number(wrong space position).\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (TOO_BIG_VALUE):
                    std::cerr << "The stroke is to large.\n";
                    scanf("%*[\n]", wrongInput);
                    delete[] output;
                    break;
                default:
                    break;
            }

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

            delete[] wrongInput;
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


int main() {
    while(true) {
        std::cout << "Exercise number 1:\n" << "Made by student of group 253502 Anton Hulis\n"
                  << "Number in the list is 7\n" << "TASK: find a fixed-point value in string\n";
        char* output = new char[80];
        std::cout << PrintString(output) << "\n";
        if(RestartProgram())
        {
            break;
        }
    }
    return 0;
}
