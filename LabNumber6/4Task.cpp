#include <iostream>
#include <string>
#include <windows.h>

int strcomp(const char str1, const char str2)
{
    if(str1 != int('A') && str1 != int('E') && str1 != int('I') && str1 != int('O') && str1 != int('U')
    && str1 != int('Y') && str2 != int('A') && str2 != int('E') && str2 != int('I') && str2 != int('O') && str2 != int('U')
                           && str2 != int('Y'))
    {
        if(str1 == str2)
            return 0;
    }
    return 1;
}

void EraseRepeat(std::string &Stroke)
{
    for(int i = 0; i < Stroke.size(); ++i)
    {
        if(strcomp(toupper(Stroke[i]), toupper(Stroke[i + 1])) == 0)
        {
            Stroke.erase(i + 1, 1);
            --i;
        }
    }
}

void CheckStroke(std::string &Stroke)
{
    for(int i = 0; i < Stroke.size() - 1; ++i) {
        if ((i < Stroke.size() - 2) && Stroke[i] == int('c') && ((Stroke[i + 1] == int('e') || Stroke[i + 1] == int('E'))
                                      || (Stroke[i + 1] == int('i') || Stroke[i + 1] == int('I'))
                                      || (Stroke[i + 1] == int('y') || Stroke[i + 1] == int('Y')))) {
            Stroke[i] = int('s');
        } else if ((i < Stroke.size() - 2) && Stroke[i] == int('C') && ((Stroke[i + 1] == int('e') || Stroke[i + 1] == int('E'))
                                             || (Stroke[i + 1] == int('i') || Stroke[i + 1] == int('I'))
                                             || (Stroke[i + 1] == int('y') || Stroke[i + 1] == int('Y')))) {
            Stroke[i] = int('S');
        }
        if((i < Stroke.size() - 1) && Stroke[i] == int('q') && (Stroke[i + 1] == int('u') || Stroke[i + 1] == int('U')))
        {
            Stroke[i] = int('k');
            Stroke[i + 1] = int('v');
            ++i;
        }
        else if( (i < Stroke.size() - 1) && Stroke[i] == int('Q') && (Stroke[i + 1] == int('u') || Stroke[i + 1] == int('U')))
        {
            Stroke[i] = int('K');
            Stroke[i + 1] = int('v');
            ++i;
        }
        if((i < Stroke.size() - 1) &&Stroke[i] == int('p') && (Stroke[i + 1] == int('h') || Stroke[i + 1] == int('H')))
        {
            Stroke[i] = int('f');
            Stroke.erase(i + 1, 1);
        } else if((i < Stroke.size() - 1) &&Stroke[i] == int('P') && (Stroke[i + 1] == int('h') || Stroke[i + 1] == int('H')))
        {
            Stroke[i] = int('f');
            Stroke.erase(i + 1, 1);
        }
        if((i < Stroke.size() - 2) &&(Stroke[i] == int('y') && i + 2 < Stroke.size() &&
            (Stroke[i + 1] == int('o') || Stroke[i + 1] == int('O')) && (Stroke[i + 2] == int('u')) || Stroke[i + 2] == int('U')))
        {
            Stroke[i] = int('u');
            Stroke.erase(i + 1, 2);
        }
        else if((i < Stroke.size() - 2) &&(Stroke[i] == int('Y') && i + 2 < Stroke.size() &&
                 (Stroke[i + 1] == int('o') || Stroke[i + 1] == int('O')) && (Stroke[i + 2] == int('u')) || Stroke[i + 2] == int('U'))){
            Stroke[i] = int('U');
            Stroke.erase(i + 1, 2);
        }
        if((i < Stroke.size() - 1) &&Stroke[i] == int('o') && (Stroke[i+1] == int('o') || Stroke[i + 1] == int('O')))
        {
            Stroke[i] = int('u');
            Stroke.erase(i + 1, 1);
        }if((i < Stroke.size() - 1) &&Stroke[i] == int('O') && (Stroke[i+1] == int('o') || Stroke[i + 1] == int('O')))
        {
            Stroke[i] = int('U');
            Stroke.erase(i + 1, 1);
        }
        if((i < Stroke.size() - 1) &&Stroke[i] == int('e') && (Stroke[i + 1] == int('e') || Stroke[i + 1] == int('E')))
        {
            Stroke[i] = int('i');
            Stroke.erase(i + 1, 1);
        }else if((i < Stroke.size() - 1) &&Stroke[i] == int('E') && (Stroke[i + 1] == int('e') || Stroke[i + 1] == int('E')))
        {
            Stroke[i] = int('I');
            Stroke.erase(i + 1, 1);
        }
        if((i < Stroke.size() - 1) &&Stroke[i] == int('t') && (Stroke[i + 1] == int('h') || Stroke[i + 1] == int('H')))
        {
            Stroke[i] = int('z');
            Stroke.erase(i + 1, 1);
        }else if((i < Stroke.size() - 1) &&Stroke[i] == int('T') && (Stroke[i + 1] == int('h') || Stroke[i + 1] == int('H')))
        {
            Stroke[i] = int('Z');
            Stroke.erase(i + 1, 1);
        }
        else if(Stroke[i] == int('q'))
        {
            Stroke[i] = int('k');
        }
        else if(Stroke[i] == int('Q'))
        {
            Stroke[i] = int('K');
        }
        if(Stroke[i] == int('x'))
        {
            Stroke[i] = int('k');
            Stroke.insert(i + 1, "s");
            ++i;
        }
        else if(Stroke[i] == int('X'))
        {
            Stroke[i] = int('K');
            Stroke.insert(i + 1, "s");
            ++i;
        }
        if(Stroke[i] == int('w'))
        {
            Stroke[i] = int('v');
        }
        else if(Stroke[i] == int('W'))
        {
            Stroke[i] = int('V');
        }
        else if (Stroke[i] == int('c')) {
            Stroke[i] = int('k');
        } else if (Stroke[i] == int('C')) {
            Stroke[i] = int('K');
        }

    }
    EraseRepeat(Stroke);
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
        std::string Stroke;
        char temp;
        std::cout << "Exercise number 4:\n" << "Made by student of group 253502 Anton Hulis\n"
                  << "Number in the list is 7\n" << "TASK: language reform.\n";
        std::cout << "Type the string and end it with '\\0'.\n";
        for (int i = 0; i < 100000000; ++i) {
            temp = getchar();
            Stroke.push_back(temp);
            if (Stroke[i] == int('0') && Stroke[i - 1] == '\\') {
                Stroke.erase(i - 1, 2);
                break;
            }
            /*temp = getchar();
            Stroke.push_back(temp);*/
        }
        CheckStroke(Stroke);
        std::cout << Stroke;
        if (RestartProgram()) {
            break;
        }
    }
}