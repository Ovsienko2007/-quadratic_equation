#include "input_output.h"
#include "solving.h"
#include "unit_test.h"
#include "work_with_colors.h"
#include "args.h"
#include "my_assert.h"
#include "console.h"

int main(int argc, char *argv[]){
    ADD_PATH_TO_ASSERT;
    
    if (check_argument(argc, argv, "--embedded-test")){
        return !run_unit_tests_from_code();
    }
    ASSERT_CLEAN;

    if (check_argument(argc, argv, "--console")){
        return run_console();
    }
    ASSERT_CLEAN;

    if (char **option_ptr = check_argument(argc, argv, "--file-test")){

        const char *file_name = get_option_argument(argc, argv, option_ptr);

        if (!file_name){
            printf(CONSOLE_RED "ERROR: WERE IS NO NAME OF FILE AFTER ARGUMENT!\n" CONSOLE_RESET);
            return 0;
        }

        return test_file(file_name);
    }
    ASSERT_CLEAN;

    program();
    ASSERT_CLEAN;
    
    return 0;
}