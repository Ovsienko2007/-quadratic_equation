/**
 * @file output.h
 * @brief outputs the answer to the equation and the test results to the console
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <stdio.h>

#include "solving.h"
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
bool print_ans(struct AnsEquation ans);

#endif 