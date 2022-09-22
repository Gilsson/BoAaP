#include <iostream>
#include <cmath>

long int fact(long int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int main() {
    std::cout << "Print x: ";
    long double x;
    std::cin >> x;
    long double a, b, c, min, sum = 0;
    for(int i = 0; i < 20; ++i)
    {
        sum += static_cast<long double>(pow(-1, i) * powl(x, 2 * i + 1) / fact(2 * i + 1));
    }
    a = sum;
    sum = 0;
    for(int i = 0; i < 20; ++i)
    {
        sum += static_cast<long double>(pow(-1, i) * powl(x, 2 * i) / fact(2 * i));
    }
    b = sum;
    sum = 0;
    for(int i = 1; i < 1000000; ++i)
    {
        sum += static_cast<long double>(pow(-1, i + 1)  * powl((fabsl(x) - 1), i) / i);
    }
    c = sum;
    a < b ? (a < c ? min = a : min = c) : (b < c ? min = b : min = c);
    std::cout << min;
    return 0;
}
