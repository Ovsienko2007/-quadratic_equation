#include "consol.h"

/**
 * @brief distributes commands from consol
 * 
 * @param [in] command command that needs to be complited
 * 
 * @return execution status
 */
static int commands(char *command);

int consol(){
    path_to_assert(CREAT);
    while (1){
        
        char command[max_len];
        printf(">>>");

        int c = '\0';
        c = getchar();
        if (c != '\n'){
        scanf("%100s", command);
        int asd = commands(command);

        if (asd == -1){
            return 0;
        }
        if (asd == 0){
            printf("Command complited!\n");
        }
        else{
            printf("Thre is no such command\n");
            clean_buffer(stdin);
            
        }
        }
    }
}

static int commands(char *command){
    if (strcmp(command, "s") == 0){
        if (program()){
            printf("ERROR");
        }
        return 0;
    }
    if (strcmp(command, "tc") == 0){
        run_unit_tests_from_code();
        clean_buffer(stdin);
        return 0;
    }
    if (strcmp(command, "tf") == 0){
        char file_name[max_len] = {};
        scanf("%100s", file_name);

        test_file(file_name);
        clean_buffer(stdin);
        return 0;
    }

    if (strcmp(command, "e") == 0){
        printf("THE END");
        return -1;
    }
    return 1;
}


int program(){
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

int test_file(const char * file_name){
    FILE * test_file = fopen(file_name, "r");

    if (test_file == NULL){
        printf("There is no file with name %s\n", file_name);
        return 0;
    }

    return !run_unit_tests_from_txt(test_file);
}
