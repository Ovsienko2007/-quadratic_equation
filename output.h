#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <stdio.h>
#include "work_with_colours.h"

/**
 * @brief print answer of quadratic equation
 * 
 * @param [in] ans contains answer of quardic equation
 * 
 * @return 0 when output will be completed
 * 
 * The answer is highlighted in color
 */
int print_ans(struct AnsEquation ans);
#endif 