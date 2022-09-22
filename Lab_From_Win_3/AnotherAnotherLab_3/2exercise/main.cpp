#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::cout << std::setprecision(20);
    const double eps = 1e-3;
    long double d = 0;
    int n = 0;
    long double ans = 0;
    do{
        d = pow(1 / 2.0, n) + pow(1 / 3.0, n);
        ++n;
        ans += d;
    }while(eps <= d);
    std::cout << ans;
    return 0;
}
