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

#define ADD_PATH_TO_ASSERT push_func(__FUNCTION__)
#define POP_ASSERT         stack_pop()
#define ASSERT_CLEAN       clean_stack(__FUNCTION__)
#define PRINT_PATH         print_stack()

const size_t size_path = sizeof(const char **);

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
    unsigned int size;
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
 * @brief delite the last elem of path
 * 
 * @param [in] stack    path to assert
 * 
 * @return 0
 */
int stack_pop();
//TODO documentation
int clean_stack(const char *func);

/**
 * @brief add name of function in stack
 * 
 * @param [in] stack  path to assert
 * @param [in] str     new file
 * 
 * @return 0
 */
int push_func(const char* str);

/**
 * @brief print path to assert
 * 
 * @param [in] stack    path to asxsert
 * 
 * @return 0
 */
int print_stack();

#endif