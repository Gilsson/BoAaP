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
    std::string *result = substraction(notation, notation2, sys);
    std::cout << *result << '\n';
    ToNormalForm(notation);
    ToNormalForm(notation2);
    result = addition(notation, notation2, sys);
    std::cout << *result;
    system("pause");
    return 0;
}
