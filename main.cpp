#include "input.h"
#include "solving.h"
#include "output.h"
#include "unittest.h"
#include "work_with_colours.h"
#include "flags.h"



int main(int argc, char *argv[])
{
    if (check_flag(argc, argv, "--test")){
        if (run_unit_tests()){
            printf("Tests were complited\nResult: OK\n\n");
        }
        return 0;
    }

    struct Equation equat = {};
    struct AnsEquation ans = {
        .num_valid_ans = ZERO_ROOTS,
        .ans1 = 0,
        .ans2 = 0
    };

    if (input_equation(&equat)){
        return 0;
    }

    find_ans(equat, &ans);

    minus_zero_to_zero(&ans.ans1);
    minus_zero_to_zero(&ans.ans2);

    print_ans(ans);

    return 0;
}