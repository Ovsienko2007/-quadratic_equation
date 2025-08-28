#include "work_with_colors.h"

const char* color_to_sescape_sequence(Color cl){
    switch (cl){
        case BLACK:     return CONSOLE_BLACK;
        case RED:       return CONSOLE_RED;
        case GREEN:     return CONSOLE_GREEN;
        case YELLOW:    return CONSOLE_YELLOW;
        case BLUE:      return CONSOLE_BLUE;
        case PIRPLE:    return CONSOLE_PIRPLE;
        case TURQUOISE: return CONSOLE_TURQUOISE;
        case WHITE:     return CONSOLE_WHITE;
        case RESET:     return CONSOLE_RESET;
        default:        return CONSOLE_RESET;
    }
}

int  print_str([[maybe_unused]] TextFormat format, [[maybe_unused]] Color cl, 
               [[maybe_unused]] Color bg, const char str[], ...) {
    va_list param;
    va_start(param, str);

#ifdef COLOR_PRINT
    printf("\033[%d;3%d;4%dm", format, cl, bg);
#endif

    vprintf(str, param); // vprintf

#ifdef COLOR_PRINT
    printf("\033[0;39m");
#endif

    va_end(param);

    return 0;
}
