#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;
    char** field = new char*[N + 2];
    for(int row = 0; row < N + 2; ++row)
    {
        field[row] = new char[M + 2];
    }
    for(int row = 0; row < N + 2; ++row)
    {
        for(int column = 0; column < M + 2; ++column)
        {
            field[row][column] = '.';
        }
    }
    for(int row = 1; row <= N; ++row)
    {
        for(int column = 1; column <= M; ++column)
        {
            std::cin >> field[row][column];
        }
    }
    for(int row = 1; row <= N; ++row)
    {
        int numOfBombsAround = 0;
        for(int column = 1; column <= M; ++column)
        {
            if(field[row][column] != '*')
            {
                for(int k = row - 1; k <= row + 1; ++k)
                {
                    for(int j = column - 1; j <= column + 1; ++j)
                    {
                        if(field[k][j] == '*')
                        {
                            numOfBombsAround++;
                        }
                    }
                }
                field[row][column] = '0' + numOfBombsAround;
            }
            numOfBombsAround = 0;
        }
    }

    for(int row = 1; row <= N; ++row)
    {
        for(int column = 1; column <= M; ++column)
        {
            std::cout << field[row][column] << " ";
        }
        std::cout << "\n";
    }
    for(int row = 0; row < N + 2; ++row)
    {
        delete[] field[row];
        field[row] = nullptr;
    }
    return 0;
}
