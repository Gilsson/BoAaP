#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::setprecision(8);
    std::cout << "Print n: ";
    int n;
    double sum = 0;
    std::cin >> n;
    // first method
    for(int i = 0; i <= n; ++i)
    {
        if(i % 2 == 0)
        {
            sum += i;
        }
    }
    std::cout << sum << '\n';
    // second method
    sum = 2;
    if(n >= 2)
    {
        n % 2 == 0 ? sum = (2 + n) / 2.0 * (n / 2.0) : sum = (2 + (n - 1)) / 2.0 * ((n - 1) / 2.0);
    }
    std::cout << sum;
    return 0;
}
