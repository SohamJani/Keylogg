# C++ Keylogger

This is a KeyLogger I leaned to write from Udemy course "Build an Advanced Keylogger using C++ for Ethical Hacking!"

Development Language: C++ 11
IDE: CodeBlocks 


## Description
- This is project is to demonstrate my fluency with C++. 
- The project uses different librarys in C++ to register keystrokes from the keyboard. These keystroke information is then dumped into a log file for latter view. 
- A log file is created every time 'ESC' butto is pressed. Until then all the key strokes are recorded. 
- Uses windows cpp library along with standard io libraries.  
- This was developed for and on windows desktop. It should work well on versions after windows7.   

## Compiler Setting For CodeBlocks:
added a new flag with the following Setting -> Compiler
- name: windowsAPI
- Compiler flags: -mwindows
- linker flags: -mwindows

## File Description
### Header Files
- IO.h : has functions that create a logfile.
- KeybHook : registers all the key strokes
- KeyConstants : cross references the key stroke codes to corresponding human interpretation. 
- Helper : functions to get Date & Time info for naming the logs.   

The log file will be generated in a directoory created at 'C:\Users\"User"\AppData\RoamingMicrosoft\CLR' 
