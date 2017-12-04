#ifndef XPLATFORM_H
#define XPLATFORM_H

/*!
 * \file XPlatform.h
 * \brief Cross-platform conio.h
 * \author tberdy
 * \version 1.0
 */

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

#if defined WINDOWS
    #define COLOR_BLACK 0
    #define COLOR_RED 12
    #define COLOR_GREEN 2
    #define COLOR_JAUNE 14
    #define COLOR_BLUE 9
    #define COLOR_MAGENTA 13
    #define COLOR_CYAN 11
    #define COLOR_WHITE 15
#elif defined UNIX
    #define COLOR_BLACK 30
    #define COLOR_RED 31
    #define COLOR_GREEN 32
    #define COLOR_JAUNE 33
    #define COLOR_BLUE 34
    #define COLOR_MAGENTA 35
    #define COLOR_CYAN 36
    #define COLOR_WHITE 37
#endif

    /*!
     *  \brief getch() equivalent function
     *
     *  Retrieve a single char from buffer
     *
     *  \return The first char entered by user
     */
    char xplt_getch();

    /*!
     *  \brief Clear screen
     *
     *  Clear screen
     */
    void xplt_clrscr();

    /*!
     *  \brief Move the cursor's position
     *
     *  Move the cursor's position
     *
     *  \param lig: the new line of the cursor (from 0)
     *  \param col: the new column of the cursor (from 0)
     */
    void xplt_gotoligcol(int lig, int col);

    /*!
     *  \brief Change the prompt colors
     *
     *  Change the prompt colors (text & foreground)
     *
     *  \param text: the color of the text
     *  \param foreground: the color of the foreground
     */
    void xplt_set_color(int text, int foreground);


#ifdef __cplusplus
}
#endif

#endif /* XPLATFORM_H */

