#include <iostream>

char* Copy(char* Destination, const char* Source)
{
    size_t size = 0;
    delete Destination;
    while(Source[size] != '\0')
    {
        ++size;
    }
    Destination[size] = '\0';
    while(size != 0)
    {
        Destination[size - 1] = Source[size - 1];
        --size;
    }
    return Destination;
}

int Compare(const char* Str1, const char* Str2)
{
    for(int i = 0; Str1[i] != '\0' && Str2[i] != '\0'; ++i)
    {
        if(Str1[i] > Str2[i])
        {
            return 1;
        }else if(Str1[i] < Str2[i])
        {
            return -1;
        }else if(Str1[i] == Str2[i] && Str1[i + 1] != '\0' && Str2[i + 1] != '\0')
        {
            continue;
        }else if(Str1[i + 1] == '\0' && Str2[i + 1] != '\0'){
            return -1;
        }
        else if(Str2[i + 1] == '\0' && Str1[i + 1] != '\0'){
            return 1;
        }
    }
    return 0;
}

void Concat(char* Destination, const char* Source)
{
    size_t DestinationSize = 0;
    while(Destination[DestinationSize] != '\0')
    {
        ++DestinationSize;
    }
    size_t SourceSize = 0;
    while(Source[SourceSize] != '\0')
    {
        ++SourceSize;
    }
    Destination[SourceSize + DestinationSize] = '\0';
    while(SourceSize != 0)
    {
        Destination[DestinationSize + SourceSize - 1] = Source[SourceSize - 1];
        --SourceSize;
    }
}

int main()
{
    char* a = new char[]{"bboba"};
    char* b = new char[]{"bbob"};
    std::cout << Compare(a,b);
    Copy(b, a);
    Concat(a, b);
    std::cout << a;
}