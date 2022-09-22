#include <iostream>

int main() {
    short i = 1;
    double ans = 0;
    while(i <= 30)
    {
        double a,b;
        if(i % 2 == 0)
        {
            a = i / 2.0;
            b = i * i * i;
        }
        else{
          a = i;
          b = i * i;
        }
        ans += (a + b);
        ++i;
  }
  std::cout << ans;
  return 0;
}
