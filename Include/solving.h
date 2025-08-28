/**
 * @file solving.h
 * @brief solves a quadratic equation
 */

#ifndef SOLVING_H_
#define SOLVING_H_

#include <assert.h>
#include <math.h>
#include <my_assert.h>

/**
 * @brief permissible error in comparing double numbers
 */
const double EPS = 1e-6; 

/**
 * @brief reate names for number of answers
 */
enum RootsCount
{
    ONE_ROOT,
    TWO_ROOTS,
    INFINITY_ROOTS,
    ZERO_ROOTS
};
/**
 * @brief contain coefficents of quadratic equation
 */
struct Equation{
    double a;
    double b;
    double c;
};  

/**
 * @brief contain answer
 */
struct AnsEquation{
    RootsCount num_valid_ans;
    double ans1;
    double ans2;
};

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

#endif