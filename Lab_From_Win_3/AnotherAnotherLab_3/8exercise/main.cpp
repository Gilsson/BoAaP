#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    for(int i = 1, degree = 1; i < n; ++i)
    {
        degree = i;
        int count = 1;
        int num = 1;
        while(degree >= 10)
        {
            degree /= 10;
            count*=10;
            num++;
        }
        int temp = 0;
        degree = i;
        for(int j = 1; j <= count; j*=10)
        {
            temp += pow((degree % 10), num);
            degree /= 10;
        }
        if(i == temp)
        {
            std::cout << i << '\n';
        }
    }

    return 0;
}
