#include <iostream>
#include <string>
#include <windows.h>

struct SportPlayer{
    std::string fullname;
    std::string country;
    int gameNumber;
    int age;
    int weight;
    int height;
};

SportPlayer* FillStruct(int &size)
{
    printf("Выберите опцию заполнения массива структур:\n"
                 "1) Ввод размера массива структур\n"
                 "2) Ввод структур, пока не появится структура с заданным признаком\n");
    int n = 0;
    scanf("%i", &n);
    char* fix = new char[1];
    scanf("%*1[\n]", fix);
    switch (n) {
        case 1: {
            int f = 0;
            printf("Введите количество элементов массива структур\n");
            scanf("%i", &f);
            size = f;
            char *fix = new char[1];
            scanf("%*1[\n]", fix);
            auto structures = new SportPlayer[f];
            for (int i = 0; i < f; ++i) {
                printf("Введите игровой номер игрока\n");
                scanf("%i", &structures[i].gameNumber);
                scanf("%*1[\n]", fix);
                printf("Введите возраст игрока\n");
                scanf("%i", &structures[i].age);
                scanf("%*1[\n]", fix);
                structures[i].fullname.resize(100);
                printf("Введите полное имя игрока\n");
                scanf("%[^\n]%*c", structures[i].fullname.c_str());
                printf("Введите вес игрока\n");
                scanf("%*1[\n]", fix);
                scanf("%i", &structures[i].weight);
                printf("Введите рост игрока\n");
                scanf("%i", &structures[i].height);
                scanf("%*1[\n]", fix);
                structures[i].country.resize(100);
                printf("Введите страну игрока\n");
                scanf("%[^\n]%*c", structures[i].country.c_str());
            }
            return structures;
            break;
        }
        case 2: {
            printf("Выберите поля структуры, значения которых хотите задать заранее:\n"
                   "1) Игровой номер\n"
                   "2) Возраст\n"
                   "3) Полное имя\n"
                   "4) Вес\n"
                   "5) Рост\n"
                   "6) Страна\n");
            auto controlstruct = new std::string[6];
            size = 0;
            std::string fields;
            fields.resize(6);
            scanf("%[^\n]%*c", fields.c_str());
            int size_str = 0;
            for(auto i : fields)
            {
                if(i != 0)
                {
                    ++size_str;
                }
            }

            for(int i = 0; i < 6; ++i)
            {
                controlstruct[i] = "0";
            }
            for(auto i: fields) {
                if (i == '1') {
                    printf("Введите игровой номер игрока\n");
                    scanf("%[^\n]%*c", controlstruct[0].c_str());
                }
                else if (i == '2')
                {
                    printf("Введите возраст игрока\n");
                    scanf("%[^\n]%*c", controlstruct[1].c_str());
                }
                else if(i == '3') {
                    printf("Введите полное имя игрока\n");
                    controlstruct[2].resize(100);

                    scanf("%[^\n]%*c", controlstruct[2].c_str());
                }
                else if(i == '4'){
                    printf("Введите вес игрока\n");

                    scanf("%[^\n]%*c", controlstruct[3].c_str());
                }
                else if(i == '5'){
                    printf("Введите рост игрока\n");

                    scanf("%[^\n]%*c", controlstruct[4].c_str());
                }
                else if(i == '6'){
                    controlstruct[5].resize(100);
                    printf("Введите страну игрока\n");
                    scanf("%[^\n]%*c", controlstruct[5].c_str());
                }
            }
            auto structures = new SportPlayer[100];
            int count = 0;
            char *fix = new char[1];
            for(int i = 0; ; ++i)
            {
                printf("Введите игровой номер игрока\n");
                scanf("%i", &structures[i].gameNumber);
                scanf("%*1[\n]", fix);
                if(structures[i].gameNumber == std::stoi(controlstruct[0]))
                {
                    ++count;
                }
                printf("Введите возраст игрока\n");
                scanf("%i", &structures[i].age);
                scanf("%*1[\n]", fix);
                if(structures[i].age == std::stoi(controlstruct[1]))
                {
                    ++count;
                }
                structures[i].fullname.resize(100);
                printf("Введите полное имя игрока\n");
                scanf("%[^\n]%*c", structures[i].fullname.c_str());
                if(structures[i].fullname == controlstruct[2])
                {
                    ++count;
                }
                printf("Введите вес игрока\n");
                scanf("%i", &structures[i].weight);
                scanf("%*1[\n]", fix);
                if(structures[i].weight == std::stoi(controlstruct[3]))
                {
                    ++count;
                }
                printf("Введите рост игрока\n");
                scanf("%i", &structures[i].height);
                scanf("%*1[\n]", fix);
                if(structures[i].height == std::stoi(controlstruct[4]))
                {
                    ++count;
                }
                structures[i].country.resize(100);
                printf("Введите страну игрока\n");
                scanf("%[^\n]%*c", structures[i].country.c_str());
                if(structures[i].country == controlstruct[5])
                {
                    ++count;
                }
                ++size;
                if(count == size_str)
                {
                    break;
                }else{
                    count = 0;
                }
            }
            return structures;
            break;
        }
        default:
            return nullptr;
            break;
    }
}

