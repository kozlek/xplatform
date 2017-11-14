/* 
 * File:   XPlatform.c
 * Author: Tberdy
 *
 * Created on 30 septembre 2016, 00:09
 */

#include "XPlatform.h"

#ifdef WINDOWS

HANDLE xplt_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO xplt_consoleInfo;
WORD xplt_saved_attributes;
GetConsoleScreenBufferInfo(xplt_hConsole, &xplt_consoleInfo);
xplt_saved_attributes = xplt_consoleInfo.wAttributes;

char xplt_getch() {
    return getch();
}

void xplt_clrscr() {
    system("cls");
}

void xplt_gotoligcol(int lig, int col) {
    COORD Coord;
    Coord.X = col;
    Coord.Y = lig;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);
}

void xplt_set_font_color(int color) {
    switch (color) {
        case BLACK:
            SetConsoleTextAttribute(xplt_hConsole, FOREGROUND_INTENSITY);
            break;
        case RED:
            SetConsoleTextAttribute(xplt_hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            break;
        case YELLOW:
            SetConsoleTextAttribute(xplt_hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            break;
        case GREEN:
            SetConsoleTextAttribute(xplt_hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            break;
        case BLUE:
            SetConsoleTextAttribute(xplt_hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            break;
        case WHITE:
            SetConsoleTextAttribute(xplt_hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            break;
    }
}

#else

char xplt_getch() {
    char c = 0;
    system("/bin/stty raw");
    while (c == 0) {
        c = getchar();
    }
    system("/bin/stty cooked");
    return c;
}

void xplt_clrscr() {
    system("clear");
}

void xplt_gotoligcol(int lig, int col) {
    printf("\033[%d;%dH", lig + 1, col + 1);
}

void xplt_set_font_color(int color) {
    switch (color) {
        case BLACK:
            printf("\033[%sm", "30");
            break;
        case RED:
            printf("\033[%sm", "31");
            break;
        case YELLOW:
            printf("\033[%sm", "32");
            break;
        case GREEN:
            printf("\033[%sm", "33");
            break;
        case BLUE:
            printf("\033[%sm", "34");
            break;
        case WHITE:
            printf("\033[%sm", "37");
            break;
    }
}

#endif