/**
 * @file input.h
 * @brief receives input from the console or from a file
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "solving.h"
#include "work_with_colors.h"

/**
 * @brief combines the structure of the equation coefficients and the structure of the answers
 */
struct TestEquation{
    Equation equat; 
    AnsEquation ans;
};

/**
 * @brief Gets coefficents for quadratic equation
 * 
 * @param [out] equation receives input data
 * 
 * @return 0 if input is completed without obtaining the required values, 1 otherwise
*/
bool input_equation(Equation *equation);

/**
 * @brief Gets tests from file
 * 
 * @param [in] fin   file name
 * @param [out] test test from file
 * @param [in] line  line in file
 * 
 * @return 0 if input is completed without obtaining the required values, 1 otherwise
*/
bool read_test_from_file(FILE *fin, TestEquation *test, int line);
#endif