#include "input_output.h"
#include "solving.h"
#include "unit_test.h"
#include "work_with_colors.h"
#include "args.h"
#include "my_assert.h"
#include "consol.h"

int main(int argc, char *argv[]){
    path_to_assert(CREAT);
    path_to_assert(ADD, __PRETTY_FUNCTION__);
    
    if (check_argument(argc, argv, "--embedded-test")){
        return !run_unit_tests_from_code();
    }
    
    if (check_argument(argc, argv, "--consol")){
        return consol();
    }

    if (char **option_ptr = check_argument(argc, argv, "--file-test")){

        const char *file_name = get_option_argument(argc, argv, option_ptr);

        if (!file_name){
            printf(CONSOLE_RED "ERROR: WERE IS NO NAME OF FILE AFTER ARGUMENT!\n" CONSOLE_RESET);
            return 0;
        }

        return test_file(file_name);
    }

    program();

    return 0;
}