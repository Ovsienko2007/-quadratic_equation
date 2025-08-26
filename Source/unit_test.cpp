#include "unit_test.h"

tests_res run_unit_tests_from_txt(const char *file_name){
    FILE * test_file  = fopen(file_name, "r");

    assert(test_file);

    tests_res unittest_res = {true, 0, 0};

    int test_num = 1;
    bool test_status = true;

    TestEquation test;

    while (!read_test_from_file(test_file, &test, test_num)){
        test_status = check_test(test_num, test);

        if (unittest_res.test_status){
            unittest_res.test_status = test_status;
        }

        unittest_res.test_correct += test_status;

        test_num++;
    }

    fclose(test_file);

    unittest_res.num_of_tests = test_num - 1;

    return unittest_res;
}

tests_res run_unit_tests_from_code(){
    tests_res unittest_res = {true, 0, 0};

    TestEquation tests[] = {
        {{0,    0,    0},          {INFINITY_ROOTS,  0,  0}},
        {{1,    0,    0},          {ONE_ROOT,        0,  0}},
        {{0,    1,    0},          {ONE_ROOT,        0,  0}},
        {{1,    4,    4},          {ONE_ROOT,       -2, -2}},
        {{1,    5,   -6},          {TWO_ROOTS,      -6,  1}},
        {{1.3, -1.3, -2.6},        {TWO_ROOTS,      -1,  2}},
        {{0,    0,    1},          {ZERO_ROOTS,      0,  0}},
        {{2,    2,    2},          {ZERO_ROOTS,      0,  0}}
    };

    int num_of_tests = sizeof(tests) / sizeof (tests[0]);

    bool test_status  = false;

    for (int test_num = 0; test_num < num_of_tests; test_num++){
        test_status = check_test(test_num + 1, tests[test_num]);

        if (unittest_res.test_status){
            unittest_res.test_status = test_status;
        }
        unittest_res.test_correct += test_status;
    }

    unittest_res.num_of_tests = num_of_tests;

    return unittest_res;
}

bool check_test(int test_num, TestEquation test){
    AnsEquation ans_i = {ZERO_ROOTS, 0, 0};
    find_ans(test.equat, &ans_i);

    if (!check_ans(ans_i, test.ans)){
        print_error(test_num, test, ans_i);
        return false;
    }

    return true;
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

const char* rootscount_to_string(RootsCount num){
    switch (num) {
        case ONE_ROOT:        return "ONE ROOT";
        case TWO_ROOTS:       return "TWO ROOTS";
        case INFINITY_ROOTS:  return "INFINITY ROOTS";
        case ZERO_ROOTS:      return "ZERO ROOTS";
        default:              return "ERROR";
    }
}

bool check_ans(AnsEquation x, AnsEquation y){
    if (x.num_valid_ans == y.num_valid_ans){
        if (x.num_valid_ans == INFINITY_ROOTS || x.num_valid_ans == ZERO_ROOTS){
            return true;
        } else if (x.num_valid_ans == ONE_ROOT && is_equal(x.ans1, y.ans1)){
            return true;
        } else if(is_equal(x.ans1, y.ans1) && is_equal(x.ans2, y.ans2)){
            return true;
        }
    }

    return false;
}