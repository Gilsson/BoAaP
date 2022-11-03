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
#include <stdio.h>


enum Exceptions
{
        LETTER_INPUT,
        WRONG_TYPE_INPUT,
        WRONG_SIGN_POSITION,
        WRONG_POINT_POSITION,
        INCORRECT_DATA,
        EMPTY_STRING,
        WRONG_SPACE_POSITION,
};


long double PrintNum(bool IsSizeInput = false)
{
    while (true) {
        int size = 0;
        long long PointIndex = -1;
        long long buff = 10132;
        long double output = 0;
        bool Sign = true;                   // true = +, false = -
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
                if (input[i] == int('-')) {
                    if (i == 0) {
                        Sign = false;
                        input[i] = '0';
                        i--;
                        continue;
                    } else {
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
                if(output < 2e18 || output > -2e18)
                    return output;
            }
            else{
                if(IsSizeInput) {
                    if (-output < 2) {
                        throw INCORRECT_DATA;
                    }
                }
                if(output < 2e18 || output > -2e18)
                    return -output;
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
                default:
                    break;
            }
            delete[] temp;
            delete[] wrongInput;
        }
    }
}

bool recursionCheck(long double* arr, int start, int end)
{
    if(end - start > 1){
        {
            if (recursionCheck(arr, start, start + (end - start + 1) / 3 - 1)) {
                return true;
            }
            if(recursionCheck(arr, start + (end - start + 1) / 3, end))
            {
                return true;
            }
            else return false;
        }
        /*else {
            if (recursionCheck(arr, start, start + end / 3)) {
                return true;
            }

            if (recursionCheck(arr, start + end / 3 + 1, end)) {
                return true;
            } else
                return false;
        }*/
    }
    else if (cbrt(pow(arr[start], 2) + 2) < 10 || cbrt(pow(arr[end], 2) + 2) < 10 ) {
        return true;
    }else
        return false;
}

long long *FillVector(long long **matrix, long long &vecSize) {
    try {
        auto *vector = new long long[vecSize];
        int newVecSize = 0;
        for (int i = 0, vectorCount = 0; i < vecSize; ++i) {
            if (matrix[i][i] != 0 && matrix[i][i] % 2 == 0) {
                vector[vectorCount] = matrix[i][i];
                ++vectorCount;
                newVecSize++;
            }
        }
        if (newVecSize <= 0)
            throw newVecSize;
        auto *newVector = new long long[newVecSize];
        for(int i = 0; i < newVecSize; ++i)
        {
            newVector[i] = vector[i];
        }
        vecSize = newVecSize;
        return newVector;
    }
    catch (int err) {
        std::cout << "Incorrect array size: " << err << '\n';
        std::cout << "Try with another input!\n";
        auto* newVec = new long long[vecSize];
        for(int i = 0; i < vecSize; ++i){
            newVec[i] = 0;
        }
        throw err;
        return newVec;
    }
}

bool Compare(long long* Arr1, int Arr1Size, long long* Arr2, int Arr2Size)
{
    if (Arr1Size != Arr2Size)
    {
        return false;
    }
    for (int i = 0; i < Arr1Size; i++)
    {
        if (Arr1[i] != Arr2[i])
        {
            return false;
        }
    }
    return true;
}



auto fillArray(int N, int M,int X) {
    auto array = new long long* [N];
    for (int i = 0; i < N; ++i) {
        array[i] = new long long[M];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            array[i][j] = X;
        }
    }
    return array;
}

auto averageArray(long long* array, int N)
{
    long double sum = 0;
    for(int i = 0; i < N; ++i)
    {
        sum += array[i];
    }
    long double average = sum / N;
    std::cout << "Average of elements in the array is: " << average << "\n";
    return average;
}

auto reverseArray(long double** arr, int N, int M){
    auto newArr = new long double*[N];
    for(int i = 0; i < M; ++i){
        newArr[i] = new long double[M];
    }
    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
        {
            newArr[N - 1 - i][M - 1 - j] = arr[i][j];
        }
    }
    return newArr;
}

long long* fillEvenArray(long long** arr, int N, int M, int& newArrSize)
{
    while(true) {
        auto newArray = new long long[(M / 2 + 1) * N];
        int count = 0;
        for (int j = 1; j < M; j += 2) {
            for (int i = 0; i < N; ++i) {
                if (arr[i][j] % 2 != 0) {
                    newArray[count] = arr[i][j];
                    ++count;
                }
            }
        }
        if (count != 0) {
            auto output = new long long[count];
            for (int i = 0; i < count; ++i) {
                output[i] = newArray[i];
            }
            newArrSize = count;
            return output;
        }else{
            std::cout << "There are no odd elements/even column in the matrix!\n";
            std::cout << "Fill the matrix one more time!\n";
            return nullptr;
        }
    }
}

auto fillArray(int N, int M) {
    int Count = 0;
    auto array = new long double* [N];
    for (int i = 0; i < N; ++i) {
        array[i] = new long double[M];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            array[i][j] = ++Count;
        }
    }
    return array;
}

auto ReverseFillArray(int N, int M) {
    int Count = N * M;
    auto array = new long double* [N];
    for (int i = 0; i < N; ++i) {
        array[i] = new long double[M];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            array[i][j] = Count--;
        }
    }
    return array;
}

bool Compare(long double** Arr1, int Arr1Size, long double** Arr2, int Arr2Size)
{
    if (Arr1Size != Arr2Size)
    {
        return false;
    }
    for (int i = 0; i < Arr1Size; i++)
    {
        for (int j = 0; j < Arr1Size; j++)
        {
            if (Arr1[i][j] != Arr2[i][j])
            {
                return false;
            }
        }
    }
    return true;
}



