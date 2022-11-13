#include <windows.h>
#include <iostream>

typedef void(__cdecl *MYPROC)(void);

int main()
{
    HINSTANCE hinstLib;
    MYPROC ProcPrint, ProcSolve;

    hinstLib = LoadLibrary(TEXT("shared_lib.dll"));

    if(hinstLib != nullptr)
    {
        ProcPrint = (MYPROC) GetProcAddress(hinstLib, "PrintInfo");
        ProcSolve = (MYPROC) GetProcAddress(hinstLib, "TaskSolve");
        if(nullptr != ProcPrint && nullptr != ProcSolve)
        {
            (ProcPrint) ();
            (ProcSolve) ();
        }
     //   ProcPrint = (MYPROC)(int(LoadLibrary(TEXT("shared_lib.dll"))) + 5106);
       // (ProcPrint)();
     //   FreeLibrary(hinstLib);
       // FreeLibrary(hinstLib);
        FreeLibrary(hinstLib);
    }
    system("pause");
    return 0;
}