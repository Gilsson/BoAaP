//
// Created by Gilsson on 12/14/2022.
//

#include "Implementations.h"
void ToDateType(std::string& str, int num)
{
    while(num > 0)
    {
        str.push_back(num % 10);
        num /= 10;
    }
    std::reverse(str.begin(), str.end());
    for (auto &item: str)
    {
        item += '0';
    }
}
long long PrintNum(bool IsSizeInput = false, int overflow = 0)
{
    while (true) {
        int size = 0;
        long long PointIndex = -1;
        long long buff = 10132;
        long long output = 0;
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
                    if (output < 1 || output > overflow) {
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
                    printf("Ожидался другой тип.\n");
                    printf("Повторите ввод.\n");
                    scanf("%*[\n]", wrongInput);
                    break;
                case (INCORRECT_DATA):
                    printf("Неверный размер.\n");
                    printf("Повторите ввод.\n");
                    scanf("%*[\n]", wrongInput);
                    break;
                case (WRONG_POINT_POSITION):
                    printf("Неверная позиция точки.\n");
                    printf("Повторите ввод.\n");
                    scanf("%*[\n]", wrongInput);
                    break;
                case (WRONG_SIGN_POSITION):
                    printf("Неверная позиция знака.\n");
                    printf("Повторите ввод.\n");
                    scanf("%*[\n]", wrongInput);
                    break;
                case (LETTER_INPUT):
                    printf("Ожидались числа, а не буковы.\n");
                    printf("Повторите ввод.\n");
                    scanf("%*[\n]", wrongInput);
                    break;
                case (EMPTY_STRING):
                    printf("Пустая строка...\n");
                    printf("Повторите ввод.\n");
                    scanf("%*1[\n]", temp);
                    break;
                case (WRONG_SPACE_POSITION):
                    printf("Ввод без пробелов! Ожидалось одно число.\n");
                    printf("Повторите ввод.\n");
                    scanf("%*[\n]", wrongInput);
                    break;
                case(TOO_BIG_VALUE):
                    printf("Слишком большое значение.\n");
                    printf("Повторите ввод.\n");
                    scanf("%*[\n]", wrongInput);
                    break;
                default:
                    break;
            }
            delete[] wrongInput;
        }
    }
}
void ShowOutput(std::istream& file)
{
    std::string str;
    file.seekg(0);
    while(!file.eof()){
        std::getline(file, str);
        std::cout << str << '\n';
    }
}
int CompareDates(Rabotyaga &element1, Rabotyaga &element2){
    int pos1 = element1.date_hiring.find('/');
    std::string temp1;
    for(int i = 0; i < pos1; ++i)
    {
        temp1 += element1.date_hiring[i];
    }
    int pos2 = element2.date_hiring.find('/');
    std::string temp2;
    for(int i = 0; i < pos2; ++i)
    {
        temp2 += element2.date_hiring[i];
    }
    if(temp1 > temp2)
    {
        return 1;
    }else if(temp1 < temp2)
    {
        return -1;
    }else{
        int prev_pos1 = pos1 + 1;
        pos1 = element1.date_hiring.find('/', pos1 + 1);
        std::string temp1;
        for(int i = prev_pos1; i < pos1; ++i)
        {
            temp1 += element1.date_hiring[i];
        }
        int prev_pos2 = pos2 + 1;
        pos2 = element2.date_hiring.find('/', pos2 + 1);
        std::string temp2;
        for(int i = prev_pos2; i < pos2; ++i)
        {
            temp2 += element2.date_hiring[i];
        }
        if(temp1 > temp2)
            return 1;
        else if(temp1 < temp2)
            return -1;
        else{
            prev_pos1 = pos1 + 1;
            pos1 = element1.date_hiring.size();
            std::string temp1;
            for(int i = prev_pos1; i < pos1; ++i)
            {
                temp1 += element1.date_hiring[i];
            }
            prev_pos2 = pos2 + 1;
            pos2 = element2.date_hiring.size();
            std::string temp2;
            for(int i = prev_pos2; i < pos2; ++i)
            {
                temp2 += element2.date_hiring[i];
            }
            if(temp1 > temp2){
                return 1;
            }else if(temp1 < temp2)
                return -1;
            else
                return 0;
        }
    }
}