#include <iostream>

int main() {
    int n, digits = 1, i;
    std::cin >> n >> i;
    int temp_number = n;
    while(temp_number > 10)
    {
        digits++;
        temp_number /= 10;
    }
    int *number = new int[digits];
    for(int count = digits - 1; count >= 0; --count)
    {
        number[count] = n % 10;
        n /= 10;
    }
    for(int count = 0; count < digits; ++count)
    {
        std::cout << number[count];
    }
    std::cout << '\n' <<  number[digits - i - 1];
    delete[] number;
    return 0;
}
