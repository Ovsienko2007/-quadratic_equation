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

    // TODO put const where possible
    if (char **option_ptr = check_argument(argc, argv, "--file-test")){
        bool is_file_present = false;

        // TODO return NULL instead of is_file_present
        const char *file_name = get_option_argument(argc, argv, option_ptr, &is_file_present);

        if (!is_file_present){
            printf(CONSOLE_RED "EROOR" CONSOLE_RESET); // TODO More detailed message
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