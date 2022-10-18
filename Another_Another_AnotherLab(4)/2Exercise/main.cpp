#include <iostream>

int main() {
    const int n = 4, k = 5;
    int matrix[n][k]{};
    for(int row = 0; row < n; ++row)
    {
        for(int column = 0; column < k; ++column)
        {
            std::cin >> matrix[row][column];
        }
    }
    for(int row = 0; row < n; ++row)
    {
        for(int column = 0; column < k; ++column)
        {
            std::cout << matrix[row][column] << " ";
        }
        std::cout << std::endl;
    }
    int maxInt = -INT32_MAX;
    std::cout << std::endl;
    for(int row = n - 1; row >= 0; --row)
    {
        for(int column = n - row; column < k; ++column)
        {
            if(matrix[row][column] > maxInt){
                maxInt = matrix[row][column];
            }
        }
    }
    if(maxInt == -INT32_MAX){
        std::cout << "The largest element is undefined!\n";
    }else {
        std::cout << "The largest element: " << maxInt;
    }
    return 0;
}
