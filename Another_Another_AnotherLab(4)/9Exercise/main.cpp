#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int*** cube = nullptr;
    cube = (int***) malloc(n * sizeof(int**));
    for(int row = 0; row < n; ++row)
    {
        cube[row] = (int**) malloc(n * sizeof(int*));
        for(int column = 0; column < n; ++column)
        {
            cube[row][column] = (int*) malloc(n * sizeof(int));
        }
    }
    for(int row = 0; row < n; ++row)
    {
        for(int column = 0; column < n; ++column)
        {
            for(int layer = 0; layer < n; ++layer)
            {
                std::cin >> cube[row][column][layer];
            }
        }
    }
    int diag_num = 0;
    int diag_sum = 0;
    int max_diag_sum = 0;
    int max_diag_num = 0;
    for(int elem = 0; elem < n; ++elem)
    {
        diag_sum += cube[elem][elem][elem];
        diag_num = 1;                               // from (0,0,0) to (n-1, n-1, n-1)
    }
    if(diag_sum >= max_diag_sum)
    {
        max_diag_sum = diag_sum;
        max_diag_num = diag_num;
    }
    diag_sum = 0;
    diag_num = 0;
    for(int elem = n - 1; elem >= 0; --elem)
    {
        diag_sum += cube[elem][elem][n - 1 - elem];
        diag_num = 2;                             // from (n-1, n-1, 0) to (0, 0, n - 1)
    }
    if(diag_sum >= max_diag_sum)
    {
        max_diag_sum = diag_sum;
        max_diag_num = diag_num;
    }
    diag_sum = 0;
    diag_num = 0;
    for(int elem = n - 1; elem >= 0; --elem)
    {
        diag_sum += cube[elem][n - 1 - elem][n - 1 - elem];
        diag_num = 3;                             // from (n-1, 0, 0) to (0, n - 1, n - 1)
    }
    if(diag_sum >= max_diag_sum)
    {
        max_diag_sum = diag_sum;
        max_diag_num = diag_num;
    }
    diag_sum = 0;
    diag_num = 0;
    for(int elem = n - 1; elem >= 0; --elem)
    {
        diag_sum += cube[n - 1 - elem][elem][n - 1 - elem];
        diag_num = 4;                             // from (0, n-1, 0) to (n - 1, 0, n - 1)
    }
    if(diag_sum >= max_diag_sum)
    {
        max_diag_sum = diag_sum;
        max_diag_num = diag_num;
    }
    switch(max_diag_num)
    {
        case 1:
            std::cout << max_diag_num << '\n';
            for(int elem = 0; elem < n - 1; ++elem)
            {
                std::cout << cube[elem][elem][elem] << " ";
            }
            break;
        case 2:
            std::cout << max_diag_num << '\n';
            for(int elem = n - 1; elem >= 0; --elem)
            {
                std::cout << cube[elem][elem][n - 1 - elem] << " ";
            }
            break;
        case 3:
            std::cout << max_diag_num << '\n';
            for(int elem = n - 1; elem >= 0; --elem)
            {
                std::cout << cube[elem][n - 1 - elem][n - 1 - elem] << " ";
            }
            break;
        case 4:
            std::cout << max_diag_num << '\n';
            for(int elem = n - 1; elem >= 0; --elem)
            {
                std::cout << cube[n - 1 - elem][elem][n - 1 - elem] << " ";
            }
            break;
    }
    return 0;
}