void ShowStruct(SportPlayer *element)
{
    printf("Игровой номер игрока: %i\n", element->gameNumber);
    printf("Возраст игрока: %i\n", element->age);
    printf("Полное имя игрока: %s\n", element->fullname.c_str());
    printf("Вес игрока: %i\n", element->weight);
    printf("Рост игрока: %i\n", element->height);
    printf("Страна игрока: %s\n", element->country.c_str());
}

void ShowFields(SportPlayer* structure, int size)
{
    for(int i = 0; i < size; ++i) {
        printf("%i-й элемент массива: \n", i + 1);
        ShowStruct(&structure[i]);
        printf("\n \n");
    }
}

SportPlayer* AddNewElements(SportPlayer* structures, int& size)
{
    printf("Введите количество структур, которые хотите добавить: \n");
    int add_size;
    char* fix = new char[1];
    scanf("%i", &add_size);
    scanf("%*1[\n]", fix);
    SportPlayer* temp_st = new SportPlayer[size + add_size];
    for(int i = 0; i < size; ++i)
    {
        temp_st[i] = structures[i];
    }
    for(int i = size; i < size + add_size; ++i)
    {
        printf("Введите игровой номер игрока\n");
        scanf("%i", &temp_st[i].gameNumber);
        scanf("%*1[\n]", fix);
        printf("Введите возраст игрока\n");
        scanf("%i", &temp_st[i].age);
        scanf("%*1[\n]", fix);
        temp_st[i].fullname.resize(100);
        printf("Введите полное имя игрока\n");
        scanf("%[^\n]%*c", temp_st[i].fullname.c_str());
        printf("Введите вес игрока\n");
        scanf("%i", &temp_st[i].weight);
        scanf("%*1[\n]", fix);
        printf("Введите рост игрока\n");
        scanf("%i", &temp_st[i].height);
        scanf("%*1[\n]", fix);
        temp_st[i].country.resize(100);
        printf("Введите страну игрока\n");
        scanf("%[^\n]%*c", temp_st[i].country.c_str());
    }
    size += add_size;
    return temp_st;
}

SportPlayer FindElement(SportPlayer* structure, int size)
{
    char* fix = new char[1];
    printf("Поиск структур с заданным значением элемента\n");
    printf("Выберите поля структуры, значения которых хотите задать заранее:\n"
           "1) Игровой номер\n"
           "2) Возраст\n"
           "3) Полное имя\n"
           "4) Вес\n"
           "5) Рост\n"
           "6) Страна\n");
    auto controlstruct = new std::string[6];
    size = 0;
    std::string fields;
    fields.resize(6);
    scanf("%[^\n]%*c", fields.c_str());
    int size_str = 0;
    for(auto i : fields)
    {
        if(i != 0)
        {
            ++size;
        }
    }

    for(int i = 0; i < 6; ++i)
    {
        controlstruct[i] = "-10";
    }
    for(auto i: fields) {
        if (i == '1') {
            printf("Введите игровой номер игрока\n");
            scanf("%[^\n]%*c", controlstruct[0].c_str());
        }
        else if (i == '2')
        {
            printf("Введите возраст игрока\n");
            scanf("%[^\n]%*c", controlstruct[1].c_str());
        }
        else if(i == '3') {
            printf("Введите полное имя игрока\n");
            controlstruct[2].resize(100);

            scanf("%[^\n]%*c", controlstruct[2].c_str());
        }
        else if(i == '4'){
            printf("Введите вес игрока\n");

            scanf("%[^\n]%*c", controlstruct[3].c_str());
        }
        else if(i == '5'){
            printf("Введите рост игрока\n");

            scanf("%[^\n]%*c", controlstruct[4].c_str());
        }
        else if(i == '6'){
            controlstruct[5].resize(100);
            printf("Введите страну игрока\n");
            scanf("%[^\n]%*c", controlstruct[5].c_str());
        }
    }
    int count = 0;
    for(int i = 0; i < size; ++i)
    {
        if(std::stoi(controlstruct[0]) == structure[i].gameNumber)
            ++count;
        if(std::stoi(controlstruct[1]) == structure[i].age)
            ++count;
        if(controlstruct[2] == structure[i].fullname)
            ++count;
        if(std::stoi(controlstruct[3]) == structure[i].weight)
            ++count;
        if(structure[i].height == std::stoi(controlstruct[4]))
        {
            ++count;
        }
        if(structure[i].country == controlstruct[5])
        {
            ++count;
        }
        if(count == size_str){
            printf("Мы нашли этот элемент под номером: %i \n", i);
            ShowStruct(&structure[i]);
        }else{
            count = 0;
        }
    }
    printf("Структура не найдена!\n");
    return SportPlayer();
}

