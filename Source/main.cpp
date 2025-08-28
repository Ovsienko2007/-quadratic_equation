#include "input.h"
#include "solving.h"
#include "output.h"
#include "unit_test.h"
#include "work_with_colors.h"
#include "args.h"
#include "my_assert.h"
//TODO Бэктрейс

int main(int argc, char *argv[]){
    path_to_assert(CREAT);
    path_to_assert(ADD, __PRETTY_FUNCTION__);
    
    if (check_argument(argc, argv, "--embedded-test")){
        return !run_unit_tests_from_code();
    }

    if (char **option_ptr = check_argument(argc, argv, "--file-test")){

        const char *file_name = get_option_argument(argc, argv, option_ptr);

        if (!file_name){
            printf(CONSOLE_RED "ERROR: WERE IS NO NAME OF FILE AFTER ARGUMENT!\n" CONSOLE_RESET);
            return 0;
        }

        FILE * test_file = fopen(file_name, "r");

        if (test_file == NULL){
            printf("There is no file with name %s", file_name);
            return 0;
        }

        return !run_unit_tests_from_txt(test_file);
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

    if (find_ans(equation, &ans)){
        printf("ERROR");
        return 1; 
    }

    minus_zero_to_zero(&ans.ans1);
    minus_zero_to_zero(&ans.ans2);

    print_ans(ans);

    return 0;
}