#ifndef CONSOL_H_
#define CONSOL_H_

#include <stdio.h>
#include "my_assert.h"

#include "unit_test.h"
#include "input_output.h"

/**
 * @brief limits the length of a variable
 */
const int max_len = 101;

/**
 * @brief  creat console
 * 
 * @return 0
 */
int run_console();

/**
 * @brief starts standard execution
 * 
 * @return execution status
 */
int run_program();

/**
 * @brief start unit tests from file
 * 
 * @param [in] file_name command that needs to be complited
 * 
 * @return unit tests status
 */
int test_file(const char * file_name);

#endif