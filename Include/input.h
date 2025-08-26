#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "structures.h"
#include "work_with_colors.h"

/**
 * @brief clean buffer of stream
 * 
 * @param [in] stream stream
 * 
 * @return has the input in the stream ended
*/
int clean_buffer(FILE *stream);

/**
 * @brief check is number not inf or NaN
 * 
 * @param [in] x number
 * 
 * @return is double not inf or NaN
*/
bool check_not_inf_nan(double x);

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

/**
 * @brief Transform str to RootsCount
 * 
 * @param [in]  num        str
 * @param [out] not_count  became true if num is not RootsCount
 * 
 * @return result of Transformation
*/
RootsCount string_to_rootscount(const char *num, bool *not_count);

#endif