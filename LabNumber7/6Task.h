//
// Created by Gilsson on 11/28/2022.
//

#ifndef LABNUMBER7_6TASK_H
#define LABNUMBER7_6TASK_H


//int Substract(int number, int sub)
//{
//    int point = 0x00;
//    while (sub != 0x00)
//    {
//        point = (~(number) & sub);
//        number ^= sub;
//        sub = (point << 1);
//    }
//    return number;
//}
//
//int Add(int number, int add)
//{
//    int point = 0x00;
//    while (add != 0x00)
//    {
//        point = ((number) & add);
//        number ^= add;
//        add = (point << 1);
//    }
//    return number;
//}
//
//int Multiply(int number, int mult)
//{
//    int result = 0;
//    /*Пока второй множитель не равен нулю.*/
//    while(mult != 0)
//    {
//        /*Если установлен бит в очередном разряде...*/
//        if ((mult & 1) == 1)
//        {
//            /*сложить первый множитель с самим собою.*/
//            result = Add(result, number);
//        }
//        /*Очередной сдвиг первого множителя влево ("лесенка")*/
//        number <<=  1;
//        /*Подводим очередной разряд в начало для сверки с условием оператора if()*/
//        mult >>= 1;
//    }
//    return result;
//}
//
//
//int Divide(int number, int divisor)
//{
//    int point = 0x00;
//    int mask = 0x01;
//    int temp = divisor;
//    number = number < 0 ? (Add((~number), 1)) : number;
//    divisor = divisor < 0 ? (Add((~divisor), 1)) : divisor;
//    if(number < divisor) return number;
//
//    while (number > 0 || divisor != 0)
//    {
//        if ((number >= (divisor << 0x01)) && ((divisor << 0x01) > 0))
//        {
//            divisor <<= 0x01;
//            mask <<= 0x01;
//        }
//        else
//        {
//            number = point | mask;
//            number = Substract(number, divisor);
//            divisor	= temp;
//            mask = 0x01;
//        }
//    }
//    return number;
//}

bool CheckFor151(int number) {
    bool b;
    int temp = 76, back_num = number;
    if(number & 1)
    {
        number >>= 1;
        number += temp;
    }else
        number >>= 1;
    if(back_num < number)
    {
        return 0;
    }if (back_num == number)
        return 1;
    b = CheckFor151(number);
    return b;
}

bool CheckFor79(int number) {
    bool b;
    int temp = 40, back_num = number;
    if(number & 1)
    {
        number >>= 1;
        number += temp;
    }else
        number >>= 1;
    if(back_num < number)
    {
        return 0;
    }if (back_num == number)
        return 1;
    b = CheckFor79(number);
    return b;
}

bool CheckFor3(int number) {
    bool b;
    int temp = 2, back_num = number;
    if(number & 1)
    {
        number >>= 1;
        number += temp;
    }else
        number >>= 1;
    if(back_num < number)
    {
        return 0;
    }if (back_num == number)
        return 1;
    b = CheckFor3(number);
    return b;
}
#endif //LABNUMBER7_6TASK_H
