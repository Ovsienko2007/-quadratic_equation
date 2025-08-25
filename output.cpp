#include "output.h"

error print_ans(AnsEquation ans){
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

        default:
            print_str(BOLD, RED,  YELLOW, "ERROR");
            break;
    }
    
    return 0;
}

error print_test_res(tests_res result){
    printf("Tests were complited\n Result: ");
    if (result.test_status){
        printf(CONSOLE_GREEN "\tTESTS PASSED: %d/%d\n" CONSOLE_RESET, result.test_correct, result.num_of_tests);
    }
    else{
        printf(CONSOLE_RED "\tTESTS PASSED: %d/%d\n" CONSOLE_RESET, result.test_correct, result.num_of_tests);
    }
    return 0;
}
