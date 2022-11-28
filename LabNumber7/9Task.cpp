#include <iostream>
#include <windows.h>
#include <iomanip>

int** separate_slaves(int** slaves, int number, int* unchecked_barrels, int day)
{
    slaves = new int*[number];
    int size;
    if(day == 1) {
        size = pow(3, number);
    }else
    {
        size = pow(2, number);
    }
    unchecked_barrels = new int[size];
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
    if(day == 1) {
        for (int i = 0; i < number; ++i) {
            for (int j = 0; j < size; ++j) {
                if (j % int(pow(3, i + 1)) == 0) {
                    for (int k = j; k < j + pow(3, i); ++k) {
                        slaves[i][k] = k + 1;
                        unchecked_barrels[k] = 1;
                    }
                }
            }
        }
    }else{
        for (int i = 0; i < number; ++i) {
            for (int j = 0; j < size; ++j) {
                if (j % int(pow(2, i + 1)) == 0) {
                    for (int k = j; k < j + pow(2, i); ++k) {
                        slaves[i][k] = k + 1;
                        unchecked_barrels[k] = 1;
                    }
                }
            }
        }
    }
    std::cout << "Unchecked barrels: \n";
    for(int i = 0; i < size; ++i)
    {
        std::cout << std::setw(4) << unchecked_barrels[i] << " ";
    }
    std::cout << '\n';
    return slaves;
}

int* check_barrels(int** slaves, const int barrels[], int& slaves_alive, int* slaves_lasts)
{
    int temp_slaves = slaves_alive;
    slaves_lasts = new int[slaves_alive];
    for(int i = 0; i < pow(3, slaves_alive); ++i)
    {
        if(barrels[i] == 1)
        {
            for(int j = 0; j < temp_slaves; ++j)
            {
                if(slaves[j][i - 1] == i)
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
    return slaves_lasts;
}

int* another_day(int** slaves, int barrels[], int* slaves_lasts, int* second_partition, int number, int number_of_alive)
{
    int size = pow(3, 5);
    int* new_array = new int[243];
    for(int f = 0; f < 243; ++f)
    {
        new_array[f] = 0;
    }
    for(int i = 0, count = 0; i < number; ++i)
    {

            for(int j = 0; j < size; ++j)
            {
                if(slaves_lasts[i] == 0) {
                    if (slaves[i][j] != -1) {
                        new_array[j]++;
                        bool flag = false;
                        for (int k = 0; k < pow(3, 5); ++k) {
                            if (second_partition[k] == slaves[i][j]) {
                                flag = true;
                                break;
                            }
                        }
                        if (!flag) {
                            second_partition[j] = slaves[i][j];
                            ++count;
                        }
                    }
                }
                else {
                    if (slaves[i][j] != -1)
                    new_array[j]--;
                }
            }
            std::cout << "Выпитые бочки на пересечении: \n";
            for(int f = 0; f < 243; ++f)
            {
                std::cout << std::setw(4) <<  new_array[f] << " ";
            }

    }
    return new_array;
}

int main()
{
    std::cout << std::setw(4);
    SetConsoleOutputCP(CP_UTF8);
    int barrels[242]{};
    int num_of_slaves = 5;
    int poison = 0;
    int number_of_alive = num_of_slaves;
    int** slaves = nullptr;
    int* unchecked_barrels = nullptr;
    slaves = separate_slaves(slaves, num_of_slaves, unchecked_barrels, 1);
    std::cin >> poison;
    barrels[poison] = 1;
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 243; ++j)
        {
            std::cout << std::setw(4) << slaves[i][j] << " ";
        }
        std::cout << '\n';
    }
    int* slaves_lasts = new int[num_of_slaves];
    slaves_lasts = check_barrels(slaves, barrels, number_of_alive, slaves_lasts);
    int* second_day = new int[(int)pow(3, 5)];
    for(int i = 0; i < pow(3, 5); ++i)
    {
        second_day[i] = 0;
    }
    second_day = another_day(slaves, barrels, slaves_lasts, second_day, num_of_slaves, number_of_alive);
    std::cout << "Second day: \n";
    for(int i = 0; i < pow(3, 5); ++i)
    {
        std::cout << std::setw(4) << second_day[i] << " ";
    }
    separate_slaves(slaves, 3, unchecked_barrels, 2);
    system("pause");
    return 0;
}