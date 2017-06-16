#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    /* This is to avoid opening a window */
    MSG Msg;
    while (GetMessage(&Msg, NULL, 0, 0))
    {
       TranslateMessage(&Msg);
       DispatchMessage(&Msg);
    }
    /* This is to avoid opening a window */

    return 0;
}
