/**
 * @file work_with_colors.h
 * @brief gives color output
 */

#ifndef work_with_colours
#define work_with_colours

#include <stdarg.h>
#include <stdio.h>

#include "stdio.h"

#ifdef COLOR_PRINT
/**
 * @brief macro to change the color of further text
 */
#define CONSOLE_BLACK      "\033[30m"
#define CONSOLE_RED        "\033[31m"
#define CONSOLE_GREEN      "\033[32m"
#define CONSOLE_YELLOW     "\033[33m"
#define CONSOLE_BLUE       "\033[34m"
#define CONSOLE_PIRPLE     "\033[35m"
#define CONSOLE_TURQUOISE  "\033[36m"
#define CONSOLE_WHITE      "\033[37m"
#define CONSOLE_RESET      "\033[39m"

#else 

#define CONSOLE_BLACK      ""
#define CONSOLE_RED        ""
#define CONSOLE_GREEN      ""
#define CONSOLE_YELLOW     ""
#define CONSOLE_BLUE       ""
#define CONSOLE_PIRPLE     ""
#define CONSOLE_TURQUOISE  ""
#define CONSOLE_WHITE      ""
#define CONSOLE_RESET      ""
#endif

/**
 * @brief reate colors to numbers
 */
enum Color{
    BLACK     = 0,
    RED       = 1,
    GREEN     = 2,
    YELLOW    = 3,
    BLUE      = 4,
    PIRPLE    = 5,
    TURQUOISE = 6,
    WHITE     = 7,
    RESET     = 9,
};

/**
 * @brief reate texts effects to numbers
 */
enum TextFormat{
    BOLD          = 1,
    FADE          = 2,
    ITALIC        = 3,
    UNDERLINED    = 4,
    BLINKING      = 5,
    STRIKETHROUGH = 9
};

/**
 * @brief converts color to string
 * 
 * @param [in] col color
 * 
 * @return result of transformation
 */
const char*  color_to_sescape_sequence(Color col);

/**
 * @brief outputs the answer with the specified effect, color, background
 * 
 * @param [in] format  text efect
 * @param [in] col     text colour
 * @param [in] back    background colour
 * @param [in] str     text
 * @param [in] param   contains numbers which will be printed
 * 
 * @return 0
 */
int  print_str(TextFormat format, Color col, Color back, const char str[], ...);

#endif