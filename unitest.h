#include <stdio.h>
#include "solving.h"

struct TestEquation{
    Equation equat; 
    AnsEquation ans;
};

bool Check_ans(AnsEquation x, AnsEquation y);
const char* rootscount_to_string(RootsCount num);

bool uni_test();