/**
 * @file my_assert.h
 * @brief make assert
 */
#ifndef MY_ASSERT_H_
#define MY_ASSERT_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "work_with_colors.h"

/**
 * @brief commands wich we can use with stack
 */
enum COMMAND_STACK{
    CREAT,
    ADD,
    POP,
    PRINT
};

/**
 * @brief stack
 */
struct Stack{
    const char **data;
    unsigned int n;
    size_t size;
};

/**
 * @brief max string size
 */
const int str_len = 1000;

/**
 * @brief print lines in some file
 * 
 * @param [in] file_name       the name of file
 * @param [in] expect_line_num the line to be prented
 */
void print_assert(const char *file_name, const char *function_name, int expect_line_num);

/**
 * @brief print answer of quadratic equation
 * 
 * @param [in] condition    the condition which my_assert is triggered
 * @param [in] return_value value wich will be returned
 * 
 * @return return_value
 */
#define MY_ASSERT(condition, return_value)                       \
if (!(condition)) {                                              \
    print_assert(__FILE__, __PRETTY_FUNCTION__, __LINE__);       \
    return return_value;                                         \
} 

/**
 * @brief work with path to assert
 * 
 * @param [in] command         the command we execute with the path
 * @param [in] ...             elementwich we put in the path (may be unused)
 */
void path_to_assert(COMMAND_STACK command, ...);

#endif