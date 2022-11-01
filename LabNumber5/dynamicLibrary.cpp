#include "dynamicLibrary.h"

#include <iostream>

long double PrintNum(bool IsSizeInput = false)
{
    while (true) {
        try{
            int size = 0;
            //bool IsWrongInput = false;
            long long PointIndex = -1;
            long long buff = 10132;
            long long output = 0;
            bool Sign = true;                   // true = +, false = -
            char *input = new char[buff];

            for (int i = 0; i < buff; ++i) {
                std::cin >> input[i];
                if (input[i] == int('-') && Sign) {
                    if (i == 0) {
                        Sign = false;
                        input[i] = 0;
                        i--;
                        continue;
                    } else{
                        throw WRONG_SIGN_POSITION;
                    }
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
                /*if (PointIndex != -1) {
                    for (int j = PointIndex + 1; j <= size; ++j) {
                        if (input[j] != int('0')) {
                            throw WRONG_TYPE_INPUT;
                        }
                    }
                }*/
                ++size;
                if (std::cin.peek() == ' ') {
                    break;
                }
                if (std::cin.peek() == '\n') {
                    break;
                }
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
                return output;
            }
            else{
                if(IsSizeInput) {
                    if (-output < 2) {
                        throw INCORRECT_DATA;
                    }
                }
                return -output;
            }
        }catch(Exceptions err)
        {
            char* wrongInput = new char[1000];
            for(int i = 0; std::cin.peek() != '\n'; ++i)
            {
                std::cin >> wrongInput[i];
            }
            delete [] wrongInput;
            switch (err) {
                case (WRONG_TYPE_INPUT): {
                    std::cout << "Expected Int type.\n";
                    break;
                }
                case (INCORRECT_DATA): {
                    std::cout << "Incorrect size.\n";
                    break;
                }
                case (WRONG_POINT_POSITION): {
                    std::cout << "Incorrect point position.\n";
                    break;
                }
                case (WRONG_SIGN_POSITION):
                {
                    std::cout << "Incorrect sign position.\n";
                    break;
                }
                case (LETTER_INPUT):
                {
                    std::cout << "Expected number, not letters.\n";
                    break;
                }
                default:
                    break;
            }
            std::cout << "Please, input the number one more time.\n";
        }
    }
}

bool recursionCheck(double* arr, int start, int end)
{
    if(end - start > 1){
        if(end / 3 != 0) {
            if (recursionCheck(arr, start, start + end / 3 - 1)) {
                return true;
            }
            if(recursionCheck(arr, start + end / 3, end))
            {
                return true;
            }
            else return false;
        }
        else {
            if (recursionCheck(arr, start, start + end / 3)) {
                return true;
            }

            if (recursionCheck(arr, start + end / 3 + 1, end)) {
                return true;
            } else
                return false;
        }
    }
    else if (cbrt(pow(arr[start], 2) + 2) < 10 || cbrt(pow(arr[end], 2) + 2) < 10 ) {
        return true;
    }else
        return false;
}
