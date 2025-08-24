#include "flags.h"

bool check_flag(int argc, char *argv[], const char *flag)
{
    for (int arg_num = 0; arg_num < argc; arg_num++){
        if (strcmp(argv[arg_num], flag) == 0){
            return true;
        }
    };
    
    return false;
}