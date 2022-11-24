#include <iostream>
#include <windows.h>

char* FindSpaces(char* output)
{
    int buff_size = 1000;
    char* buff = new char[buff_size];
    std::cout << "Type the text\n";
    for(int i = 0, j = 0; i < buff_size; ++i)
    {
        buff[i] = getchar();
        if(buff[i] == int(' ') || (buff[i] >= int('a') && buff[i] <= int('z')) || (buff[i] >= int('A') && buff[i] <= int('Z')))
        {
            output[j] = buff[i];
            ++j;
        }
        if(buff[i] == '\n')
        {
            output[j] = '\0';
            return output;
        }
    }
}

bool RestartProgram(){
    char* temp = new char[1];
    std::cout << "To repeat the program, type";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    std::cout << " Y:\n" ;
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
    while(true) {
        std::cout << "Exercise number 2:\n" << "Made by student of group 253502 Anton Hulis\n"
                  << "Number in the list is 7\n" << "TASK: delete from text all symbols, which\n"
                                                    "are not the spaces and letters\n";
        char* output;
        std::cout << FindSpaces(output);

        if(RestartProgram())
        {
            break;
        }
    }
}