#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"

struct Rabotyaga{
    std::string fullname;
    std::string position;
    std::string date_hiring;
    int dep_number;
    int age;
};

int FindInFile(std::ofstream& file){
    for(int i = 0; file.cur != file.end; ++i) {
        file.seekp(i);
    }
}

void FillElements(Rabotyaga* array, int start, int end, std::fstream& in, std::ofstream& out)
{
    for(int i = start; i < end; ++i){
        out << "\nВведите номер департамента сотрудника\n";
        in >> array[i].dep_number;
        out << array[i].dep_number;
        out << "\nВведите возраст сотрудника\n";
        in >> array[i].age;
        out << array[i].age;
        out << "\nВведите полное имя сотрудника\n";
        std::getline(in, array[i].fullname);
        out << array[i].fullname;
        out << "\nВведите должность сотрудника\n";
        std::getline(in, array[i].position);
        out << array[i].position;
        out << "\nВведите дату начала работы сотрудника\n";
        out << "Введите год\n";
        char* year = new char[100];
        in >> year;
        out << year;
        out << "\nВведите месяц\n";
        char* month = new char[100];
        in >> month;
        out << month;
        out << "\nВведите день\n";
        char* day = new char[100];
        in >> day;
        out << day << '\n';
        array[i].date_hiring = year;
        array[i].date_hiring += "/";
        array[i].date_hiring += month;
        array[i].date_hiring += "/";
        array[i].date_hiring += day;
    }
}

void ShowStructure(Rabotyaga& element, std::ofstream& out)
{
    out << "Номер департамента сотрудника " << element.dep_number << '\n';
    std::cout << "Номер департамента сотрудника " << element.dep_number << '\n';
    out << "Возраст сотрудника " << element.age << '\n';
    std::cout << "Возраст сотрудника " << element.age << '\n';
    out << "Полное имя сотрудника" << element.fullname.c_str() << '\n';
    std::cout << "Полное имя сотрудника" << element.fullname.c_str() << '\n';
    out << "Должность сотрудника " << element.position.c_str() << '\n';
    std::cout << "Должность сотрудника " << element.position.c_str() << '\n';
    out << "Дата начала работы сотрудника " << element.date_hiring.c_str() << '\n';
    std::cout << "Дата начала работы сотрудника " << element.date_hiring.c_str() << '\n';
}

void ShowElements(Rabotyaga* array, int size, std::ofstream& out)
{
    std::cout << "\nЭлементы массива:\n\n";
    out << "\nЭлементы массива:\n\n";
    for(int i = 0; i < size; ++i){
        ShowStructure(array[i], out);
    }
}

int CompareDates(Rabotyaga &element1, Rabotyaga &element2){
    int pos1 = element1.date_hiring.find('/');
    std::string temp1;
    for(int i = 0; i < pos1; ++i)
    {
        temp1 += element1.date_hiring[i];
    }
    int pos2 = element2.date_hiring.find('/');
    std::string temp2;
    for(int i = 0; i < pos2; ++i)
    {
        temp2 += element2.date_hiring[i];
    }
    if(temp1 > temp2)
    {
        return 1;
    }else if(temp1 < temp2)
    {
        return -1;
    }else{
        int prev_pos1 = pos1 + 1;
        pos1 = element1.date_hiring.find('/', pos1 + 1);
        std::string temp1;
        for(int i = prev_pos1; i < pos1; ++i)
        {
            temp1 += element1.date_hiring[i];
        }
        int prev_pos2 = pos2 + 1;
        pos2 = element2.date_hiring.find('/', pos2 + 1);
        std::string temp2;
        for(int i = prev_pos2; i < pos2; ++i)
        {
            temp2 += element2.date_hiring[i];
        }
        if(temp1 > temp2)
            return 1;
        else if(temp1 < temp2)
            return -1;
        else{
            prev_pos1 = pos1 + 1;
            pos1 = element1.date_hiring.size();
            std::string temp1;
            for(int i = prev_pos1; i < pos1; ++i)
            {
                temp1 += element1.date_hiring[i];
            }
            prev_pos2 = pos2 + 1;
            pos2 = element2.date_hiring.size();
            std::string temp2;
            for(int i = prev_pos2; i < pos2; ++i)
            {
                temp2 += element2.date_hiring[i];
            }
            if(temp1 > temp2){
                return 1;
            }else if(temp1 < temp2)
                return -1;
            else
                return 0;
        }
    }
}

