#include "output.h"

bool print_ans(AnsEquation ans){
    path_to_assert(ADD, __PRETTY_FUNCTION__);
    switch (ans.num_valid_ans){
        case ZERO_ROOTS:
            printf("The sequation has " CONSOLE_RED "no roots" CONSOLE_RESET "\n");
            break;

        case ONE_ROOT:
            printf("There is 1 root:\n"
                   "   ans = " CONSOLE_GREEN "%0.3lf" CONSOLE_RESET "\n", ans.ans1);
            break;

        case TWO_ROOTS:
            printf("There are 2 roots:\n"
                  "   ans1 = " CONSOLE_GREEN "%0.3lf" CONSOLE_RESET "\n"
                  "   ans1 = " CONSOLE_GREEN "%0.3lf" CONSOLE_RESET "\n",
                  ans.ans1, ans.ans2);
            break;

        case INFINITY_ROOTS:
            printf(CONSOLE_GREEN "Infinite" CONSOLE_RESET " number of roots\n");
            break;
        
        case ERROR:
            print_str(BOLD, RED,  YELLOW, "ERROR");
            break;
            
        default:
            print_str(BOLD, RED,  YELLOW, "ERROR");
            break;
    }

    return 0;
}
