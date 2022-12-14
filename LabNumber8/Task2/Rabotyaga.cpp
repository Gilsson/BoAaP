//
// Created by Gilsson on 12/14/2022.
//
#include "Rabotyaga.h"
void FillDate(Rabotyaga& element, std::istream& in, std::ostream& out)
{
    out << "Введите год\n";
    char* year = new char[100];
    in >> year;
    out << year;
    std::cout << year;
    out << "\nВведите месяц\n";
    std::cout << "\nВведите месяц\n";
    char* month = new char[100];
    in >> month;
    out << month;
    std::cout << month;
    out << "\nВведите день\n";
    char* day = new char[100];
    in >> day;
    out << day << '\n';
    std::cout << day << '\n';
    element.date_hiring = year;
    element.date_hiring += "/";
    element.date_hiring += month;
    element.date_hiring += "/";
    element.date_hiring += day;
    out << element.date_hiring << '\n';
    std::cout << element.date_hiring << '\n';
}

void FillElements(Rabotyaga* array, int start, int end, std::istream& in, std::ostream& out)
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
        FillDate(array[i], in, out);
    }
}

void ShowStructure(Rabotyaga& element, std::ostream& out)
{
    out << "Номер департамента сотрудника " << element.dep_number << '\n';
    std::cout << "Номер департамента сотрудника " << element.dep_number << '\n';
    out << "Возраст сотрудника " << element.age << '\n';
    std::cout << "Возраст сотрудника " << element.age << '\n';
    out << "Полное имя сотрудника" << element.fullname.c_str() << '\n';
    std::cout << "Полное имя сотрудника " << element.fullname.c_str() << '\n';
    out << "Должность сотрудника " << element.position.c_str() << '\n';
    std::cout << "Должность сотрудника " << element.position.c_str() << '\n';
    out << "Дата начала работы сотрудника " << element.date_hiring.c_str() << '\n';
    std::cout << "Дата начала работы сотрудника " << element.date_hiring.c_str() << '\n';
}

void ShowElements(Rabotyaga* array, int size, std::ostream& out)
{
    std::cout << "\nЭлементы массива:\n\n";
    out << "\nЭлементы массива:\n\n";
    for(int i = 0; i < size; ++i){
        ShowStructure(array[i], out);
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

void ChangeStruct(Rabotyaga& element, std::istream& in, std::ostream& out)
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
                std::cout << element.dep_number;
                break;
            }
            case 2:
            {
                std::cout << "Текущее значение поля:" << element.age <<'\n';
                out << "Текущее значение поля:" << element.age <<'\n';
                std::cout << "Введите новое значение: \n";
                out << "Введите новое значение: \n";
                in >> element.age;
                out << element.age;
                std::cout << element.age;
                break;
            }
            case 3:
            {
                std::cout << "Текущее значение поля:" << element.fullname <<'\n';
                out << "Текущее значение поля:" << element.fullname <<'\n';
                std::cout << "Введите новое значение: \n";
                out << "Введите новое значение: \n";
                in >> element.fullname;
                out << element.fullname;
                std::cout << element.fullname;
                break;
            }
            case 4:
            {
                std::cout << "Текущее значение поля:" << element.position <<'\n';
                out << "Текущее значение поля:" << element.position <<'\n';
                std::cout << "Введите новое значение: \n";
                out << "Введите новое значение: \n";
                in >> element.position;
                out << element.position;
                std::cout << element.position;
                break;
            }
            case 5: {
                std::cout << "Текущее значение поля:" << element.date_hiring << '\n';
                out << "Текущее значение поля:" << element.date_hiring << '\n';
                std::cout << "Введите новое значение: \n";
                out << "Введите новое значение: \n";
                FillDate(element, in, out);
                std::cout << element.date_hiring;
                out << element.date_hiring;
                break;
            }
            default:
            {
                std::cout << "Неправильная команда, повторите ввод\n";
                continue;
                break;
            }
        }
        return;
    }
}