void DeleteOrChangeElementInArray(SportPlayer*& structures, int &size)
{
    printf("Выберите поля структуры, по значениям которых определим:\n"
           "1) Игровой номер\n"
           "2) Возраст\n"
           "3) Полное имя\n"
           "4) Вес\n"
           "5) Рост\n"
           "6) Страна\n");
    auto controlstruct = new std::string[6];
    std::string fields;
    fields.resize(6);
    scanf(" %[^\n]%*c", fields.c_str());
    int size_str = 0;
    for(auto i : fields)
    {
        if(i != 0)
        {
            ++size_str;
        }
    }

    for(int i = 0; i < 6; ++i)
    {
        controlstruct[i] = "0";
    }
    for(auto i: fields) {
        if (i == '1') {
            printf("Введите игровой номер игрока\n");
            scanf("%[^\n]%*c", controlstruct[0].c_str());
        }
        else if (i == '2')
        {
            printf("Введите возраст игрока\n");
            scanf("%[^\n]%*c", controlstruct[1].c_str());
        }
        else if(i == '3') {
            printf("Введите полное имя игрока\n");
            controlstruct[2].resize(100);

            scanf("%[^\n]%*c", controlstruct[2].c_str());
        }
        else if(i == '4'){
            printf("Введите вес игрока\n");

            scanf("%[^\n]%*c", controlstruct[3].c_str());
        }
        else if(i == '5'){
            printf("Введите рост игрока\n");

            scanf("%[^\n]%*c", controlstruct[4].c_str());
        }
        else if(i == '6'){
            controlstruct[5].resize(100);
            printf("Введите страну игрока\n");
            scanf("%[^\n]%*c", controlstruct[5].c_str());
        }
    }
    int count = 0;
    char* fix = new char[1];
    for(int i = 0; i < size ; ++i)
    {
        if(structures[i].gameNumber == std::stoi(controlstruct[0]))
        {
            ++count;
        }
        if(structures[i].age == std::stoi(controlstruct[1]))
        {
            ++count;
        }
        if(structures[i].fullname == controlstruct[2])
        {
            ++count;
        }
        if(structures[i].weight == std::stoi(controlstruct[3]))
        {
            ++count;
        }
        if(structures[i].height == std::stoi(controlstruct[4]))
        {
            ++count;
        }
        if(structures[i].country == controlstruct[5])
        {
            ++count;
        }
        if(count == size_str)
        {
            char flag;
            printf("Выберите, что хотите сделать с данным элементом массива:\n"
                   "1) Изменить\n"
                   "2) Удалить\n");
            scanf(" %c", &flag);
            scanf("%*1[\n]", fix);
            switch (flag) {
                case '1':
                {
                    printf("Выберите поля структуры, значения которых хотим изменить:\n"
                           "1) Игровой номер\n"
                           "2) Возраст\n"
                           "3) Полное имя\n"
                           "4) Вес\n"
                           "5) Рост\n"
                           "6) Страна\n");
                    auto controlstruct1 = new std::string[6];
                    std::string fields1;
                    fields1.resize(6);
                    scanf("%[^\n]%*c", fields1.c_str());
                    int size_str1 = 0;
                    for(auto it : fields1)
                    {
                        if(it != 0)
                        {
                            ++size_str1;
                        }
                    }

                    for(int f = 0; f < 6; ++f)
                    {
                        controlstruct1[f] = "-10";
                    }
                    for(auto it: fields1) {
                        if (it == '1') {
                            printf("Введите игровой номер игрока\n");
                            scanf("%[^\n]%*c", controlstruct1[0].c_str());
                        }
                        else if (it == '2')
                        {
                            printf("Введите возраст игрока\n");
                            scanf("%[^\n]%*c", controlstruct1[1].c_str());
                        }
                        else if(it == '3') {
                            printf("Введите полное имя игрока\n");
                            controlstruct1[2].resize(100);

                            scanf("%[^\n]%*c", controlstruct1[2].c_str());
                        }
                        else if(it == '4'){
                            printf("Введите вес игрока\n");

                            scanf("%[^\n]%*c", controlstruct1[3].c_str());
                        }
                        else if(it == '5'){
                            printf("Введите рост игрока\n");

                            scanf("%[^\n]%*c", controlstruct1[4].c_str());
                        }
                        else if(it == '6'){
                            controlstruct1[5].resize(100);
                            printf("Введите страну игрока\n");
                            scanf("%[^\n]%*c", controlstruct1[5].c_str());
                        }else{
                            --size_str1;
                        }
                    }
                    if(controlstruct1[0] != "-10")
                    {
                        structures[i].gameNumber = std::stoi(controlstruct1[0]);
                    }
                    if(controlstruct1[1] != "-10")
                    {
                        structures[i].age = std::stoi(controlstruct1[1]);
                    }if(controlstruct1[2] != "-10")
                    {
                        structures[i].fullname = controlstruct1[2];
                    }if(controlstruct1[3] != "-10")
                    {
                        structures[i].weight = std::stoi(controlstruct1[3]);
                    }if(controlstruct1[4] != "-10")
                    {
                        structures[i].height = std::stoi(controlstruct1[4]);
                    }if(controlstruct1[5] != "-10")
                    {
                        structures[i].country = controlstruct1[5];
                    }
                    break;
                }
                case '2':
                {
                    SportPlayer* temp_elements = new SportPlayer[size - 1];
                    for(int j = 0, counter = 0; counter < size; ++counter)
                    {
                        if(counter != i)
                        {
                            temp_elements[j] = structures[counter];
                            ++j;
                        }
                    }
                    --size;
                    structures = temp_elements;
                    break;
                }
            }
        }
    }
}

