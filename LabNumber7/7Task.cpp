#include "7Task.h"
#include <vector>
#include <algorithm>
#include <iostream>


int main()
{
    int number = 0;
    std::cin >> number;

    /*std::vector<std::vector<std::string>> first(2);
    std::vector<std::vector<std::string>> second(2);
    first[0].push_back("1");
    second[0].push_back("0");
    int count = 1;
    int j = 0;
    while(count < number)
    {
        ++j;
        for(int i = 0; i < second[0].size();++i)
        {
            std::string temp = to_binary_code(second[0][i]);
            second[0][i].insert(0, "0");
            if(temp.size() < j || temp[temp.length() - j] == '0')
            {
                second[1].push_back(second[0][i]);
            }
        }
        for(int i = 0; i < first[0].size();++i)
        {
            std::string temp = to_binary_code(first[0][i]);
            first[0][i].insert(0, "0");
            if(temp.size() < j || temp[temp.length() - j] == '0')
            {
                second[1].push_back(first[0][i]);
            }
        }
        for(int i = 0; i < second[0].size();++i)
        {
            std::string temp = to_binary_code(second[0][i]);
            //second[0][i].insert(0, "0");
            if(temp.size() < j + 1 || temp[temp.length() - j + 1] == '0')
            {
                second[0][i][0] = '1';
                first[1].push_back(second[0][i]);
            }
        }
        std::swap(first[0], first[1]);
        std::swap(second[0], second[1]);
        first[1].clear();
        second[1].clear();
        count += first[0].size();
    }
    int diff = count - number;
    std::cout << first[0][first[0].size() - 1 - diff];
    //DoubleTen(1);*/
    return 0;
}