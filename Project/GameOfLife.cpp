#include <iostream>
#include "SlotMachine.h"

int main() {
    FieldOfLife* field = FieldOfLife::NewField(105);
    std::cout << *field;
    system("pause");
    return 0;
}
