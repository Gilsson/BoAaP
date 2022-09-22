#include <cmath>
#include <iostream>

int main() {
    double A = 0, B = acos(-1) / 2, M = 20, H = (B - A) / M, y, x = A;
    for(int i = 0; x <= B; ++i)
    {
        x = A + i * H;
        y = sin(x) - cos(x);
        std::cout << "X" << i << ": " << x << "\tY" << i << ":" << y << '\n';
    }
    return 0;
}
