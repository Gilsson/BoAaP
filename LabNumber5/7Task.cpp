#include <iostream>
#include <iostream>

int CharToInt(char str)
{
    return int(str - int('0'));
}

char* Addition(char* str_first, long long size_first,
               char* str_second, long long size_second);

long long SizeOfGreatest(char* str_first, long long size_first, char* str_second, long long size_second)
{
    long long new_size = (size_first > size_second) ? size_first : size_second;
    char* temp_first = new char[3*new_size]{};
    char* temp_second = new char[3*new_size]{};
    for(long long i = 0; i < new_size; ++i)
    {
        temp_first[i] = '0';
        temp_second[i] = '0';
    }
    for(long long i = size_first - 1, j = new_size - 1; i >= 0; --i, --j)
    {
        temp_first[j] =str_first[i];
    }
    for(long long i = size_second - 1, j = new_size - 1; i >= 0; --i, --j)
    {
        temp_second[j] = str_second[i];
    }
    long long real_size1 = 0, real_size2 = 0;
    for(long long i = 0; i < new_size; ++i)
    {
        if(temp_first[i] != '0')
        {
            real_size1 = (new_size - i);
            break;
        }
    }
    for(long long i = 0; i < new_size; ++i)
    {
        if(temp_second[i] != '0')
        {
            real_size2 = (new_size - i);
            break;
        }
    }
    if(real_size1 > real_size2)
    {
        return real_size1;
    }else if(real_size2 > real_size1)
    {
        return real_size2;
    }else
    {
        for(long long i = 0; i < new_size; ++i)
        {
            if(temp_first[i] > temp_second[i])
            {
                return real_size1;
            }
        }
    }
    return real_size2;
}

char* TurnIntoRealSize(char* str, long long& size);

auto TurnIntoReverseCode(char* str, long long& size)
{
    for(int i = 0; i < size; ++i)
    {
        if(str[i] < int('0') || str[i] > int('9')) {
            str[i] = '\0';
        }
        else {
            str[i] = 9 - (str[i] - '0') + '0';
        }
    }
    char temp[] = "1";
    long long sizeTemp = 1;
    TurnIntoRealSize(temp, sizeTemp);
    TurnIntoRealSize(str, size);
    return Addition(str, size, temp, sizeTemp);
}


char* Shift(char* str, long long size, long long shiftNum)
{
    str = TurnIntoRealSize(str, size);
    char* temp = new char[size + shiftNum + 1]{};
    for(long long it = size + shiftNum - 1; it >= 0; --it)
    {
        temp[it] = '0';
    }
    if(shiftNum < 0) {
        for (long long it = 0; it < size + shiftNum; ++it) {
            temp[it] = str[it];
        }
    }else {
        for (long long it = 0; it < size; ++it) {
            temp[it] = str[it];
        }
    }
    temp[size + shiftNum] = '\0';
    return temp;
}

char* TurnIntoRealSize(char* str, long long& size)
{
    long long pos = 0;
    if(str[0] == '0' && str[1] == '\0') {
        size = 1;
        return str;
    }
    while(str[pos] == '0')
    {
        ++pos;
    }
    long long temp_size = 0;
    while(str[temp_size + pos] != '\0')
    {
        ++temp_size;
    }
    size = temp_size;
    char* temp = new char[size + 1];
    for(long long i = pos, count = 0; count < size; ++i)
    {
        temp[count] = str[i];
        ++count;
    }
    temp[size] = '\0';
    str = new char[size + 1];
    for(long long i = 0; i < size; ++i)
    {
        str[i] = temp[i];
    }
    str[size] = '\0';
    return str;
}

char* Multiply(char* str_first, long long size_first, char* str_second, long long size_second)
{
    str_first = TurnIntoRealSize(str_first, size_first);
    str_second = TurnIntoRealSize(str_second, size_second);
    long long new_size = 2 * SizeOfGreatest(str_first, size_first, str_second, size_second) + 1;
    char* result = new char[new_size]{};
    for(long long i = 0; i < new_size - 1; ++i)
    {
        result[i] = '0';
    }
    result[new_size - 1] = '\0';
    char* temp_sum = new char[1]{};
    temp_sum[0] = '\0';
    long long res_size = 1;
    for(long long i = size_second - 1; i >= 0; --i)
    {
        for(long long j = CharToInt(str_second[i]); j > 0; --j){
            temp_sum = Addition(str_first, size_first, temp_sum, res_size);
            temp_sum = TurnIntoRealSize(temp_sum, res_size);
        }
        temp_sum = Shift(temp_sum, res_size, (size_second - 1) - i);
        result = Addition(result, new_size, temp_sum, res_size);
        for(long long k = 0; k < res_size; ++k)
        {
            temp_sum[k] = '0';
        }
    }
    return result;
}

