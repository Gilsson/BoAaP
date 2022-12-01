#include <iostream>
#include <string>

const int BIT_SIZE = 16;

std::string to_binary_code(int number)
{
    std::string code;
    while(number > 0)
    {
        code.push_back((number % 2) + int('0'));
        number >>= 1;
    }
    for(int i = code.size(); i < BIT_SIZE; ++i)
        code.push_back(int('0'));
    std::reverse(code.begin(), code.end());
    return code;
}

void forward_reverse(std::string& code)
{
    for(auto &it : code)
    {
        it = (it == int('1')) ? int('0') : int('1');
    }
}

void FillZero(std::string& str, int newsize)
{
    str.insert(0, newsize - str.size(), '0');
}

void RepairNumber(std::string& str)
{
    for(int i = str.size() - 1; i >= 1; --i)
    {
        if(i != 1) {
            if (str[i] >= '2') {
                str[i - 1] += 1;
                str[i] = str[i] - 2;
            }
        }else{
            if (str[i] >= '2') {
                str.insert(1, "1");
                str[i + 1] = str[i + 1] - 2;
            }
        }
    }
}

std::string sum(std::string& string1, std::string& string2)
{
    std::string result;

    forward_reverse(string1);
    forward_reverse(string2);
    int size = string1.size() > string2.size() ? string1.size() : string2.size();
    //FillZero(string1, size);
   //FillZero(string2, size);
    result.resize(size, '0');
    result[15] = '1';
    for(int i = size - 1; i > 0 ; --i)
    {
        result[i] += string1[i] + string2[i] - 2 * '0';
        if(result[i] >= '2'){
            result[i] = result[i] - 2;
            result[i - 1] += 1;
        }
        //result[i - 1] += (string1[i] + string2[i] - 1) / (2 * int('0'));
    }
    //result[15] += result[0] - '0';
    //RepairNumber(result);

    forward_reverse(result);
    return result;
}

int main()
{
    int a = 5;
    int f = 6;
    std::string b = to_binary_code(a);
    std::cout << b << '\n';
    std::string c = to_binary_code(f);
    std::cout << sum(b, c) << '\n';
    //forward_reverse(b);
    //std::cout << b;
}