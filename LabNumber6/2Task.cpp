#include <iostream>

char* FindSpaces()
{
    int buff_size = 1000;
    char* buff = new char[buff_size];
    char* output = new char[buff_size];
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

int main()
{
    std::cout << FindSpaces();
}