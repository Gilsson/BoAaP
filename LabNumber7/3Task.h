//
// Created by Gilsson on 11/27/2022.
//

#ifndef LABNUMBER7_3TASK_H
#define LABNUMBER7_3TASK_H

#include <iostream>

void resize(std::string & notation1, std::string& notation2)
{
    if(notation1.size() > notation2.size())
    {
        for(int i = notation2.size(); i < notation1.size(); ++i)
        {
            notation2.insert(0, 1, '0');
        }
    }
    else
    {
        for(int i = notation1.size(); i < notation2.size(); ++i)
        {
            notation1.insert(0, 1, '0');
        }
    }
}

void normalize_number(std::string* notation, int sys)
{
    while(notation[0][0] == '0') {
        std::string temp = *notation;
        notation[0].resize(notation[0].size() - 1, '0');
        for (int i = 0; i < notation[0].size(); ++i) {
            notation[0][i] = temp[i + 1];
        }
    }
        for(int i = 0; i < notation[0].size(); ++i)
        {
            if(notation[0][i] > int('9'))
            {
                notation[0][i] = int('A') + notation[0][i] - '9' - 1;
            }
        }
}

void digitize(std::string & notation, int sys)
{
    for(auto &i : notation)
    {
        if(i > int('9'))
        {
            i = i - 'A' + 10;
        }else{
            i -= int('0');
        }
    }
}

void ToNormalForm(std::string& notation)
{
    for(auto &i : notation)
    {
        if(i > 9)
        {
            i = 'A' - 10 + i;
        }else{
            i = '0' + i;
        }
    }
}

std::string* addition(std::string notation1, std::string notation2, int sys)
{
    std::string* result = new std::string();
    resize(notation1, notation2);
    digitize(notation1, sys);
    digitize(notation2, sys);
    int size = notation1.size();
    result->resize(size + 1, int('0'));
    for(int i = size - 1; i >= 0; --i)
    {
        //int temp = result[i + 1];
        result[0][i + 1] += (notation2[i] + notation1[i]) % sys;
        result[0][i] += (notation2[i] % (int('A') - 10) + notation1[i] % (int('A') - 10)) / sys;
    }
    normalize_number(result, sys);
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
