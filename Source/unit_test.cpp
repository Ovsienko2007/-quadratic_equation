#include "unit_test.h"

/**
 * @brief checks the work of solving the equation
 * 
 * @param [in] test_num test number
 * @param [in] test     test data
 * 
 * @return have test been passed
 */
static bool check_test(int test_num, TestEquation test);

/**
 * @brief it shows that the answers are not equal
 * 
 * @param [in] test_num test number
 * @param [in] test     test data
 * @param [in] ans      program answer
 * 
 * @return string number of answers 
 */
static int print_error(int test_num, TestEquation test, AnsEquation ans);

/**
 * @brief determines whether the answer matches the correct one
 * 
 * @param [in] x answer of programm
 * @param [in] y correct answer
 * 
 * @return are the answers equal
 */
static bool check_ans(AnsEquation x, AnsEquation y);

/**
 * @brief converts the number of answers into a string
 * 
 * @param [in] num number of answers
 * 
 * @return string number of answers 
 */
static const char* rootscount_to_string(RootsCount num);

/**
 * @brief print res of unittest
 * 
 * @param [in] result result of test
 * 
 * @return 0 when output will be completed
 */
static bool print_test_res(TestsRes result);

bool run_unit_tests_from_txt(FILE * test_file){
    ADD_PATH_TO_ASSERT;
    MY_ASSERT(test_file != NULL, 1);

    assert(test_file);

    TestsRes unittest_res = {
        .test_status = true,
        .num_of_tests = 0,
        .test_correct =  0
    };

    int test_num = 0;
    bool test_status = true;

    TestEquation test;

    while (!read_test_from_file(test_file, &test, test_num)){
        test_status = check_test(test_num + 1, test);
        ASSERT_CLEAN;

        if (unittest_res.test_status){
            unittest_res.test_status = test_status;
        }

        unittest_res.test_correct += test_status;

        test_num++;
    }

    fclose(test_file);

    unittest_res.num_of_tests = test_num;

    print_test_res(unittest_res);
    ASSERT_CLEAN;

    return unittest_res.test_correct;
}

bool run_unit_tests_from_code(){
    ADD_PATH_TO_ASSERT;
    TestsRes unittest_res  = {
        .test_status = true,
        .num_of_tests = 0,
        .test_correct =  0
    };

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

    int num_of_tests = sizeof(tests) / sizeof(tests[0]);

    bool test_status  = false;

    for (int test_num = 0; test_num < num_of_tests; test_num++){
        test_status = check_test(test_num + 1, tests[test_num]);
        ASSERT_CLEAN;

        if (unittest_res.test_status){
            unittest_res.test_status = test_status;
        }
        unittest_res.test_correct += test_status;
    }

    unittest_res.num_of_tests = num_of_tests;

    print_test_res(unittest_res);
    ASSERT_CLEAN;

    return unittest_res.test_correct;
}

static bool check_test(int test_num, TestEquation test){
    ADD_PATH_TO_ASSERT;
    AnsEquation ans_i = {
        .num_valid_ans = ZERO_ROOTS, 
        .ans1 = 0, 
        .ans2 = 0
    };

    find_ans(test.equat, &ans_i);
    ASSERT_CLEAN;

    if (!check_ans(ans_i, test.ans)){
        print_error(test_num, test, ans_i);
        ASSERT_CLEAN;
        return false;
    }

    return true;
}

static int print_error(int test_num, TestEquation test, AnsEquation ans){
    ADD_PATH_TO_ASSERT;
    printf(CONSOLE_RED " Test %d was failed:" CONSOLE_RESET " %.4lf %.4lf %.4lf \n",
           test_num, test.equat.a, test.equat.b, test.equat.c);
    printf("\t" CONSOLE_GREEN "expected ans: %14s %.4lf %.4lf\n" CONSOLE_RESET,
            rootscount_to_string(test.ans.num_valid_ans), test.ans.ans1, test.ans.ans2);
    printf("\t" CONSOLE_YELLOW "received ans: %14s %.4lf %.4lf\n" CONSOLE_RESET,\
            rootscount_to_string(ans.num_valid_ans), ans.ans1, ans.ans2);
    printf("______________________________________________________________\n");
    return 0;
}

bool print_test_res(TestsRes result){
    ADD_PATH_TO_ASSERT;
    printf("Tests were complited\n Result: ");
    if (result.test_status){
        printf(CONSOLE_GREEN "\tTESTS PASSED: %d/%d\n" CONSOLE_RESET, result.test_correct, result.num_of_tests);
    }
    else{
        printf(CONSOLE_RED "\tTESTS PASSED: %d/%d\n" CONSOLE_RESET, result.test_correct, result.num_of_tests);
    }
    return 0;
}

static const char* rootscount_to_string(RootsCount num){
    ADD_PATH_TO_ASSERT;
    switch (num) {
        case ONE_ROOT:        return "ONE ROOT";
        case TWO_ROOTS:       return "TWO ROOTS";
        case INFINITY_ROOTS:  return "INFINITY ROOTS";
        case ZERO_ROOTS:      return "ZERO ROOTS";
        case ERROR:           return "ERROR";
        default:              return "ERROR";
    }
}

bool check_ans(AnsEquation x, AnsEquation y){
    ADD_PATH_TO_ASSERT;

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