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
    return num / 10;
}

int orderAddition()
{
    while(true) {
        int p, q;
        std::cin >> p >> q;
        if(p < 0 && q < 0) return 0;
        int sum = 0;
        for (int i = p; i <= q; ++i) {
            sum += orderOfNumber(i);
        }
        std::cout << sum << '\n';
    }
}

int main()
{
    orderAddition();
    return 0;
}