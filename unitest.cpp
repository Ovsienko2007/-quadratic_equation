#include "unitest.h"

bool uni_test(){
    int num_of_tests = 8;
    int i = 0;
    int q = true;

    TestEquation tests[10] = {
        {{0, 0, 0},          {INFINITY_ROOTS, 0, 0}},
        {{1, 0, 0},          {ONE_ROOT, 0, 0}},
        {{0, 1, 0},          {ONE_ROOT, 0, 0}},
        {{1, 4, 4},          {ONE_ROOT, -2, -2}},
        {{1, 5, -6},         {TWO_ROOTS,-6, 1}},
        {{1.3, -1.3, -2.6},  {TWO_ROOTS, -1, 2}},
        {{0, 0, 1},          {ZERO_ROOTS, 0, 0}},
        {{2, 2, 2},          {ZERO_ROOTS, 0, 0}}
    };

    for (i = 0; i < num_of_tests; i++){

        AnsEquation ans_i = {ZERO_ROOTS, 0, 0};
        find_ans(tests[i].equat, &ans_i);

        if (!Check_ans(ans_i, tests[i].ans)){
            printf("Test %d: %lf %lf %lf \n", i, tests[i].equat.a, tests[i].equat.b, tests[i].equat.c);
            printf("\texpected ans: %s %lf %lf\n", 
                   rootscount_to_string(tests[i].ans.num_valid_ans), tests[i].ans.ans1, tests[i].ans.ans2);
            printf("\treceived ans: %s %lf %lf\n",\
                 rootscount_to_string(ans_i.num_valid_ans), ans_i.ans1, ans_i.ans2);

            q = false;
        }

    }

    return q;

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