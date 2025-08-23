#include "output.h"

int print_ans(AnsEquation ans)
{
    switch (ans.num_valid_ans){
        case ZERO_ROOTS:
            printf("The sequation has %sno roots%s\n", GREEN, RESET);
            break;

        case ONE_ROOT:
            printf("There is 1 root:\n  ans = %s %0.3lf %s\n", GREEN, ans.ans1, RESET);
            break;
            
        case TWO_ROOTS:
            // TODO split into 2 lines
            printf("There are 2 roots:\n  ans1 = %s %0.4lf %s \n  ans1 = %s %0.4lf %s\n",
                   GREEN, ans.ans1, RESET, GREEN, ans.ans2, RESET);
            break;

        case INFINITY_ROOTS:
            printf("%sInfinite%s number of roots\n", GREEN, RESET);
            break;

        default:
            printf("%sError%s\n", RED, RESET);
            break;
    }
    return 0;
}

/*
int colour_to_str(Colour col){
    int grn = 32;
    int red = 31;
    int res = 0;
    switch (col){
        case GREEN:
            return 32;
        case RED:
            return 31;
        case RESET:
            return 0;
    }
}
*/