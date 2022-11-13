#include <iostream>
#include <cmath>

long long S(long long n)
{
    if(n == 1)
        return 1;
    if(n == 0)
        return 0;
    if(n % 2 == 0)
        return S(n + 1) - (n + 1);
    return powl(((n / 2) + 1), 2) + S(n - ((n / 2) + 1));
}

int main() {
    long long n, k;
    std::cin >> k;
    while(k > 0)
    {
        std::cin >> n;
        std::cout << S(n) << '\n';
        --k;
    }
    return 0;
}