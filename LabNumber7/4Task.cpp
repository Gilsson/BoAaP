#include <iostream>
#include "4Task.h"

int main()
{
    int arabic;
    std::cin >> arabic;
    //for(int i = 49; i < 100; ++i)
    std::cout << *ConvertToRim(arabic) << '\n'; // O(N)
}