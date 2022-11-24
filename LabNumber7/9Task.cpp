#include <iostream>
#include <windows.h>

/*void check_barrel(int** slave, int barrels[],){
    for(int i = 0; i < number)
    {

    }
}*/

int** separate_slaves(int** slaves, int number, int day)
{
    slaves = new int*[number];
    int size = pow(3, number);
    int* unchecked_barrels = new int[size];
    for (int i = 0; i < number; ++i) {
        slaves[i] = new int[size];
    }
    for(int i = 0; i < number; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            slaves[i][j] = -1;
            unchecked_barrels[j] = 0;
        }
    }
    for(int i = 0; i < number; ++i) {
        for (int j = 0; j < size; ++j) {
            if(j % int(pow(3, i + 1)) == 0) {
                for (int k = j; k < j + pow(3, i); ++k) {
                    slaves[i][k] = k + 1;
                    unchecked_barrels[k] = 1;
                }
            }
        }
    }
    std::cout << "Unchecked barrels: \n";
    for(int i = 0; i < 243; ++i)
    {
        std::cout << unchecked_barrels[i] << " ";
    }
    std::cout << '\n';
    return slaves;
}

void check_barrels(int** slaves, int barrels[], int slaves_alive)
{
    int temp_slaves = slaves_alive;
    int* slaves_lasts = new int[slaves_alive];
    for(int i = 0; i < pow(3, slaves_alive); ++i)
    {
        if(barrels[i] == -1)
        {
            for(int j = 0; j < temp_slaves; ++j)
            {
                if(slaves[j][i] != -1)
                {
                    --slaves_alive;
                    slaves_lasts[j] = 0;
                }
                else{
                    slaves_lasts[j] = 1;
                }
            }
        }
    }
}


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int barrels[242]{};
    int num_of_slaves = 5;
    int poison = 0;
    int number_of_alive = num_of_slaves;
    int** slaves = nullptr;
    slaves = separate_slaves(slaves, num_of_slaves, 1);
    barrels[poison] = -1;
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 243; ++j)
        {
            std::cout << slaves[i][j] << " ";
        }
        std::cout << '\n';
    }
    char flag = 0b11111110;
    std::cin >> poison;
    barrels[poison] = 1;
    poison = -987654;

}