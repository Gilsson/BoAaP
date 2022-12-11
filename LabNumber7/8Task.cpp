#include "8Task.h"

int main()
{
    int num;
    std::cin >> num;
    std::cout << ToUnrealForm(ConverToThird(num)); // O(N)
    return 0;
}