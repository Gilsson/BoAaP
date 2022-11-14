#include <iostream>
#include <string>

int find_count(const std::string& str, const char symbol)
{
    int count = 0;
    for(const auto it : str)
    {
        if(it == symbol)
        {
            ++count;
        }
    }
    return count;
}

int main()
{
    std::string str;
    std::cin >> str;
    long long output = 1;
    long long division = 1;
    std::string buff;
    for(int i = str.length() - 1; i >= 0; --i)
    {
        if(find_count(buff, str[i]) == 0) {
            int find = find_count(str, str[i]);
            buff.push_back(str[i]);
            output *= i + 1;
            for (; find != 0; --find) {
                division *= find;
            }
        }
        else
            output *= i + 1;
    }
    std::cout << output / division;
}