char* Addition(char* str_first, long long size_first,
               char* str_second, long long size_second)
{
    str_first = TurnIntoRealSize(str_first, size_first);

    str_second = TurnIntoRealSize(str_second, size_second);
    long long new_size = (size_first > size_second) ? size_first : size_second;
    ++new_size;
    char* temp_first = new char[new_size + 2]{};
    char* temp_second = new char[new_size + 2]{};
    char *result = new char[new_size + 2]{};
    for(long long i = 0; i < new_size; ++i)
    {
        result[i] = '0';
        temp_first[i] = '0';
        temp_second[i] = '0';
    }
    result[new_size + 1] = '\0';
    temp_first[new_size + 1] = '\0';
    temp_second[new_size + 1] = '\0';
    for(long long i = size_first - 1, j = new_size - 1; i >= 0; --i, --j)
    {
        temp_first[j] =str_first[i];
    }
    for(long long i = size_second - 1, j = new_size - 1; i >= 0; --i, --j)
    {
        temp_second[j] = str_second[i];
    }
    for(long long i = new_size - 1; i >= 0; --i)
    {
        int temp = CharToInt(temp_first[i]) + CharToInt(temp_second[i]) + CharToInt(result[i]);
        if(temp >= 10)
        {
            result[i] = '0' + temp % 10;
            result[i - 1] = '0' + temp / 10;
        }else
        {
            result[i] = '0' + temp;
        }
    }
    result = TurnIntoRealSize(result, new_size);
    return result;
}

char* Substract(char* str_first, long long size_first)
{
    char* temp_first = new char[size_first + 1] {};
    char *result = new char[size_first + 1] {};
    for(int i = 0; i < size_first; ++i)
    {
        result[i] = '0';
        temp_first[i] = '0';
    }
    temp_first[size_first] = '\0';
    result[size_first] = '\0';
    for(int i = size_first - 1; i >= 0; --i)
    {
        temp_first[i] = str_first[i];
    }
    if(CharToInt(temp_first[size_first - 1]) - 1 < 0) {
        for (int i = size_first - 1; i >= 0; --i) {
            if (CharToInt(temp_first[i]) >= 1) {
                result[i] = temp_first[i] + CharToInt(result[i]);
                temp_first[i] = result[i];
                break;
            }
            else {
                result[i] = '0' + 10 + CharToInt(result[i]);
                if(result[i] == '0' + 10)
                {
                    result[i] = '0' + 9;
                }
                temp_first[i] = result[i];
                result[i - 1] -= 1;
            }}
    }else
    {
        temp_first[size_first - 1] -= 1;
    }
    return temp_first;
}

auto FillString(int &size)
{
    char* temp = new char[10];
    scanf("%*[\n]", temp);
    auto string = new char[22]{0};
    scanf("%[^\n^' ']%*c", string);
    int newsize = 0;
    for(int i = 0; i < 22; ++i)
    {
        if(string[i] != '\0')
        {
            ++newsize;
        }
    }
    auto output = new char[newsize];
    for(int i = 0; i < newsize; ++i)
    {
        output[i] = string[i];
    }
    return output;
}

unsigned long long ModularMultiply(unsigned long long base, unsigned long long power, unsigned long long mod)
{
    unsigned long long output = 0;
    while(power != 0)
    {
        if(power & 1)
        {
            output = (output + base) % mod;
            base = (base + base) % mod;
            power >>= 1;
        }
    }
    return output;
}

int main()
{
    int sizeK = 0;
    auto K = FillString(sizeK);
    int sizeN = 0;
    auto n = FillString(sizeN);
    int sizeT = 0;
    auto t = FillString(sizeT);
    long long size = 9;
    char* temp = new char[]{"12345673"};
    temp = TurnIntoReverseCode(temp, size);
    temp = Addition(temp, size, "12345672", 8);
    std::cout << temp;
}