/*TEST(PrintNum, TestFromFile) {
    FILE* fileptr;
    fileptr = fopen("TestInput.txt", "w+");

    EXPECT_THROW(PrintNum(), Exceptions);
}*/

TEST(Task2, recursion_test)
{
    int n = 10;
    auto* arr = new long double[n]{1000, 1000, 1000, 1000, 1000, 1, 1000, 1000, 1000, 1000};
    EXPECT_TRUE(recursionCheck(arr, 0, n - 1));
    EXPECT_FALSE(recursionCheck(arr, 0, 3));
    delete[] arr;
}

TEST(Task2, recursion_find_test)
{
    int n = 5;
    auto* arr = new long double[n]{ 100, 10, 100, 100, 1000};
    EXPECT_TRUE(recursionCheck(arr, 0, n - 1));
    EXPECT_FALSE(recursionCheck(arr, 2, n - 1));
}

TEST(Task2, difficult_test)
{
    int n = 40;
    auto* arr = new long double[n]{ 100, 100, 100, 100, 1000, 100,
                               100, 100, 100, 100, 1000, 100,
                              100, 100, 100, 100, 1000, 100,
                              100, 100, 100, 100, 1000, 100,
                              10, 100, 100, 100, 100, 1000, 100,
                              100, 100, 100, 100, 1000, 100,
                              100, 100, 100};
    EXPECT_TRUE(recursionCheck(arr, 0, n - 1));
}

TEST(Task3, Throw_Test)
{
    int N = 3, K = 6;
    auto matrix = new long long*[N];
    for(int i = 0; i < 3; ++i){
        matrix[i] = new long long[K];
    }
    for(int i = 0, count = 0; i < N; ++i)
    {
        for(int j = 0; j < K; ++j){
            matrix[i][j] = count;
            ++count;
        }
    }
    long long vectorSize = 3;
    EXPECT_NO_THROW(try{
        FillVector(matrix, vectorSize);
    }
    catch(Exceptions err)
    {
        throw err;
    });
    vectorSize = 0;
    EXPECT_THROW(FillVector(matrix, vectorSize), int);
}

TEST(Task3, Compare_test) {
    int N = 3, K = 6;
    auto matrix = new long long*[N];
    for(int i = 0; i < 3; ++i){
        matrix[i] = new long long[K];
    }
    for(int i = 0, count = 0; i < N; ++i)
    {
        for(int j = 0; j < K; ++j){
            matrix[i][j] = count;
            ++count;
        }
    }
    long long vectorSize = 3;
    long long *vector = new long long[1]{14};
//   0    1   2   3 4 5
//   6    7    8 9 10 11
//  11 12 13   14 (<- this) 15 16
    EXPECT_EQ(*FillVector(matrix, vectorSize), *vector);
}
TEST(Task4, ReverseTest_True) {
    int ArrSize= 2;
    long double** Arr1 = fillArray(ArrSize, ArrSize);
    long double** Arr2 = new long double* [ArrSize];
    for (int i = 0; i < ArrSize; ++i) {
        Arr2[i] = new long double[ArrSize];
    }
    Arr2[0][0] = 4;
    Arr2[0][1] = 3;
    Arr2[1][0] = 2;
    Arr2[1][1] = 1;

    EXPECT_TRUE(Compare(reverseArray(Arr1, ArrSize, ArrSize), ArrSize, Arr2, ArrSize));
}

TEST(Task4, ReverseTest_Fails)
{
    int ArrSize = 4;
    long double** Arr1 = ReverseFillArray(ArrSize, ArrSize);
    long double** Arr2 = ReverseFillArray(ArrSize, ArrSize);
    EXPECT_FALSE(Compare(reverseArray(Arr1, ArrSize, ArrSize),ArrSize, Arr1, ArrSize));
}

TEST(Task4, ReverseTest_OneElem)
{
    int ArrSize = 40;
    auto Arr1 = fillArray(ArrSize, ArrSize);
    auto Arr2 = new long double*[ArrSize];
    Arr2[0] = new long double[ArrSize];
    Arr2[0][0] = 0;
    EXPECT_FALSE(Compare(reverseArray(Arr1, ArrSize, ArrSize),ArrSize, Arr1, ArrSize));
}

TEST(Task5, Crashtest) {
    int Arr1rows = 4;
    int Arr1columns = 4;
    long long** Arr1 = fillArray(Arr1rows, Arr1rows, 2);
    int VectorSize = 0;
    long long* Vector = new long long[VectorSize];
    int NewSize = 0;
    long long* NewArr = fillEvenArray(Arr1, Arr1rows, Arr1columns, NewSize);
    EXPECT_TRUE(Compare(NewArr, NewSize, Vector, VectorSize));
}


TEST(Task5, simpleTest) {
    int Arr1Size1 = 4;
    int Arr1Size2 = 4;
    long long** Arr1 = fillArray(Arr1Size1, Arr1Size1, 3);
    int Arr2Size = 8;
    long long* Arr2 = new long long[Arr2Size]{3,3,3,3,3,3,3,3};
    int NewSize = 0;
    long long* NewArr = fillEvenArray(Arr1, Arr1Size1, Arr1Size2, NewSize);
    EXPECT_TRUE(Compare(NewArr, NewSize, Arr2, Arr2Size));
}


TEST(Task5, averageTest) {
    int Arr2Size = 8;
    long long* Arr2 = new long long[Arr2Size] {0,0,0,0,3,3,3,3};
    EXPECT_EQ(averageArray(Arr2,Arr2Size),1.5);
}