/* 
 * File:   XPlatform.h
 * Author: Tberdy
 *
 * Created on 30 septembre 2016, 00:09
 */

#ifndef XPLATFORM_H
#define XPLATFORM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

#if defined (_WIN32) || defined (_WIN64)
    #define WINDOWS
    #include <windows.h>
    #include <conio.h>
#elif defined (__APPLE__) || defined (__MACH__) || defined (__unix__)
    #define UNIX
    #include <unistd.h>
    #include <stdio.h>
#endif

enum COLOR {
    BLACK,
    RED,
    YELLOW,
    GREEN,
    BLUE,
    WHITE
};

char xplt_getch();
void xplt_clrscr();
void xplt_gotoligcol(int lig, int col);
void xplt_set_font_color(int color);


#ifdef __cplusplus
}
#endif

#endif /* XPLATFORM_H */

