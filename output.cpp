#include "output.h"

int print_ans(AnsEquation ans)
{
    switch (ans.num_valid_ans){
        case ZERO_ROOTS:
            printf("The sequation has %sno roots%s\n", 
                   colour_to_str(GREEN), colour_to_str(RESET));
            break;

        case ONE_ROOT:
            printf("There is 1 root:\n  ans = %s %0.3lf %s\n", 
                   colour_to_str(GREEN), ans.ans1, colour_to_str(RESET));
            break;
            
        case TWO_ROOTS:
            printf("There are 2 roots:\n  ans1 = %s %0.3lf %s \n  ans1 = %s %0.3lf %s\n",
                   colour_to_str(GREEN), ans.ans1, colour_to_str(RESET),
                   colour_to_str(GREEN), ans.ans2, colour_to_str(RESET));
            break;

        case INFINITY_ROOTS:
            printf("%sInfinite%s number of roots\n",
                   colour_to_str(GREEN), colour_to_str(RESET));
            break;

        default:
            printf("%sError%s\n", colour_to_str(RED), colour_to_str(RESET));
            break;
    }
    return 0;
}


const char*  colour_to_str(Colour col) {
    switch (col){
        case RED:             return "\033[31m";
        case GREEN:           return "\033[32m";
        case RESET:           return "\033[0m";
        default:              return "\033[0m";
    }
}
