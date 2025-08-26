#ifndef UNITEST_H_
#define UNITEST_H_

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "solving.h"
#include "work_with_colors.h"
#include "structures.h"
#include "input.h"

/**
 * @brief determines whether the answer matches the correct one
 * 
 * @param [in] x answer of programm
 * @param [in] y correct answer
 * 
 * @return are the answers equal
 */
bool check_ans(AnsEquation x, AnsEquation y);

/**
 * @brief converts the number of answers into a string
 * 
 * @param [in] num number of answers
 * 
 * @return string number of answers 
 */
const char* rootscount_to_string(RootsCount num);

/**
 * @brief it shows that the answers are not equal
 * 
 * @param [in] test_num test number
 * @param [in] test     test data
 * @param [in] ans      program answer
 * 
 * @return string number of answers 
 */
int print_error(int test_num, TestEquation test, AnsEquation ans);

/**
 * @brief checks the work of solving the equation
 * 
 * @param [in] test_num test number
 * @param [in] test     test data
 * 
 * @return have test been passed
 */
bool check_test(int test_num, TestEquation test);

/**
 * @brief checks the work of solving the equation by tests from code
 * 
 * @return have all tests been passed
 */
tests_res run_unit_tests_from_code();


/**
 * @brief checks the work of solving the equation by tests from file
 * 
 * @return have all tests been passed
 */
tests_res run_unit_tests_from_txt(const char *name);

#endif