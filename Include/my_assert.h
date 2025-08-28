#ifndef MY_ASSERT_H_
#define MY_ASSERT_H_

#include <stdio.h>
#include <string.h>

#include "work_with_colors.h"

const int str_len = 1000;
//__PRETTY_FUNCTION__
void print_assert(const char *file_name, int expect_line_num);

#define MY_ASSERT(condition, return_value)  \
if (!(condition)) {                         \
    print_assert(__FILE__, __LINE__);       \
    return return_value;                    \
}           

#endif