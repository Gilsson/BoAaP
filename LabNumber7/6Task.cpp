#include <iostream>
#include "windows.h"
#include "6Task.h"


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    while(true) {
        std::cout << "Введите число:\n";
        int num = PrintNum();  // O(N)
        std::cout << "Делимость на какое число нужно проверить?\n"
                     "1) 151\n"
                     "2) 79\n"
                     "3) 3\n";
        int flag = PrintNum(true); // O(N)
        switch (flag) {
            case 1:{
                if(CheckFor151(num)){ // log(N)
                    std::cout << "Число делится на 151\n";
                }else{
                    std::cout << "Число не делится на 151\n";
                }
                break;
            }
            case 2:
            {
                if(CheckFor79(num)){ // log(N)
                    std::cout << "Число делится на 79\n";
                }else{
                    std::cout << "Число не делится на 79\n";
                }
                break;
            }
            case 3:
            {
                if(CheckFor3(num)){ // log(N)
                    std::cout << "Число делится на 3\n";
                }else{
                    std::cout << "Число не делится на 3\n";
                }
                break;
            }
            default:
            {
                std::cout << "Неправильный ввод\n";
                break;
            }
        }
        if(RestartProgram())
        {
            break;
        }
    }
}