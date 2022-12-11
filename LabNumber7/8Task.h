//
// Created by Gilsson on 11/29/2022.
//

#ifndef LABNUMBER7_8TASK_H
#define LABNUMBER7_8TASK_H
#include <iostream>
#include <string>

std::string ConverToThird(int num)
{
    std::string result;
    while(num > 0) // O(N)
    {
        result.push_back(num % 3 + '0');
        num /= 3;
    }
    result.push_back('0');
    std::reverse(result.begin(), result.end());
    return result;
}

std::string ToUnrealForm(std::string num)
{
    for(int i = num.size() - 1; i > 0; --i ) // O(N)
    {
        if(i != 1 && num[i] < '1'){
            num[i] += 3;
            num[i - 1] -= 1;
            /*if(num[i - 1] == '0') {
                num[i] -= 1;
                num[i - 1] -= 1;
            }*/
        }
    }
    while(num[0] == '0') // O(N)
    {
        num.erase(0, 1);
    }
    return num;
}


#endif //LABNUMBER7_8TASK_H
