#include <iostream>
#include <string>
#include <windows.h>

#define BIT_SIZE 64



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
                    code[i] = '0' + (code[i] - '0') % 2;
                    code[i - 1] += 1;
                }else
                {
                    break;
                }
            }
        }
    }
    return code;
}

std::string to_binary_code(std::string& str)
{
    std::string code;
    if(str[0] == '-'){
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
        forward_add(code);          // O(K)
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

void PrintInfo()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    std::cout << "Лабораторная работа номер 7:\n"
                 "Задание 1:\n"
                 "--------------------------------------------------------------------------------------------\n"
                 "\nВводить только числа.\n"
                 "Задание: перевести число из дополнительного кода в обратный.\n"
                 "Работу подготовил:\n";
    std::cout << "Гулис Антон\n";
    std::cout << "Чтобы запустить решение, нажмите ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    std::cout << "Enter.\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    while(true) // O(N)  - в худшем случае O(бесконечность)
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
    std::cout << "Чтобы повторить выполнение решения, нажмите ";
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
    while(true) {  // O(N)
        std::string s;
        std::cout << "\n Введите число в дополнительном коде(если число будет с \"-\" вначале, оно расценится как число "
                     "в естественной форме и переведется в дополнительный код)\n";
        std::cin >> s;
        std::cout << to_binary_code(s) << '\n'; // O(logN))
        add_to_reverse(s); // O(1), O(K) - в худшем случае(переполнение всех битов единицей)
        if(RestartProgram())
        {
            break;
        }
    }
    return 0;
}