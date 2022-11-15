#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;
    int greatest_size = -1;
    char buff = str[0];
    bool flag = false;
    for(int i = 0, j = str.length() - 1; i <= j; ++i, --j)
    {
        if(buff != str[i] || buff != str[j])
        {
            flag = true;
        }
        if(str[i] != str[j])
        {
            greatest_size = str.length();
            break;
        }
    }
    if(greatest_size == str.length())
        std::cout << greatest_size;
    else if(!flag)
        std::cout << str.length() - 1;
    else
        std::cout << -1;
    return 0;
}