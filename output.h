#include <stdio.h>
#include "solving.h"

enum Colour{
    GREEN,
    RED,
    RESET
};


const char*  colour_to_str(Colour col);
int print_ans(struct AnsEquation ans);
 