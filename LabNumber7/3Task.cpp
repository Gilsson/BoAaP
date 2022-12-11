#include "3Task.h"
#include <iostream>
#include <windows.h>



int main()
{
    SetConsoleOutputCP(CP_UTF8);
    PrintInfo();
    while(true) {
        std::string notation;
        std::string notation2;
        int sys = 10;
        std::cout << "Введите основание системы счисления\n";
        sys = PrintNum(true); // O(N)
        std::cout << "Введите первое число:\n";
        notation = PrintString(); // O(N)
        std::cout << "Введите второе число\n";
        notation2 = PrintString();                    // O(N)
        /*if (notation[0] == '-' && notation2[0] == '-') {
            std::string temp1 = notation, temp2 = notation2;
            temp2.insert(0, 1, '-');
            std::cout << "Разность двух чисел:\n";
            std::string *result1 = addition(temp1, temp2, sys, true); // O(N)
            std::cout << *result1 << '\n';
            //notation[0] = '0';
            //digitize(notation, sys);
            //notation[0] = sys - 1;
            //ToAdditionalCode(notation, sys);
            std::cout << "Сумма двух чисел:\n";
            std::string *result2 = addition(notation, notation2, sys, true); // O(K)
            std::cout << *result2 << '\n';

        } else if (notation2[0] == '-') {
            std::string temp1 = notation, temp2 = notation2;
            temp2.erase(0, 1);
            std::string *result = addition(temp1, temp2, sys, false);  // O(K)
            std::cout << *result << '\n';
            //notation2.erase(0, 1);
            //digitize(notation2, sys);
            //ToAdditionalCode(notation2, sys);
            //std::string *result2 = addition(notation, notation2, sys, true);
            std::string *result4 = substraction(temp1, temp2, sys);  // O(K)
            std::cout << *result4 << '\n';
        }else if(notation[0] == '-'){
            std::string temp1 = notation, temp2 = notation2;
            temp1.erase(0, 1);
            std::string *result = addition(temp1, temp2, sys, false);  // O(K)
            std::cout << "Разность двух чисел:\n";
            std::cout << "-" << *result << '\n';
            std::cout << "Сумма двух чисел: \n";
            std::cout << *addition(notation2, notation, sys, true);  // O(K)
        }
        else {*/
            std::cout << "Сумма двух чисел:\n";
            std::string temp1 = notation, temp2 = notation2;
            std::string *result3 = addition(notation, notation2, sys, true);  // O(K)
            std::cout << *result3 << '\n';
            std::cout << "Разность двух чисел:\n";
            temp2.insert(0, 1, '-');
            std::cout << *addition(temp1, temp2, sys, true);  // O(K)
        //}
        if(RestartProgram())
        {
            break;
        }
    }
    system("pause");
    return 0;
}
