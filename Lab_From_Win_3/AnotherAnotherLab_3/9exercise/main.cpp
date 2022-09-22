#include <iostream>
#include <cmath>

int main() {
    /*
     *
        double a;
        std::cout << "Print a(" << i - 1 << "): ";
        std::cin >> a;
        int full = (int)(fabs(a));
        int part = (int) ((a - full) * precision);
     */
    std::cout << "Print n: \n";
    int n;
    std::cin >> n;
    std::cout << "Print precision of fractional part(1000, 10000, 100000): \n";
    int precision;
    std::cin >> precision;
    double sum = 0;
    for (int i = 0; i < n; ++i) {

        double a;
        std::cout << "Print a(" << i << "): ";
        std::cin >> a;
        int full = (int)(fabs(a));
        int part = (int) ((a - full) * precision);
        if (i % 2 == 0) {
            sum += (full << (i)) + (part << (i)) / double(precision);
        } else {
            sum -= (full << (i)) + (part << (i)) / double(precision);
        }
    }
    std::cout << "Sum is " << sum;
    return 0;
}
