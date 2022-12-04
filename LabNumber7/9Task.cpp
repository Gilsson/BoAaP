#include <iostream>
#include <windows.h>
#include <iomanip>

enum Exceptions
{
    LETTER_INPUT,
    WRONG_TYPE_INPUT,
    WRONG_SIGN_POSITION,
    WRONG_POINT_POSITION,
    INCORRECT_DATA,
    EMPTY_STRING,
    WRONG_SPACE_POSITION,
    TOO_BIG_VALUE,
};

long double PrintNum(bool IsSizeInput = false)
{
    while (true) {
        int size = 0;
        long long PointIndex = -1;
        long long buff = 10132;
        long double output = 0;
        bool Sign = true;        // true = +, false = -
        bool WrongSign = false;
        char *input = new char[buff]{0};
        scanf("%[^\n]%*c", input);
        try{
            if(strlen(input) == 0) {
                throw EMPTY_STRING;
            }
            for (int i = 0; i < buff; ++i) {
                if (input[i] == 0) {
                    break;
                }
                if (input[i] == int('-') || input[i] == int('+')) {
                    if (i == 0 && input[i] == int('-')) {
                        Sign = false;
                        input[i] = '0';
                        ++size;
                        continue;
                    } else if(i == 0 && input[i] == int('+'))
                    {
                        if(Sign == false) {
                            throw WRONG_SIGN_POSITION;
                        }
                        Sign = true;
                        input[i] = '0';
                        WrongSign = true;
                        ++size;
                        continue;
                    }
                    else{
                        throw WRONG_SIGN_POSITION;
                    }
                }
                if(input[i] == int(' '))
                {
                    throw WRONG_SPACE_POSITION;
                }
                if ((input[i] < int('0') || input[i] > int('9')) && input[i] != int('.')) {
                    throw LETTER_INPUT;
                }
                if (input[i] == int('.')) {
                    for (int j = 0; j < i; ++j) {
                        if (input[j] == int('.')) {
                            throw WRONG_POINT_POSITION;
                        }
                    }
                }
                if (PointIndex == -1) {
                    for (int j = 0; j <= size; ++j) {
                        if (input[j] == int('.'))
                            PointIndex = j;
                    }
                }
                if (PointIndex != -1 && IsSizeInput) {
                    for (int j = PointIndex + 1; j <= size; ++j) {
                        if (input[j] != int('0')) {
                            throw WRONG_TYPE_INPUT;
                        }
                    }
                }
                ++size;
            }
            if (PointIndex != -1) {
                if((Sign == false || WrongSign) && size == 1){
                    throw WRONG_SIGN_POSITION;
                }
                for (long long i = PointIndex - 1; i >= 0; --i) {
                    output += (input[i] - '0') * powl(10, PointIndex - i - 1);
                }
                for (long long i = PointIndex + 1; i < size; ++i) {
                    output += (input[i] - '0') * powl(1 / 10.0, i - PointIndex);
                }
            } else {
                if((Sign == false || WrongSign) && size == 1){
                    throw WRONG_SIGN_POSITION;
                }
                for (long long i = size - 1; i >= 0; --i) {
                    output += (input[i] - '0') * powl(10, size - i - 1);
                }
            }
            if (Sign) {
                if (IsSizeInput) {
                    if (output < 1 || output > 10000) {
                        throw INCORRECT_DATA;
                    }
                }
                if (size < 300 || output < 1e300)
                    return output;
                else{
                    throw TOO_BIG_VALUE;
                }
            } else {
                if (IsSizeInput) {
                    if (-output < 1) {
                        throw INCORRECT_DATA;
                    }
                }
                if (size < 300 || output < 1e300)
                    return -output;
                else
                    throw TOO_BIG_VALUE;
            }
        }catch(Exceptions err)
        {
            char *wrongInput = new char[1000];
            char *temp = new char[1];
            switch (err){
                case (WRONG_TYPE_INPUT):
                    std::cerr << "Expected Int type.\n";
                    std::cerr << "Please, input the number one more time.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (INCORRECT_DATA):
                    std::cerr << "Incorrect size.\n";
                    std::cerr << "Please, input the number one more time.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (WRONG_POINT_POSITION):
                    std::cerr << "Incorrect point position.\n";
                    std::cerr << "Please, input the number one more time.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (WRONG_SIGN_POSITION):
                    std::cerr << "Incorrect sign position.\n";
                    std::cerr << "Please, input the number one more time.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (LETTER_INPUT):
                    std::cerr << "Expected number, not letters.\n";
                    std::cerr << "Please, input the number one more time.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case (EMPTY_STRING):
                    std::cerr << "Empty string.\n";
                    std::cerr << "Please, input the number one more time.\n";
                    scanf("%*1[\n]", temp);
                    break;
                case (WRONG_SPACE_POSITION):
                    std::cerr << "Expect only 1 number(wrong space position).\n";
                    std::cerr << "Please, input the number one more time.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                case(TOO_BIG_VALUE):
                    std::cerr << "The value is too large.\n";
                    std::cerr << "Please, input the number one more time.\n";
                    scanf("%*[\n]", wrongInput);
                    break;
                default:
                    break;
            }
            delete[] wrongInput;
        }
    }
}

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
    /*std::cout << "Unchecked barrels: \n";
    for(int i = 0; i < size; ++i)
    {
        std::cout << std::setw(4) << unchecked_barrels[i] << " ";
    }*/
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
    std::cout << "Через 24 часа осталось в живых только " << slaves_alive << ".\n";
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
                        ++new_array[j];
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

    }
    std::cout << "\nВыпитые бочки на пересечении\n";
    for(int f = 0; f < 243; ++f)
    {
        std::cout << std::setw(4) <<  new_array[f] << " ";
    }

    return new_array;
}

