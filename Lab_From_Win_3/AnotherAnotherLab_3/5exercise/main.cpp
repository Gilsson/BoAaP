#include <iostream>
#include <cmath>
#include <iomanip>
// number on the list
// 7
int main() {
    std::cout << std::setprecision(20);
    int n, count;
    long double x, ans;
    std::cout << "\tPrint n: ";
    std::cin >> n;
    std::cout << "\n\tPrint the number of x: ";
    std::cin >> count;
    while(count != 0)
    {
        std::cout << "\n\tPrint x: [less then 1]";
        std::cin >> x;
        ans = (1 + powl(x, 2)) / 2.0 * atanl(x) - x / 2.0;
        std::cout << "\tY(x) : " << ans << '\n';
        ans = 0;
        long double temp_count = x;
        for(long long i = 0, counter = 1; i <= n; ++i, counter+=2)
        {
            temp_count *= (-1.0 * x * x * (4 * i * i - 1))/ (4 * i * i + 8 * i + 3) ;
            ans += temp_count;
        }
        std::cout << "\t S(x) : " << ans;
        --count;
    }
    return 0;
}
