//
// Created by Gilsson on 11/29/2022.
//

#ifndef LABNUMBER7_7TASK_H
#define LABNUMBER7_7TASK_H

#include <iostream>
#include <algorithm>
#include <string>

std::string dividide(std::string str)
{
    std::string result = str;
    int part = 0;
    for (int i = 0; i < str.size(); i++) { // O(N)
        result[i] = (str[i] - '0' + 10 * part) / 2 + '0';
        part = (str[i] - '0') % 2;
    }
    int count = 0;
    for(; count < result.size(); ++count) // O(N)
    {
        if(result[count] != '0')
        {
            break;
        }
    }
    result.erase(0, count);
    return result;
}

std::string to_binary_code(std::string& str, int k)
{
    std::string result;
    std::string code = str;
    while(code != "" && result.size() != k)
    { // O(K)
        result.push_back((code[code.size() - 1] - '0') % 2 + '0');
        code = dividide(code); // O(2N)
    }
    while(result.size() < k) // O(K - size)
    {
        result.push_back('0');
    }
    std::reverse(result.begin(), result.end()); // O(K)
    if(result.size() - k > 0)
    {
        result.erase(0, result.size() - k);
    }
    str = result; // O(K)
    return str;
}

#endif //LABNUMBER7_7TASK_H
