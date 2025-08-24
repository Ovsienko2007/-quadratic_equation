#include "unittest.h"

bool run_unit_tests(){
    int test_num = 0;
    int unitest_res = true;


    TestEquation tests[] = {
        {{0, 0, 0},          {INFINITY_ROOTS, 0, 0}},
        {{1, 0, 0},          {ONE_ROOT, 0, 0}},
        {{0, 1, 0},          {ONE_ROOT, 0, 0}},
        {{1, 4, 4},          {ONE_ROOT, -2, -2}},
        {{1, 5, -6},         {TWO_ROOTS,-6, 1}},
        {{1.3, -1.3, -2.6},  {TWO_ROOTS, -1, 2}},
        {{0, 0, 1},          {ZERO_ROOTS, 0, 0}},
        {{2, 2, 2},          {ZERO_ROOTS, 0, 0}}
    };

    int num_of_tests = sizeof(tests) / sizeof (tests[0]);

    for (test_num = 0; test_num < num_of_tests; test_num++){
        AnsEquation ans_i = {ZERO_ROOTS, 0, 0};
        find_ans(tests[test_num].equat, &ans_i);

        if (!Check_ans(ans_i, tests[test_num].ans)){
            print_error(test_num, tests[test_num], ans_i);
            unitest_res = false;
        }
    }

    return unitest_res;
}

int print_error(int test_num, TestEquation test, AnsEquation ans){
    printf(CONSOLE_RED " Test %d was failed:" CONSOLE_RESET " %.4lf %.4lf %.4lf \n",
           test_num, test.equat.a, test.equat.b, test.equat.c);
    printf("\t" CONSOLE_GREEN "expected ans: %14s %.4lf %.4lf\n" CONSOLE_RESET, 
            rootscount_to_string(test.ans.num_valid_ans), test.ans.ans1, test.ans.ans2);
    printf("\t" CONSOLE_YELLOW "received ans: %14s %.4lf %.4lf\n" CONSOLE_RESET,\
            rootscount_to_string(ans.num_valid_ans), ans.ans1, ans.ans2);
    printf("______________________________________________________________\n");
    return 0;
}

const char*  rootscount_to_string(RootsCount num) {
    switch (num) {
        case ONE_ROOT:        return "ONE ROOT";
        case TWO_ROOTS:       return "TWO ROOTS";
        case INFINITY_ROOTS:  return "INFINITY ROOTS";
        case ZERO_ROOTS:      return "ZERO ROOTS";
        default:              return "ERROR";
    }
}

bool Check_ans(AnsEquation x, AnsEquation y){
    if (x.num_valid_ans == y.num_valid_ans &&
        is_equal(x.ans1, y.ans1) && 
        is_equal(x.ans2, y.ans2)){
            return true;
        }

    return false;
}