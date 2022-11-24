#include <windows.h>
#include <iostream>

//typedef void(*MYPROC)();

int main()
{
    //ProcPrint = (MYPROC)(int(LoadLibrary(TEXT("shared_lib.dll"))) + 5106);
    void (*ProcPrint)() = (void (*)(void))(GetProcAddress(LoadLibraryW(L"F:\\Projects\\BoAaP\\FinalShared\\cmake-build-debug\\FinalShared.dll"), "PrintInfo"));
    ProcPrint();
    void (*TaskSolve)() = (void(*)(void))(GetProcAddress(GetModuleHandleA("F:\\Projects\\BoAaP\\FinalShared\\cmake-build-debug\\FinalShared.dll"), "TaskSolve"));
    TaskSolve();
    FreeLibrary(GetModuleHandleA("F:\\Projects\\BoAaP\\FinalShared\\cmake-build-debug\\FinalShared.dll"));
    system("pause");
    return 0;
}