#ifndef SOLVING_H_
#define SOLVING_H_

#include <assert.h>
#include <math.h>

#include "structures.h"

/**
 * @brief determines if two double numbers are equal
 * 
 * @param [in] a first number
 * @param [in] b first number
 * 
 * @return true if numbers is equal false otherwise
 */
bool is_equal(double a, double b);

/**
 * @brief if the number differs from zero less than EPS then it brings it to 0
 * 
 * @param [in] a number
 * 
 * @return 0
 */
int minus_zero_to_zero(double *ans1);

/**
 * @brief permissible error in comparing double numbers
 * 
 * @param [in] equation coefficents of quadratic equation
 * @param [out] ans     answer of quadratic equation
 * 
 * @return 0
 */
int find_ans(struct Equation equation, struct AnsEquation *ans);

/**
 * @brief solves a linear equation
 * 
 * @param [in] equation coefficents of quadratic equation
 * @param [out] ans     answer of quadratic equation
 * 
 * @return 0
 */
int linear_equation(struct Equation equation, struct AnsEquation *ans);

/**
 * @brief solves a quadratic equation
 * 
 * @param [in] equation coefficents of quadratic equation
 * @param [out] ans     answer of quadratic equation
 * 
 * @return 0
 */
int quadratic_equation(struct Equation equation, struct AnsEquation *ans);

#endif