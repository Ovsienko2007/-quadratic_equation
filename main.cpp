#include "input.h"
#include "solving.h"
#include "output.h"
#include "unittest.h"
#include "work_with_colors.h"
#include "args.h"
#include "structures.h"

int main(int argc, char *argv[]){
    if (check_argument(argc, argv, "--embedded-test")){
        print_test_res(run_unit_tests_from_code());
        return 0;
        
    }

    if (char **option_ptr = check_argument(argc, argv, "--file-test")){
        const char *file_name = NULL;

        if (get_option_argument(argc, argv, option_ptr)){
            printf(CONSOLE_RED "ERROR: WERE IS NO NAME OF FILE AFTER ARGUMENT!" CONSOLE_RESET);
            return 0;
        }

        print_test_res(run_unit_tests_from_txt(file_name));

        return 0;
    }

    Equation equation = {};
    AnsEquation ans = {
        .num_valid_ans = ZERO_ROOTS,
        .ans1 = 0,
        .ans2 = 0
    };

    if (input_equation(&equation)){
        return 0;
    }

    find_ans(equation, &ans);

    minus_zero_to_zero(&ans.ans1);
    minus_zero_to_zero(&ans.ans2);

    print_ans(ans);

    return 0;
}