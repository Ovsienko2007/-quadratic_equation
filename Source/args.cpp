#include "args.h"

char** check_argument(int argc, char **argv, const char *arg){
    ADD_PATH_TO_ASSERT;
    MY_ASSERT(argv != NULL, 0);    

    for (int arg_num = 0; arg_num < argc; arg_num++){
        if (strcmp(argv[arg_num], arg) == 0){
            return argv + arg_num;
        }
    }
    return 0;
}

const char* get_option_argument(int argc, char **argv, char **option_ptr){
    ADD_PATH_TO_ASSERT;
    MY_ASSERT(argv != NULL, 0);
    MY_ASSERT(option_ptr != NULL, 0);

    if (option_ptr - argv >= argc) {
        return NULL;
    }

    return *(option_ptr + 1);
}
