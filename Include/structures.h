/**
 * @file structures.h
 * @brief solves a quadratic equation
 */

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

typedef bool error;

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
 * @brief combines the structure of the equation coefficients and the structure of the answers
 */
struct TestEquation{
    Equation equat; 
    AnsEquation ans;
};

/**
 * @brief contains the test result, the number of correct tests and the total number of tests
 */
struct tests_res{
    bool test_status;
    int num_of_tests;
    int test_correct;
};

#endif