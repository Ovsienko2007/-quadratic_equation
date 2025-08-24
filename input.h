#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <math.h>
#include <ctype.h>

#include "solving.h"
 
int buffer_cleaning();
bool check_not_inf_non(double x);

/**
 * @brief Gets coefficents for quadratic equation
 * 
 * @param [out] equation receives input data
 * 
 * @return 0 if input is completed without obtaining the required values, 1 otherwise
*/
int input_equation(Equation *equation);

#endif