SportPlayer* SortFields(SportPlayer* structures, int size, int &new_size)
{
    auto sorted = new SportPlayer[size];
    int count = 0;
    for(int i = 0; i < size; ++i) {
        if (structures[i].age > 20) {
            sorted[count] = structures[i];
            ++count;
        }
    }
    new_size = count;
    for(int d = new_size / 2; d > 0; d /= 2){
        for(int i = d, j; i < new_size; ++i){
            SportPlayer temp = sorted[i];
            for(j = i; j >= d ; j -= d){
                if(temp.height > structures[j - d].height)
                    sorted[j] = sorted[j - d];
                else
                    break;
            }
            sorted[j] = temp;
        }
    }
    return sorted;
}

bool RestartProgram(){
    char* temp = new char[1];
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    printf("Чтобы повторить выполнение программы, нажмите");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf(" Y:\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    scanf("%*c", temp);
    char* temp2 = new char[1];
    scanf("%*1[\n]", temp2);
    if(*temp != 'y' && *temp != 'Y')
    {
        system("cls");
        return true;
    }
    return false;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    int size;
    auto players = FillStruct(size);
    while(true)
    {
        printf("Выберите функцию, которую хотите применить к заданному массиву структур:\n"
               "1) Показать элементы массива структур\n"
               "2) Добавить в массив структур новый элемент\n"
               "3) Найти в массиве структур определенную\n"
               "4) Удалить или изменить элемент из массива структур\n"
               "5) Отсортировать массив структур по убыванию роста\n");
        char choose;
        scanf(" %c", &choose);
        int new_size = 0;
        switch (choose) {
            case '1': {
                ShowFields(players, size);
                if(!RestartProgram())
                {
                    return 0;
                }
                break;
            }
            case '2': {
                AddNewElements(players, size);;
                if(!RestartProgram())
                {
                    return 0;
                }
                break;
            }
            case '3': {
                FindElement(players, size);;
                if(!RestartProgram())
                {
                    return 0;
                }
                break;
            }
            case '4': {
                DeleteOrChangeElementInArray(players, size);
                ShowFields(players, size);
                if(!RestartProgram())
                {
                    return 0;
                }
                break;
            }
            case '5': {
                auto sorted_array = SortFields(players, size, new_size);
                ShowFields(sorted_array, new_size);
                if(!RestartProgram())
                {
                    return 0;
                }
                break;
            }
            default:
            {
                printf("Введенное значение не принадлежит отрезку [1; 5], введите заново\n");
                break;
            }
        }
    }
    return 0;
}