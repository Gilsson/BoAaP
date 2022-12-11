#include "7Task.h"


int main()
{
    int num;
    std::cin >> num;
    std::string* a = new std::string[10000];
    std::string* b = new std::string[10000];
    a[0] = "0";
    int counta = 0;
    int countb = 0;
    int sizea = 1;
    int tempsize = 0;
    int sizeb = 0;
    int k = 1;
    int find = num;
    std::string *tempa = new std::string[20000];
    while(find != 0)// O(N)
    {
        for(int i = 0; i < sizea; ++i)// O(N)
        {
            b[i] = a[i];
            b[i][0] = '1';
            //std::cout << b[i] << "b\n";
            ++sizeb;
            --find;
            if(find == 0) {
                std::cout << b[i];
                break;
            }
        }
        ++k;

        for(int i = 0; i < sizea; ++i)// O(N)
        {
            a[i] = '0' + a[i];
        }
        tempsize = 0;
        for(int i = 0; i < sizea; ++i) // O(N)
        {
            auto temp = to_binary_code(a[i], k); // O(NlogN)
            if(temp[0] == '0') {
                tempa[counta] = temp;
                ++tempsize;
                ++counta;
            }
        }
        for(int i = 0; i < sizeb; ++i) // O(N)
        {
            auto temp = to_binary_code(b[i], k); // O(NlogN)
            if(temp[0] == '0') {
                tempa[counta] = temp;
                ++tempsize;
                ++counta;
            }
        }
        counta = 0;
        sizea = tempsize;
        a = tempa;
        sizeb = 0;
    }
    return 0;
}