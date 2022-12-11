//
// Created by Gilsson on 11/27/2022.
//

#ifndef LABNUMBER7_3TASK_H
#define LABNUMBER7_3TASK_H

#include <iostream>
#include "windows.h"

#define BITS 64

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

std::string PrintString() {
    while (true) {
        int size = 0;
        long long PointIndex = -1;
        int SignIndex = -1;
        long long buff = 80;
        char* returned = new char[buff];
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
                    if(input[1] != '\0'){
                        input[i] = '\0';
                        std::string result = input;
                        return result;
                    }
                    else {
                        input[0] = '\0';
                        throw EMPTY_STRING;
                    }
                }
                if (input[i] == int('-') || input[i] == int('+')) {
                    SignIndex = i;
                    size = 1;
                    continue;
                }
                if (input[i] == int(' ')) {
                    throw WRONG_SPACE_POSITION;
                }
                if ((input[i] < int('0') || input[i] > int('9'))
                    && (input[i] < int('a') || input[i] > int('z')) && ((input[i] < int('A') || input[i] > int('Z')))) {
                    throw LETTER_INPUT;
                }
                /*if ((input[i] >= int('a') && input[i] <= int('z')) ||
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
                }*/
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
                    delete[] input;
                    break;
                default:
                    break;
            }

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

            delete[] wrongInput;
        }
    }
}

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
                    if (output < 1 || output > 36) {
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

void resize(std::string & notation1, std::string& notation2)
{
    if(notation1.size() > notation2.size())
    {
        for(int i = notation2.size(); i < notation1.size(); ++i)// O(NK)
        {
            notation2.insert(0, 1, 0);  // O(K)
        }
    }
    else
    {
        for(int i = notation1.size(); i < notation2.size(); ++i)// O(NK)
        {
            notation1.insert(0, 1, 0);  // O(K)
        }
    }
}

void normalize_number(std::string* notation, int sys)
{
    while(notation[0][0] == '0') {// O(N)
        std::string temp = *notation;
        notation[0].resize(notation[0].size() - 1, '0');  // O(K)
        for (int i = 0; i < notation[0].size(); ++i) {  // O(K)
            notation[0][i] = temp[i + 1];
        }
    }
        for(int i = 0; i < notation[0].size(); ++i)  // O(K)
        {
            if(notation[0][i] > int('9'))
            {
                notation[0][i] = int('A') + notation[0][i] - '9' - 1;
            }
        }
}

void digitize(std::string & notation, int sys)
{
    for(auto &i : notation)  // O(K)
    {
        if(i > int('9'))
        {
            i = i - 'A' + 10;
        }else{
            i -= int('0');
        }
    }
}

void ToAdditionalCode(std::string& str, int sys)
{
    digitize(str, sys);
    std::string temp;
    temp.resize(BITS, 0);
    int size = str.size();
    for(int i = BITS - 1, count = size - 1; i >= 0 && count >= 0; --count, --i)// O(N)
    {
        temp[i] = str[count];
    }
    for(auto &i : temp)// O(N)
    {
        i = sys - 1 - i;
    }
    str = temp;
    size = str.size();
    str[size - 1] += 1;
    if(str[size - 1] == sys)
    {
        str[size - 1] = 0;
        str[size - 2] += 1;
        for(int i = size - 2; i >= 0; --i)// O(N)
        {
            if(str[i] >= sys)
            {
                str[i] %= sys;
                str[i - 1] += 1;
            }else{
                break;
            }
        }
    }
}

void ToNormalForm(std::string& notation,int sys)
{
    if(notation[0] == sys - 1)
    {
        for(int i = 1; i < notation.size(); ++i)// O(N)
        {
            notation[i] = sys - 1 - notation[i];
        }
    }
    while(notation[0] == 0)// O(N)
    {
        notation.erase(0, 1);
    }
    while(notation[1] == sys - 1)// O(N)
    {
        notation.erase(1, 1);
    }
    for(auto &i : notation)
    {
        if(i > 9)
        {
            i = 'A' - 10 + i;
        }else{
            i = '0' + i;
        }
    }

    //notation.erase(0, 1);
}

std::string* addition(std::string notation1, std::string notation2, int sys, bool sign)
{
    if(notation2[0] == '-')
    {
        notation2.erase(0, 1);
        ToAdditionalCode(notation2, sys);
    }else{
        digitize(notation2, sys);
    }if(notation1[0] == '-')
    {
        notation1.erase(0, 1);
        ToAdditionalCode(notation1, sys);
    }else{
        digitize(notation1, sys);
    }
    std::string* result = new std::string();
    bool flag = notation1 < notation2;
    bool overflow = 0;
    resize(notation1, notation2);
    int size = notation1.size();
    result->resize(size + 1, 0);
    for(int i = size - 1; i >= 0; --i)// O(N)
    {
        //int temp = result[i + 1];
        int temp = result[0][i + 1];
        result[0][i + 1] = (result[0][i + 1] + notation2[i] + notation1[i]) % (sys);
        //if(i == 0 && (temp + notation1[i] + notation2[i]) / sys > 0)
        //    overflow = true;
        result[0][i] = (temp + notation1[i] + notation2[i]) / sys;

    }
    //result[0][!overflow] = (sys - 1 + result[0][!overflow]) % sys;
    ToNormalForm(result[0], sys);
    //normalize_number(result, sys);
    return result;
}

std::string * substraction(std::string& notation1, std::string& notation2, int sys)
{
    auto result = new std::string();
    resize(notation2, notation1);
    digitize(notation1, sys);
    digitize(notation2, sys);
    bool flag = notation1 > notation2;
    if(!flag)
    {
        std::string temp = notation1;
        notation1 = notation2;
        notation2 = temp;
    }
    int size = notation2.size();
    result->resize(size+1, '0');
    notation1.insert(0, 1, 0);
    notation2.insert(0, 1, 0);
    for(int i = size; i > 0; --i)// O(N)
    {
        if(notation1[i] < notation2[i]){
            result[0][i] += sys - (notation2[i] - notation1[i]);
            notation1[i - 1] -= 1;
        }else{
            result[0][i] += notation1[i] - notation2[i];
        }
    }
    normalize_number(result, sys);
    if(!flag)
        result[0].insert(0, 1, '-');
    return result;
}

void PrintInfo()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    std::cout << "Лабораторная работа номер 7:\n"
                 "Задание 3:\n"
                 "--------------------------------------------------------------------------------------------\n"
                 "\n"
                 "Задание: осуществить сложение и вычитание чисел в заданной системе счисления.\n"
                 "Работу подготовил:\n";
    std::cout << "Гулис Антон\n";
    std::cout << "Чтобы запустить решение, нажмите ";
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
    std::cout << "Чтобы повторить выполнение программы, нажмите ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    std::cout << " Y(y):\n" ;
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

#endif //LABNUMBER7_3TASK_H
