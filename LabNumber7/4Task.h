//
// Created by Gilsson on 11/28/2022.
//

#ifndef LABNUMBER7_4TASK_H
#define LABNUMBER7_4TASK_H

//const std::string Rim{'I', 'V', 'X', 'L', 'C', 'D', 'M'};

std::string* ConvertToRim(int num)
{
    int temp = num;
    int size = 0;
    while(temp > 0)
    {
        temp/=10;
        ++size;
    }

    auto Rom = new std::string ();
    if(num <= 0)
    {
        return Rom;
    }
    int count = 0;
        while(num >= 1000)
        {
            if(count < 3) {
                Rom->push_back('M');
                num -= 1000;
                ++count;
            }
        }
        count = 0;
        while(num >= 500)
        {
            if(count == 0) {
                Rom->push_back('D');
                num -= 100;
            }if(num >= 500 && count < 3) {
                Rom->push_back('C');
                num -= 100;
                ++count;
            }else if(count >= 3){
                Rom->erase(Rom->size() - 4, 4);
                Rom->push_back('C');
                Rom->push_back('M');
                num -= 100;

            }
            if(num < 500)
            {
                num -= 400;
            }
        }
        count = 0;
        while (num >= 100)
        {
            if(count < 3) {
                Rom->push_back('C');
                num -= 100;
                ++count;
            }else{
                Rom->erase(Rom->size() - 3, 3);
                Rom->push_back('C');
                Rom->push_back('D');

                num -= 100;
            }
        }
        count = 0;
        while (num >= 50)
        {
            if(count == 0)
            {
                Rom->push_back('L');
                num -= 10;
            }
            if(count < 3 && num >= 50) {
                Rom->push_back('X');
                num -= 10;
                ++count;
            }else if(count >= 3){

                Rom->erase(Rom->size() - 4, 4);
                Rom->push_back('X');
                Rom->push_back('C');
                num -= 10;
            }
            if(num < 50)
            {
                num -= 40;
            }
        }
        count = 0;
        while(num >= 10)
        {
            if(count < 3) {
                Rom->push_back('X');
                ++count;
                num -= 10;
            }else{
                Rom->erase(Rom->size() - 3, 3);
                Rom->push_back('X');
                Rom->push_back('L');

                num -= 10;
            }
        }
        count = 0;
        while(num >= 5)
        {
            if(count == 0)
            {
                Rom->push_back('V');
                num -= 1;
            }
            if(count < 3 && num >= 5)
            {
                Rom->push_back('I');
                num -= 1;
                ++count;
            }else if(count >= 3){
                Rom->erase(Rom->size() - 4, 4);
                Rom->push_back('I');
                Rom->push_back('X');

                num -= 1;
            }
            if(num < 5)
            {
                num -= 4;
            }
        }
        count = 0;
        while(num >= 1)
        {
            if(count < 3)
            {
                ++count;
                num -= 1;
                Rom->push_back('I');
            }else{
                Rom->erase(Rom->size() - 3, 3);
                num -= 1;
                Rom->push_back('I');
                Rom->push_back('V');
            }
        }
        count = 0;
        /*if(count < 3) {
            Rom->push_back(Rim[number]);
            if (Rim[number] != 'V' && Rim[count] != 'L' && Rim[count] != 'D')
                ++count;
        }else{
            Rom->erase(i - 3, 3);
            Rom->push_back(Rim[number]);
            ++number;
            count = 0;
        }*/
    return Rom;
}

#endif //LABNUMBER7_4TASK_H
