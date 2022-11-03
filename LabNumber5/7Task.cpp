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
    long long a = 1, n, m;
    std::cin >> a >> n >> m;
    m = pow(10, m);
    std::cout << fast_pow(a, n, m);
}