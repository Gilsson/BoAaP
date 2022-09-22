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
        std::cout << "\n\tPrint x: ";
        std::cin >> x;
        ans = (1 + powl(x, 2)) / 2.0 * atanl(x) - x / 2.0;
        std::cout << "\tY(x) : " << ans << '\n';
        ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            ans += powl(-1, i + 1) * powl(x, 2 * i + 1) / (4 * powl(i, 2) - 1);
        }
        std::cout << "\t S(x) : " << ans;
        --count;
    }
    return 0;
}
