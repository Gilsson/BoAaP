#include <iostream>
#include <string>
#include <windows.h>

#define BIT_SIZE 32

std::string& minus(std::string& code, int end) // O(K) в худшем случае
{
    if(end == 0)
    {
        code.insert(code.begin(), int('1')); // O(K)
        code.insert(code.begin() + 1, int('0')); // O(K)
        return minus(code, code.size() - 1); // O(K)
    }
    if(code[end] == int('1'))
    {
        code[end] = int('0');
        return code;
    }
    else{
        code[end] = int('1');
        return minus(code, end - 1); // O(K)
    }
}



std::string& add_to_reverse(std::string& code)
{
    if(code[0] == '1')
    {
        minus(code, code.size() - 1); // O(K)
    }
    std::cout << "\nОбратный код числа: " << code << '\n';
    return code;
}

std::string& forward_add(std::string& code)
{
    if(code[0] == '1') {
        code.erase(0, 1); // O(K)
        for (auto &it: code) { // O(K)
            it = (it == int('1')) ? int('0') : int('1');
        }

        int size = code.size();
        code[size - 1] += 1;
        if(code[size - 1] >= '2')
        {
            code[size - 1] = '0';
            code[size - 2] += 1;
            for(int i = size - 2; i > 0; --i) // O(K)
            {
                if(code[i] >= '2')
                {
                    code[i] = '0';
                    code[i - 1] += 1;
                }else
                {
                    break;
                }
            }
        }
        code.insert(0, 1, '1');
    }
    return code;
}
std::string to_binary_code(std::string& str)
{
    std::string code;
    if(str == "-0")
    {
        str.resize(BIT_SIZE, '1');
    }
    else if(str[0] == '-'){
        str.erase(0, 1); // O(K)
        int number = stoi(str); // O(K)
        while(number > 0)   // O(K)
        {
            code.push_back((number % 2) + int('0'));
            number >>= 1;
        }
        for(int i = code.size(); i < BIT_SIZE; ++i) // O(K)
            code.push_back(int('0'));
        std::reverse(code.begin(), code.end()); // O(K)
        code[0] = '1';
        forward_add(code); // O(K)
    }
    else {
        int number = stoi(str); // O(K)
        while (number > 0) { // O(K)
            code.push_back((number % 2) + int('0'));
            number >>= 1;
        }
        for (int i = code.size(); i < BIT_SIZE; ++i) // O(K)
            code.push_back(int('0'));
        std::reverse(code.begin(), code.end()); // O(K)
    }
    str = code; // O(K)
    return str;
}

void FillZero(std::string& str, int newsize)
{
    str.insert(0, newsize - str.size(), '0'); // O(K)
}

void RepairNumber(std::string& str)
{
    for(int i = str.size() - 1; i >= 1; --i)  // O(K)
    {
        if(i != 1) {
            if (str[i] >= '2') {
                str[i - 1] += 1;
                str[i] = str[i] - 2;
            }
        }else{
            if (str[i] >= '2') {
                str.insert(1, "1");
                str[i + 1] = str[i + 1] - 2;
            }
        }
    }
}

std::string sum(std::string& string1, std::string& string2)
{
    std::string result;

    //forward_add(string1);
    //forward_add(string2);
    int size = string1.size() > string2.size() ? string1.size() : string2.size();
    //FillZero(string1, size);
   //FillZero(string2, size);
    result.resize(size, '0');  // O(K)
    //result[15] = '1';
    result[result.size() - 1] += 1;
    for(int i = size - 1; i > 0 ; --i)  // O(K)
    {
        result[i] += string1[i] + string2[i] - 2 * '0';
        if(result[i] >= '2'){
            result[i] = result[i] - 2;
            result[i - 1] += 1;
        }
        //result[i - 1] += (string1[i] + string2[i] - 1) / (2 * int('0'));
    }
    //result[15] += result[0] - '0';
    //RepairNumber(result);
    if(result[0] == '1' && result[1] == '0')
    {
        result[0] = '0';
    }else{
        result.erase(0, 1);   // O(K)
    }
    //forward_add(result);
    return result;
}

void PrintInfo()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    std::cout << "Лабораторная работа номер 7:\n"
                 "Задание 2:\n"
                 "--------------------------------------------------------------------------------------------\n"
                 "\nВводить только числа.\n"
                 "Задание: произвести сложение двоичных чисел, заданных в естественной форме.\n"
                 "Сложение выполнить в обратном коде.\n"
                 "Ответ выразить в обратном коде.\n"
                 "Работу подготовил:\n";
    std::cout << "Гулис Антон\n";
    std::cout << "Чтобы запустить решение, нажмите ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    std::cout << "Enter.\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    while(true)
    {
        char *temp = new char[1]{0};
        scanf("%[^\n]%*c", temp);
        if(strlen(temp) == 0) {
            char* temp2 = new char[1];
            scanf("%*1[\n]", temp2);
            return;
        }
    }
}

bool RestartProgram(){
    char* temp = new char[1];
    std::cout << "Чтобы повторить выполнение программы, нажмите ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    std::cout << " Y(y):\n" ;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    std::cin >> temp;
    char* temp2 = new char[1];
    scanf("%*1[\n]", temp2);
    if(*temp != 'y' && *temp != 'Y')
    {
        system("cls");
        return true;
    }
    return false;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    PrintInfo();
    while(true) {
        std::string a;
        std::cout << "Введите число в естественной форме: \n";
        std::cin >> a;
        std::string b = to_binary_code(a); // O(logN)
        add_to_reverse(b); // O(1) в лучшем случае, O(K) - в худшем
        //std::cout << "\n Обратный код числа : " << b << '\n';
        std::string f;
        std::cout << "Введите второе число в естественной форме: \n";
        std::cin >> f;
        std::string c = to_binary_code(f);    // O(logN)
        add_to_reverse(c); // O(1) в лучшем случае, O(K) - в худшем
        //std::cout << "\n Обратный код числа : " << c << '\n';
        std::cout << "\nСумма двух чисел в прямом коде:" << sum(b, c) << '\n';  // O(K)
        if(RestartProgram())
        {
            break;
        }
    }
    return 0;
    //forward_add(b);
    //std::cout << b;
}