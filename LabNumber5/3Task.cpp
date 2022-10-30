#include <iostream>
#include <iomanip>

enum Exceptions
{
    LETTER_INPUT,
    WRONG_TYPE_INPUT,
    WRONG_SIGN_POSITION,
    WRONG_POINT_POSITION,
    INCORRECT_DATA,
};

long double PrintNum(bool IsSizeInput = false)
{
    while (true) {
        try{
            int size = 0;
            //bool IsWrongInput = false;
            long long PointIndex = -1;
            long long buff = 113200132;
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

long long** FillMatrix(const long long N, const long long K)
{
    auto** matrix = new long long * [N];
    for(int i = 0; i < N; ++i)
    {
        matrix[i] = new long long [K];
    }
    for(int i = 0; i < N; ++i){
       for(int j = 0; j < K; ++j)
       {
           matrix[i][j] = PrintNum();
       }
    }
    return matrix;
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
        return newVec;
    }
}


void showVector(long long* vector, size_t vecSize)
{
    long long multiply = 1;
    for(int i = 0; i < vecSize; ++i)
    {
        std::cout << vector[i] << " ";
        multiply *= vector[i];
    }
    std::cout << std::endl;
    std::cout << "Multiply of elements of array: " << multiply;
    std::cout << std::endl;
}


int main()
{
    long long N = 0, K = 0;
    N = PrintNum(true);
    K = PrintNum(true);
    long long** matrix = nullptr;
    matrix = FillMatrix(N, K);
    long long vecSize = N <= K ? N : K;
    long long* newVector = nullptr;
    newVector = FillVector(matrix, vecSize);
    showVector(newVector, vecSize);
    return 0;
}
