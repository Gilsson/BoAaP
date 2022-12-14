//
// Created by Gilsson on 12/14/2022.
//

#include "Implementations.h"
void ShowOutput(std::istream& file)
{
    std::string str;
    file.seekg(0);
    while(!file.eof()){
        std::getline(file, str);
        std::cout << str << '\n';
    }
}
int CompareDates(Rabotyaga &element1, Rabotyaga &element2){
    int pos1 = element1.date_hiring.find('/');
    std::string temp1;
    for(int i = 0; i < pos1; ++i)
    {
        temp1 += element1.date_hiring[i];
    }
    int pos2 = element2.date_hiring.find('/');
    std::string temp2;
    for(int i = 0; i < pos2; ++i)
    {
        temp2 += element2.date_hiring[i];
    }
    if(temp1 > temp2)
    {
        return 1;
    }else if(temp1 < temp2)
    {
        return -1;
    }else{
        int prev_pos1 = pos1 + 1;
        pos1 = element1.date_hiring.find('/', pos1 + 1);
        std::string temp1;
        for(int i = prev_pos1; i < pos1; ++i)
        {
            temp1 += element1.date_hiring[i];
        }
        int prev_pos2 = pos2 + 1;
        pos2 = element2.date_hiring.find('/', pos2 + 1);
        std::string temp2;
        for(int i = prev_pos2; i < pos2; ++i)
        {
            temp2 += element2.date_hiring[i];
        }
        if(temp1 > temp2)
            return 1;
        else if(temp1 < temp2)
            return -1;
        else{
            prev_pos1 = pos1 + 1;
            pos1 = element1.date_hiring.size();
            std::string temp1;
            for(int i = prev_pos1; i < pos1; ++i)
            {
                temp1 += element1.date_hiring[i];
            }
            prev_pos2 = pos2 + 1;
            pos2 = element2.date_hiring.size();
            std::string temp2;
            for(int i = prev_pos2; i < pos2; ++i)
            {
                temp2 += element2.date_hiring[i];
            }
            if(temp1 > temp2){
                return 1;
            }else if(temp1 < temp2)
                return -1;
            else
                return 0;
        }
    }
}