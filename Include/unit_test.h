/**
 * @file unit_test.h
 * @brief check unit tests
 */

#ifndef UNITEST_H_
#define UNITEST_H_

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "solving.h"
#include "work_with_colors.h"
#include "solving.h"
#include "input.h"
#include "my_assert.h"

/**
 * @brief contains the test result, the number of correct tests and the total number of tests
 */
struct TestsRes{
    bool test_status;
    int num_of_tests;
    int test_correct;
};

/**
 * @brief checks the work of solving the equation by tests from code
 * 
 * @return have all tests been passed
 */
bool run_unit_tests_from_code();

/**
 * @brief checks the work of solving the equation by tests from file
 * 
 * @return have all tests been passed
 */
bool run_unit_tests_from_txt(const char *name);

#endif