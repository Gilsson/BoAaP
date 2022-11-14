#include <iostream>
#include <string>

void EraseRepeat(std::string &Stroke)
{
    for(int i = 0; i < Stroke.size(); ++i)
    {
        if(strnicmp(&Stroke[i], &Stroke[i + 1], 1) == 0)
        {
            Stroke.erase(i + 1, 1);
            --i;
        }
    }
}

void CheckStroke(std::string &Stroke)
{
    for(int i = 0; i < Stroke.size(); ++i) {
        if (Stroke[i] == int('c') && (Stroke[i + 1] == int('e')
                                      || Stroke[i + 1] == int('i')
                                      || Stroke[i + 1] == int('y'))) {
            Stroke[i] = int('s');
        } else if (Stroke[i] == int('C') && (Stroke[i + 1] == int('e')
                                             || Stroke[i + 1] == int('i')
                                             || Stroke[i + 1] == int('y'))) {
            Stroke[i] = int('S');
        } else if (Stroke[i] == int('c')) {
            Stroke[i] = int('k');
        } else if (Stroke[i] == int('C')) {
            Stroke[i] = int('K');
        }
        if(Stroke[i] == int('q') && (Stroke[i + 1] == int('u')))
        {
            Stroke[i] = int('k');
            Stroke[i + 1] = int('v');
        }else if(Stroke[i] == int('q'))
        {
            Stroke[i] = int('k');
        }
        if(Stroke[i] == int('Q') && (Stroke[i + 1] == int('u')))
        {
            Stroke[i] = int('K');
            Stroke[i + 1] = int('v');
        }else if(Stroke[i] == int('Q'))
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
        if(Stroke[i] == int('p') && Stroke[i + 1] == int('h'))
        {
            Stroke[i] = int('f');
            Stroke.erase(i + 1, 1);
        } else if(Stroke[i] == int('P') && Stroke[i + 1] == int('h'))
        {
            Stroke[i] = int('f');
            Stroke.erase(i + 1, 1);
        }
        if((Stroke[i] == int('y') && i + 2 < Stroke.size() &&
            Stroke[i + 1] == int('o') && Stroke[i + 2] == int('u')))
        {
            Stroke[i] = int('u');
            Stroke.erase(i + 1, 2);
        }
        else if((Stroke[i] == int('Y') && i + 2 < Stroke.size() &&
            Stroke[i + 1] == int('o') && Stroke[i + 2] == int('u'))){
            Stroke[i] = int('U');
            Stroke.erase(i + 1, 2);
        }
        if(Stroke[i] == int('o') && Stroke[i+1] == int('o'))
        {
            Stroke[i] = int('u');
            Stroke.erase(i + 1, 1);
        }if(Stroke[i] == int('O') && Stroke[i+1] == int('o'))
        {
            Stroke[i] = int('U');
            Stroke.erase(i + 1, 1);
        }
        if(Stroke[i] == int('e') && Stroke[i + 1] == int('e'))
        {
            Stroke[i] = int('i');
            Stroke.erase(i + 1, 1);
        }else if(Stroke[i] == int('E') && Stroke[i + 1] == int('e'))
        {
            Stroke[i] = int('I');
            Stroke.erase(i + 1, 1);
        }
        if(Stroke[i] == int('t') && Stroke[i + 1] == int('h'))
        {
            Stroke[i] = int('z');
            Stroke.erase(i + 1, 1);
        }else if(Stroke[i] == int('T') && Stroke[i + 1] == int('h'))
        {
            Stroke[i] = int('Z');
            Stroke.erase(i + 1, 1);
        }
    }
    EraseRepeat(Stroke);
}

int main()
{
    std::string Stroke;
    char temp;
    for(int i = 0; i < 100; ++i) {
        temp = getchar();
        Stroke.push_back(temp);
        if(Stroke[i] == int('0') && Stroke[i - 1] == '\\')
        {
            Stroke.erase(i - 1, 2);
            break;
        }
    }
    CheckStroke(Stroke);
    std::cout << Stroke;
}