void SortFields(Rabotyaga* structures, int size)
{
    for(int d = size / 2; d > 0; d /= 2){
        for(int i = d, j; i < size; ++i){
            Rabotyaga temp = structures[i];
            for(j = i; j >= d ; j -= d){
                if(CompareDates(temp, structures[j - d]) == -1)
                    structures[j] = structures[j - d];
                else
                    break;
            }
            structures[j] = temp;
        }
    }
}

void ShowOutput(std::fstream& file)
{
    std::string str;
    while(!file.eof()){
        std::getline(file, str);

        std::cout << str << '\n';
    }
}

void ChangeStruct(Rabotyaga& element, std::fstream& in, std::ofstream& out)
{
    std::cout << "\nВыберите поле, которое необходимо изменить:\n"
                 "1)Номер департамента сотрудника\n"
                 "2)Возраст сотрудника\n"
                 "3)Полное имя сотрудника\n"
                 "4)Должность сотрудника\n"
                 "5)Дата начала работы сотрудника\n";
    while(true) {
        int flag;
        in >> flag;
        switch (flag) {
            case 1:
            {
                std::cout << "Текущее значение поля:" << element.dep_number <<'\n';
                out << "Текущее значение поля:" << element.dep_number <<'\n';
                std::cout << "Введите новое значение: \n";
                out << "Введите новое значение: \n";
                in >> element.dep_number;
                out << element.dep_number;
                break;
            }
            case 2:
            {
                std::cout << "Текущее значение поля:" << element.age <<'\n';
                out << "Текущее значение поля:" << element.age <<'\n';
                
            }
        }
    }
}
int main()
{
    std::fstream file;
    file.open("F:\\Projects\\BoAaP\\LabNumber8\\Input.txt", std::fstream::in | std::fstream::out);
    std::ofstream out("F:\\Projects\\BoAaP\\LabNumber8\\Output.txt");
    SetConsoleOutputCP(CP_UTF8);
    int size = 0;
    std::cout << "Введите размер массива структур:\n";
    file >> size;
    std::cout << size << '\n';
    auto array_struct = new Rabotyaga[size];
    std::cout << "Введите количество элементов, которые хотите добавить в массив\n";
    int amount;
    file >> amount;
    std::cout << amount << '\n';
    FillElements(array_struct, 0, amount, file, out);
    ShowElements(array_struct, amount, out);
    SortFields(array_struct, amount);
    ShowElements(array_struct, amount, out);
    int count = 0;
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "Выберите действие, которое хотите произвести над файлом:\n"
                 "1) Добавление записи в файл\n"
                 "2) Удаление записи из файла\n"
                 "3) Корректировка записи файла\n";
    int num;
    std::fstream commands;
    commands.open("F:\\Projects\\BoAaP\\LabNumber8\\Commands.txt", std::fstream::in);
    ShowOutput(file);
    commands >> num;
    switch (num){
        case 1:
        {
            FillElements(array_struct, amount, amount + 1, file, out);
            file.write((char*)&array_struct[amount - 1], sizeof(Rabotyaga));
            ++amount;
            break;
        }
        case 2:
        {
            std::cout << "Введите номер структуры, которую хотите удалить: \n";
            for(int i = 0; i < amount; ++i)
                {
                    std::cout << i + 1 << ") ";
                    ShowStructure(array_struct[i], out);
                    std::cout << '\n';
                }
            int element;
            std::cin >> element;
            auto* temp_structs = new Rabotyaga[size - 1];
            for(int i = 0, count = 0; i < size; ++i)
            {
                if(i != element - 1)
                {
                    temp_structs[count] = array_struct[i];
                    ++count;
                }
            }
            delete[] array_struct;
            array_struct = new Rabotyaga[--size];
            --amount;
            for(int i = 0; i < amount; ++i)
            {
                array_struct[i] = temp_structs[i];
            }
            for(int i = 0; i < amount; ++i)
            {
                std::cout << i + 1 << ") ";
                ShowStructure(array_struct[i], out);
                std::cout << '\n';
            }
            break;
        }
        case 3:
        {
            std::cout << "Введите номер структуры, которую хотите изменить: \n";
            for(int i = 0; i < amount; ++i)
            {
                std::cout << i + 1 << ") ";
                ShowStructure(array_struct[i], out);
                std::cout << '\n';
            }
            int element;
            std::cin >> element;
            ChangeStruct(array_struct[element - 1], file, out);
        }
    }
    file.close();
    out.close();
    commands.close();
    system("pause");
}