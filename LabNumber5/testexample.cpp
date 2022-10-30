//
// Created by gilsson on 10/23/22.
//

#include "cmake-build-debug/_deps/googletest-src/googletest/include/gtest/internal/gtest-port.h"
#include "cmake-build-debug/_deps/googletest-src/googletest/include/gtest/internal/gtest-internal.h"
#include "cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest-message.h"
#include "cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest-assertion-result.h"
#include "cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest-test-part.h"
#include "cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest_pred_impl.h"
#include "cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest.h"
#include <fstream>


std::ifstream cin("F:\\Projects\\BoAaP\\LabNumber5\\TestInput.txt");

enum Exceptions
{
    LETTER_INPUT,
    WRONG_TYPE_INPUT,
    WRONG_SIGN_POSITION,
    WRONG_POINT_POSITION,
    INCORRECT_DATA,
};
long double PrintNum() {
    while (true) {
        try {
            int size = 0;
            bool IsWrongInput = false;
            long long PointIndex = -1;
            long long buff = 113200132;
            long long output = 0;
            bool Sign = true;                   // true = +, false = -
            char *input = new char[buff];

            for (int i = 0; i < buff; ++i) {
                cin >> input[i];
                if (input[i] == int('-')) {
                    if (i == 0) {
                        Sign = false;
                        input[i] = 0;
                        i--;
                        continue;
                    } else {
                        IsWrongInput = true;
                        throw WRONG_SIGN_POSITION;
                        break;
                    }
                }
                if ((input[i] < int('0') || input[i] > int('9')) && input[i] != int('.')) {
                    std::cout << "Wrong Input\n";
                    IsWrongInput = true;
                    throw LETTER_INPUT;
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
                if (PointIndex == -1) {
                    for (int j = 0; j <= size; ++j) {
                        if (input[j] == int('.'))
                            PointIndex = j;
                    }
                }
                if (PointIndex != -1) {
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
                if (cin.peek() == ' ') {
                    break;
                }
                if (cin.peek() == '\n') {
                    break;
                }
            }
            if (PointIndex != -1) {
                for (int i = PointIndex - 1; i >= 0; --i) {
                    output += (input[i] - '0') * powl(10, PointIndex - i - 1);
                }
                for (int i = PointIndex + 1; i < size; ++i) {
                    output += (input[i] - '0') * powl(1 / 10.0, i - PointIndex);
                }
            } else {
                for (int i = size - 1; i >= 0; --i) {
                    output += (input[i] - '0') * powl(10, size - i - 1);
                }
                if (output < 2) {
                    throw INCORRECT_DATA;
                } else {
                    if (Sign)
                        return output;
                    else {
                        return -output;
                    }
                }
                break;
            }
        } catch (Exceptions e) {
            char *wrongInput = new char[1000];
            for (int i = 0; cin.peek() != '\n'; ++i) {
                cin >> wrongInput[i];
            }
            std::cout << "Please, input the number one more time.\n";
            throw e;
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

TEST(example, example_Test) {
    EXPECT_THROW({
        try{
            PrintNum();
        }catch(Exceptions e)
        {
                throw e;
        }
    }, Exceptions);
}

TEST(Task2, simple_test)
{
    int n = 10;
    auto* arr = new double[n]{1000, 1000, 1000, 1000, 1000, 1, 1000, 1000, 1000, 1000};
    EXPECT_TRUE(recursionCheck(arr, 0, n - 1));
    EXPECT_FALSE(recursionCheck(arr, 0, 3));
    delete[] arr;
}

TEST(Task2_0, modern_test)
{
    int n = 5;
    auto* arr = new double[n]{ 100, 10, 100, 100, 1000};
    EXPECT_TRUE(recursionCheck(arr, 0, n - 1));
    EXPECT_FALSE(recursionCheck(arr, 2, n - 1));
}

TEST(Task2_1, difficult_test)
{
    int n = 6;
    auto* arr = new double[n]{ 100, 100, 100, 100, 1000, 100};
    EXPECT_FALSE(recursionCheck(arr, 0, n - 1));
}
