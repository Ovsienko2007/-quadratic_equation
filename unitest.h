#ifndef UNITEST_H_
#define UNITEST_H_

#include <stdio.h>
#include "solving.h"

struct TestEquation{
    Equation equat; 
    AnsEquation ans;
};

bool Check_ans(AnsEquation x, AnsEquation y);
const char* rootscount_to_string(RootsCount num);
int print_error(int test_num, TestEquation test, AnsEquation ans);

bool uni_test();

#endif