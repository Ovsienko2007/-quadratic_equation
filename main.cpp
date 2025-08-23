#include "input.h"
#include "solving.h"
#include "output.h"
#include "unitest.h"
#include "work_with_colours.h"

int main()
{
    struct Equation equat = {};
    struct AnsEquation ans = {
        .num_valid_ans = ZERO_ROOTS,
        .ans1 = 0,
        .ans2 = 0
    };

    if (uni_test()){
        printf("Tests were complited\nResult: OK\n\n");
    }
    else{
        return 0;
    }

    if (input_equation(&equat)){
        return 0;
    }

    find_ans(equat, &ans);

    minus_zero_to_zero(&ans.ans1);
    minus_zero_to_zero(&ans.ans2);

    print_ans(ans);

    return 0;
}