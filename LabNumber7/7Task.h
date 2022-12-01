//
// Created by Gilsson on 11/29/2022.
//

#ifndef LABNUMBER7_7TASK_H
#define LABNUMBER7_7TASK_H

#include <iostream>

long long DoubleTen(long long base)
{
    int temp_base = 0, temp_number = pow(10, base);
    while(temp_base != base)
    {
        if(temp_number & 1) {
            ++temp_base;
            temp_number += pow(10, temp_base);
        }
        else{
            --temp_base;
        }
        std::cout << temp_number << " ";
    }
    ++base;
    return DoubleTen( base);
}


#endif //LABNUMBER7_7TASK_H
