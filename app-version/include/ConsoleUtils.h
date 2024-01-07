

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
    #define OS_WINDOWS
#elif defined(__linux__) || defined(__linux) || defined(linux) || defined(__gnu_linux__)
    #define OS_LINUX
#elif defined(__APPLE__) || defined(__MACH__)
    #define OS_MAC
#else
    #define OS_UNKNOWN
#endif

#pragma once

#include <iostream>
#include <string>

#ifdef OS_WINDOWS
    #include <windows.h>
#endif

namespace ConsoleUtils
{
    #ifdef OS_WINDOWS
        static const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        static const int WHITE = 7;
	    static const int RED = 12;
	    static const int YELLOW = 6;
	    static const int GREEN = 10;
	    static const int CYAN = 11;
	    static const int BLUE = 3;
	    static const int MAGENTA = 13;

    #else
        static const int WHITE = 37;
	    static const int RED = 31;
	    static const int YELLOW = 33;
	    static const int GREEN = 32;
	    static const int CYAN = 36;
	    static const int BLUE = 34;
	    static const int MAGENTA = 35;
    #endif

        static const int NO_COLOR = -1;

    static int currentColor = -1;

    void Clear();
    void SetColor(int color);
    int GetColor();
    void SetItalic();
    void SetUnderline();
    void ResetStyle();
}
