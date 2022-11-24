#include <iostream>
#include <string>



std::string to_binary_code(int number)
{
    std::string code;
    while(number != 0)
    {
        code.push_back((number % 2) + int('0'));
        number >>= 1;
    }
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

int main()
{
    int a = 4;
    std::string b = to_binary_code(a);
    std::string c = to_binary_code(a);
    forward_reverse(b);
    std::cout << b;
}