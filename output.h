#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <stdio.h>

#include "structures.h"
#include "work_with_colors.h"

/**
 * @brief print answer of quadratic equation
 * 
 * @param [in] ans contains answer of quardic equation
 * 
 * @return 0 when output will be completed
 * 
 * The answer is highlighted in color
 */
error print_ans(struct AnsEquation ans);

/**
 * @brief print res of unittest
 * 
 * @param [in] result result of test
 * 
 * @return 0 when output will be completed
 */
error print_test_res(tests_res result);

#endif 