int second(int* merging, int slaves_alive, int* barrels)
{
    int size = pow(2, slaves_alive);
    int* last_barrels = new int[size + 1];
    for(int i = 0, count = 0; i < pow(3, 5); ++i)
    {
        if(merging[i] == 5 - slaves_alive)
        {
            last_barrels[count] = i + 1;
            ++count;
        }
    }
    std::cout << "\nНомера бочек на подозрении:\n";
    for(int i = 0; i < size; ++i)
    {
        std::cout << last_barrels[i] << " ";
    }
    std::cout << '\n';
    int** last_partition = new int*[slaves_alive];
    for(int i = 0; i < slaves_alive; ++i)
    {
        last_partition[i] = new int[size];
        for(int j = 0; j < size; ++j)
        {
            last_partition[i][j] = 0;
        }
    }
    bool drinked = false;
    for(int i = last_barrels[0], count = 0; i <= pow(3, 5) && count < slaves_alive; ++count)
    {

        for (int k = 0, barrel = 0; k < pow(2, slaves_alive), barrel < size; ++k) {
            if (k % int(pow(2, count + 1)) == 0) {
                int temp = barrel;
                for (int f = k; f < k + pow(2, count); ++f) {
                    i = last_barrels[temp];
                    ++temp;
                    last_partition[count][f] = i;
                }
                    barrel += (temp - barrel) * 2;
            }
            //i = last_barrels[barrel];
            //for (int f = k; k < j + pow(2, i); ++k)
            //i = last_barrels[j];
            //last_partition[count - 1][k] = i;
            //j += pow(2, count);
        }
        i = last_barrels[0];
    }
    for(int i = 0; i < slaves_alive; ++i)
    {
        for(int j = 0; j < pow(2, slaves_alive); ++j)
        {
            std::cout << i + 1 << ": " << last_partition[i][j] << "\n";
        }
        std::cout << '\n';
    }
    for(int i = last_barrels[0], count = 1; i < pow(3, 5) && count < pow(2, slaves_alive);)
    {
        if(barrels[i] == 1)
        {
            int death = 0;
            for(int find = 0, slave = 0; slave < slaves_alive; ++find)
            {
                if(last_partition[slave][find] == i)
                {
                    ++death;
                    ++slave;
                    find = 0;
                }
                if(find >= pow(2, slaves_alive))
                {
                    find = 0;
                    ++slave;
                }
            }
            slaves_alive -= death;
            std::cout << "\nЭто бочка под номером: " << i;
            std::cout << "\nЧтобы найти бочку, понадобилось пожертвовать: " << 5 - slaves_alive << '\n';
            drinked = true;
            break;
        }else{
            i = last_barrels[count];
            ++count;
        }
    }
    if(!drinked)
    {
        std::cout << "\nЭто бочка под номером: " << last_barrels[size - 1];
        std::cout << "\nЧтобы найти бочку, понадобилось пожертвовать: " <<  5 - slaves_alive << '\n';
    }
    return 0;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int barrels[242]{};
    int num_of_slaves = 5;
    int poison = 0;
    int number_of_alive = num_of_slaves;
    int** slaves = nullptr;
    int* unchecked_barrels = nullptr;
    slaves = separate_slaves(slaves, num_of_slaves, unchecked_barrels, 1);
    poison = PrintNum(true);
    barrels[poison] = 1;
    for(int i = 0; i < 5; ++i)
    {
        std::cout << i + 1 << " выпьет из: \n";
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
    std::cout << "На второй день: \n";
    for(int i = 0; i < pow(3, 5); ++i)
    {
        std::cout << std::setw(4) << second_day[i] << " ";
    }
    second(second_day, number_of_alive, barrels);
    //separate_slaves(slaves, 3, unchecked_barrels, 2);
    system("pause");
    return 0;
}