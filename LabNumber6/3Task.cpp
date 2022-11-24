#include <iostream>
#include <windows.h>

#define MAX_BUFFER_SIZE 10000

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

long double PrintNum(bool IsSizeInput) {
    while (true) {
        int size = 0;
        long long PointIndex = -1;
        long long buff = 10132;
        long double output = 0;
        bool WrongSign = false;
        bool Sign = true;                   // true = +, false = -
        char *input = new char[buff]{0};
        scanf("%[^\n]%*c", input);
        try {
            if (strlen(input) == 0) {
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
                if (input[i] == int(' ')) {
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
                    if (output < 1 || output > 10000) {
                        throw INCORRECT_DATA;
                    }
                }
                if (size < 18 || output < 1e18)
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
                if (size < 18 || output < 1e18)
                    return -output;
                else
                    throw TOO_BIG_VALUE;
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
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

            delete[] wrongInput;
        }
    }
}


char* Copy(char* Destination, const char* Source)
{
    std::cout << "Copying of the first string into the second:\n";
    size_t size = 0;
    delete Destination;
    while(Source[size] != '\0')
    {
        ++size;
    }
    Destination = new char[size];
    Destination[size] = '\0';
    while(size != 0)
    {
        Destination[size - 1] = Source[size - 1];
        --size;
    }
    std::cout << Destination << '\n';
    return Destination;
}

void Compare(const char* Str1, const char* Str2)
{
    for(int i = 0; Str1[i] != '\0' && Str2[i] != '\0'; ++i)
    {
        if(Str1[i] > Str2[i])
        {
            std::cout << "First string is greater the the second!\n";
            return;
        }else if(Str1[i] < Str2[i])
        {
            std::cout << "First string is less the the first!\n";
            return;
        }else if(Str1[i] == Str2[i] && Str1[i + 1] != '\0' && Str2[i + 1] != '\0')
        {
            continue;
        }else if(Str1[i + 1] == '\0' && Str2[i + 1] != '\0'){
            std::cout << "First string is less the the first!\n";
            return;
        }
        else if(Str2[i + 1] == '\0' && Str1[i + 1] != '\0'){
            std::cout << "First string is greater the the second!\n";
            return;
        }
    }
    std::cout << "Strings are equal!\n";
}

void Concat(char* Destination, const char* Source)
{
    std::cout << "Concatenation of two strings: \n";
    size_t DestinationSize = 0;
    while(Destination[DestinationSize] != '\0')
    {
        ++DestinationSize;
    }
    size_t SourceSize = 0;
    while(Source[SourceSize] != '\0')
    {
        ++SourceSize;
    }
    char* temp = Destination;
    Destination = new char[SourceSize + DestinationSize];
    Destination[SourceSize + DestinationSize] = '\0';
    for(int i = 0; i < DestinationSize; ++i)
    {
        Destination[i] = temp[i];
    }
    while(SourceSize != 0)
    {
        Destination[DestinationSize + SourceSize - 1] = Source[SourceSize - 1];
        --SourceSize;
    }
    std::cout << Destination << '\n';
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

int main()
{
    while(true) {
        std::cout << "Exercise number 3:\n" << "Made by student of group 253502 Anton Hulis\n"
                  << "Number in the list is 7\n" << "TASK: write a function of comparing, copying and concatenating of strings.\n"
                                                    "Use pointers.\n";
        int size_first, size_second;
        std::cout << "Input length of the first strings: \n";
        size_first = PrintNum(true);
        std::cout << "\nInput length of the second strings: \n";
        size_second = PrintNum(true);
        char *a = new char[size_first + 1];
        char *b = new char[size_second + 1];
        std::cout << "Type the first string(it will take only first N elements from buffer)";
        char* buffer_cleaner = new char[MAX_BUFFER_SIZE];
        for(int i = 0; i < size_first; ++i)
        {
            char temp = getchar();
            if(temp != '\n')
                a[i] = temp;
        }
        a[size_first] = '\0';
        std::cout << "Type the second string(it will take only first N elements from buffer)";
        for(int i = 0; i < size_second; ++i)
        {
            std::cin >> b[i];
        }
        b[size_second] = '\0';
        Compare(a, b);
        Concat(a, b);
        Copy(a, b);
        if(RestartProgram())
        {
            break;
        }
    }
}