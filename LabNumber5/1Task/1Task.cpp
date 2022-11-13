#include <iostream>

__declspec(dllexport) void PrintInfo();
__declspec(dllexport) void SolveTask();

int main() {
    PrintInfo();
    SolveTask();
    system("pause");
    return 0;
}
