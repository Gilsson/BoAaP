#include <iostream>
#include <string>

unsigned long long fast_pow(unsigned long long k, unsigned long long n, unsigned long long t)
{
    unsigned long long output = 1;
    for(int i = 0; n != 0; ++i)
    {
        if(n & 1)
        {
            output *= k;
            output %= t;
        }
        k *= k;
        k %= t;
        n >>= 1;
    }
    return output;
}

int find_number(const std::string& where, const std::string& founded)
{
    int find = 0;
    for(int j = 0; j < where.length(); ++j) {
        if (where[j] == founded[find]) {
            ++find;
        }
    }
    return find;
}

int main()
{
    int t;
    std::cin >> t;
    while(t != 0)
    {
        int stroke_size, modulo;
        std::cin >> stroke_size >> modulo;
        std::string suff, pref;
        std::cin >> pref >> suff;
        if(suff.length() + pref.length() == stroke_size)
        {
            std::cout << 1 << '\n';
        }else if(suff.length() + pref.length() >= stroke_size)
        {
            int find1 = find_number(pref, suff);
            int find2 = find_number(suff, pref);
            int find =  find1 > find2 ? find1 : find2;
                if(find != 0)
                {
                    int size = suff.length() - find + pref.length();
                    if(size == stroke_size)
                    {
                        std::cout << 1 << '\n';
                    }else if(size > stroke_size)
                    {
                        std::cout << 0 << '\n';
                    }
                    else
                    {
                        if(suff != pref)
                        std::cout << (fast_pow(26, stroke_size - size, modulo) * 2 % modulo) % modulo << '\n';
                        else
                            std::cout << fast_pow(26, stroke_size - size, modulo) << '\n';
                    }
                } else
                {
                    std::cout << 0 << '\n';
                }
            }
        else{
            if(suff != pref)
            std::cout << (fast_pow(26, stroke_size - suff.length() - pref.length(), modulo) * 2 % modulo) % modulo << '\n';
            else
                std::cout << (fast_pow(26, stroke_size - suff.length() - pref.length(), modulo)) << '\n';
        }
        --t;
    }
}