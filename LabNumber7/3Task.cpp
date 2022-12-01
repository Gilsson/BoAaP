#include "3Task.h"
#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    std::string notation;
    std::string notation2;
    int sys = 10;
    std::cin >> notation;
    std::cin >> notation2;
    std::cin >> sys;

    std::string test = "1234ABBA";
    std::string test2 = "-BBBBAAAAAAAAAA";

    //ToAdditionalCode(test2, 12);
    std::cout << *addition(test, test2, 12, true) << '\n';

    if(notation[0] == '-')
    {
        //notation[0] = '0';
        //digitize(notation, sys);
        //notation[0] = sys - 1;
        //ToAdditionalCode(notation, sys);
        std::string* result2 = addition(notation, notation2, sys, true);
        std::cout << *result2 << '\n';
    }
    else if(notation2[0] == '-')
    {
        std::string temp1 = notation, temp2 = notation2;
        temp2.erase(0, 1);
        std::string *result = addition(temp1, temp2, sys, false);
        std::cout << *result << '\n';
        //notation2.erase(0, 1);
        //digitize(notation2, sys);
        //ToAdditionalCode(notation2, sys);



        std::string* result2 = addition(notation, notation2, sys, true);
        std::cout << *result2 << '\n';
    }
    else{
        std::string* result3 = addition(notation, notation2, sys, true);
        std::cout << *result3;
    }

//    std::string *result = addition(notation, notation2, sys, false);
//    std::cout << *result << '\n';
    /*ToNormalForm(temp1);
    ToNormalForm(temp2);*/

    system("pause");
    return 0;
}
