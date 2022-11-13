#include <iostream>
#include <cmath>

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

int main()
{
    while(true) {
        long long a = 1, n, m;
        std::cin >> a >> n >> m;
        if(a == 0 && n == 0 && m == 0)
            break;
        else {
            m = pow(10, m);
            n %= m * 2;
            a %= m;
            std::cout << fast_pow(a, n, m) << '\n';
        }
    }
    return 0;
}