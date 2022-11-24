#include <iostream>
#include <string>

std::string& minus(std::string& code, int end)
{
    if(end == 0)
    {
        code.insert(code.begin(), int('1'));
        code.insert(code.begin() + 1, int('0'));
        return minus(code, code.size() - 1);
    }
    if(code[end] == int('1'))
    {
        code[end] = int('0');
        return code;
    }
    else{
        return minus(code, end - 1);
    }
}

std::string& add_to_reverse(std::string& code)
{
    minus(code, code.size() - 1);
    return code;
}

std::string& forward_reverse(std::string& code)
{
    for(auto &it : code)
    {
        it = (it == int('1')) ? int('0') : int('1');
    }
    return code;
}


int main()
{
    std::string s;
    std::cin >> s;
    forward_reverse(s);
    add_to_reverse(s);
    std::cout << s;
}