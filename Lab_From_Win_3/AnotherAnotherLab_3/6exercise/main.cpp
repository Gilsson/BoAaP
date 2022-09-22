#include <iostream>
#include <iomanip>
#include <cmath>
// number on the list
// 7
int main() {
    std::cout << std::setprecision(10);
    long n = 1;
    std::cout << "\t Input a number of fragments: ";
    std::cin >> n;
    double step = 1.0 / n;
    double min = INT16_MAX;
    for(double i = 2; i <= 3.0; i += step)
    {
        double temp = 1.0 / tan(2 * i) - 1.0 / (1 + pow(i, 2));
        if(fabs(temp) < fabs(min))
        {
            min = temp;
        }
    }
    std::cout << "\t Solve of the equation: " << min;
    return 0;
}
