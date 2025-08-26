#ifndef ARGS_H_
#define ARGS_H_

/**
 * @file args.h
 * @brief read arguments
 */

#include <string.h>
#include <stdio.h>

/**
 * @brief checks for argument when starting a program
 * 
 * @param [in] argc number of argument
 * @param [in] argv list of arguments
 * @param [in] arg  argument
 * 
 * @return adress of argument if it was entered
 */
char** check_argument(int argc, char **argv, const char *arg);

/**
 * @brief find the name of file wich was entered after argument
 * 
 * @param [in]  argc       number of arguments
 * @param [in]  argv       list of arguments
 * @param [in]  option_ptr adress of argument
 * 
 * @return option of argument
 */
const char* get_option_argument(int argc, char **argv, char **option_ptr);

#endif