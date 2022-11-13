#include <iostream>

int orderOfNumber(int num)
{
    if(num == 0)
    {
        return num;
    }
    if(num % 10 > 0)
    {
        return num % 10;
    }
    return orderOfNumber(num / 10);
}


int orderAddition()
{
    while(true) {
        long long p, q;
        std::cin >> p >> q;
        if(p < 0 && q < 0) return 0;
        long long iter = q - p;
        long long sum = 0;
        for (; p <= q; ++p) {
            sum += orderOfNumber(p);
            //else
              //  sum += p/10;
        }
        std::cout << sum << '\n';
    }
}


int main()
{
    orderAddition();
    return 0;
}

