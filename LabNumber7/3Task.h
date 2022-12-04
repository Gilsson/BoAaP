//
// Created by Gilsson on 11/27/2022.
//

#ifndef LABNUMBER7_3TASK_H
#define LABNUMBER7_3TASK_H

#include <iostream>

#define BITS 16

void resize(std::string & notation1, std::string& notation2)
{
    if(notation1.size() > notation2.size())
    {
        for(int i = notation2.size(); i < notation1.size(); ++i)
        {
            notation2.insert(0, 1, 0);  // O(K)
        }
    }
    else
    {
        for(int i = notation1.size(); i < notation2.size(); ++i)
        {
            notation1.insert(0, 1, 0);  // O(K)
        }
    }
}

void normalize_number(std::string* notation, int sys)
{
    while(notation[0][0] == '0') {
        std::string temp = *notation;
        notation[0].resize(notation[0].size() - 1, '0');  // O(K)
        for (int i = 0; i < notation[0].size(); ++i) {  // O(K)
            notation[0][i] = temp[i + 1];
        }
    }
        for(int i = 0; i < notation[0].size(); ++i)  // O(K)
        {
            if(notation[0][i] > int('9'))
            {
                notation[0][i] = int('A') + notation[0][i] - '9' - 1;
            }
        }
}

void digitize(std::string & notation, int sys)
{
    for(auto &i : notation)  // O(K)
    {
        if(i > int('9'))
        {
            i = i - 'A' + 10;
        }else{
            i -= int('0');
        }
    }
}

void ToAdditionalCode(std::string& str, int sys)
{
    digitize(str, sys);
    std::string temp;
    temp.resize(BITS, 0);
    int size = str.size();
    for(int i = BITS - 1, count = size - 1; i >= 0 && count >= 0; --count, --i)
    {
        temp[i] = str[count];
    }
    for(auto &i : temp)
    {
        i = sys - 1 - i;
    }
    str = temp;
    size = str.size();
    str[size - 1] += 1;
    if(str[size - 1] == sys)
    {
        str[size - 1] = 0;
        str[size - 2] += 1;
        for(int i = size - 2; i >= 0; --i)
        {
            if(str[i] >= sys)
            {
                str[i] %= sys;
                str[i - 1] += 1;
            }else{
                break;
            }
        }
    }
}

void ToNormalForm(std::string& notation,int sys)
{
    if(notation[0] == sys - 1)
    {
        for(int i = 1; i < notation.size(); ++i)
        {
            notation[i] = sys - 1 - notation[i];
        }
    }
    while(notation[0] == 0)
    {
        notation.erase(0, 1);
    }
    while(notation[1] == sys - 1)
    {
        notation.erase(1, 1);
    }
    for(auto &i : notation)
    {
        if(i > 9)
        {
            i = 'A' - 10 + i;
        }else{
            i = '0' + i;
        }
    }

    //notation.erase(0, 1);
}

std::string* addition(std::string notation1, std::string notation2, int sys, bool sign)
{
    if(notation2[0] == '-')
    {
        notation2.erase(0, 1);
        ToAdditionalCode(notation2, sys);
    }else{
        digitize(notation2, sys);
    }if(notation1[0] == '-')
    {
        notation1.erase(0, 1);
        ToAdditionalCode(notation1, sys);
    }else{
        digitize(notation1, sys);
    }
    std::string* result = new std::string();
    bool flag = notation1 < notation2;
    bool overflow = 0;
    resize(notation1, notation2);
    int size = notation1.size();
    result->resize(size + 1, 0);
    for(int i = size - 1; i >= 0; --i)
    {
        //int temp = result[i + 1];
        int temp = result[0][i + 1];
        result[0][i + 1] = (result[0][i + 1] + notation2[i] + notation1[i]) % (sys);
        //if(i == 0 && (temp + notation1[i] + notation2[i]) / sys > 0)
        //    overflow = true;
        result[0][i] = (temp + notation1[i] + notation2[i]) / sys;
    }
    //result[0][!overflow] = (sys - 1 + result[0][!overflow]) % sys;
    ToNormalForm(result[0], sys);
    //normalize_number(result, sys);
    return result;
}

std::string * substraction(std::string& notation1, std::string& notation2, int sys)
{
    auto result = new std::string();
    resize(notation2, notation1);
    digitize(notation1, sys);
    digitize(notation2, sys);
    bool flag = notation1 > notation2;
    if(!flag)
    {
        std::string temp = notation1;
        notation1 = notation2;
        notation2 = temp;
    }
    int size = notation2.size();
    result->resize(size+1, '0');
    notation1.insert(0, 1, 0);
    notation2.insert(0, 1, 0);
    for(int i = size; i > 0; --i)
    {
        if(notation1[i] < notation2[i]){
            result[0][i] += sys - (notation2[i] - notation1[i]);
            notation1[i - 1] -= 1;
        }else{
            result[0][i] += notation1[i] - notation2[i];
        }
    }
    normalize_number(result, sys);
    if(!flag)
        result[0].insert(0, 1, '-');
    return result;
}

#endif //LABNUMBER7_3TASK_H
