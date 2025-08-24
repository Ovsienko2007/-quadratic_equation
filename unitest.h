#ifndef UNITEST_H_
#define UNITEST_H_

#include <stdio.h>
#include "solving.h"


/**
 * @brief combines the structure of the equation coefficients and the structure of the answers
 */
struct TestEquation{
    Equation equat; 
    AnsEquation ans;
};

/**
 * @brief determines whether the answer matches the correct one
 * 
 * @param [in] x answer of programm
 * @param [in] y correct answer
 * 
 * @return are the answers equal
 */
bool Check_ans(AnsEquation x, AnsEquation y);

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
 * @param [in] test test data
 * @param [in] ans program answer
 * 
 * @return string number of answers 
 */
int print_error(int test_num, TestEquation test, AnsEquation ans);

/**
 * @brief checks the work of solving the equation
 * 
 * @return have all tests been passed
 */
bool uni_test();

#endif