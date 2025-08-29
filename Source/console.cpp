#include "console.h"

static const char* help = 
"============================Quadratic_equation==================================\n"
"                                                                                \n"
"The program that solves a quadratic equation.                                   \n"
"                                                                                \n"
"                                                                                \n"
"======================Commands supported by the program=========================\n"
"                                                                                \n"
"With Make                                                                       \n"
"                                                                                \n"
"| Command                     | what is it doing                               |\n"
"|-----------------------------|------------------------------------------------|\n"
"| make                        | compiles the program                           |\n"
"| make start                  | starts the program in standard mode            |\n"
"| make start_embedded_test    | performs tests prescribed in the program       |\n"
"| make start_file_test        | performs tests prescribed in the file test     |\n"
"| make start_consol           | open console                                   |\n"
"| make clean                  | delete all compiled files                      |\n"
"                                                                                \n"
"Without it                                                                      \n"
"                                                                                \n"
"./Build/quadratic_equation.exe runs the program (does not compile)              \n"
"                                                                                \n"
"Additionally, you can run the program with flags                                \n"
"                                                                                \n"
"| Flag                        | what is it doing                               |\n"
"|-----------------------------|------------------------------------------------|\n"
"| --embedded-test             | performs tests prescribed in the program       |\n"
"| --file-test <file_name>     | executes tests specified in the specified file |\n"
"| --console                   | open console                                   |\n"
"                                                                                \n"
"Generating documentation using doxyfile                                         \n"
"                                                                                \n"
"doxygen   generates documentation                                               \n"
"                                                                                \n"
"=======================Technologies used in the programe========================\n"
"                                                                                \n"
"* g++  14.2.0                                                                   \n"
"* GNU Make                                                                      \n"
"* Doxyfile                                                                      \n"
"* cmd Linux                                                                     \n";

/**
 * @brief distributes commands from console
 * 
 * @param [in] command command that needs to be complited
 * 
 * @return execution status
 */
static int run_commands(char *command); // TODO readCommands

int run_console(){ // TODO runConsole
    ADD_PATH_TO_ASSERT;

    while (1){
        
        char command[max_len];
        printf(">>>");

        int c = '\0';
        c = getchar();
        if (c != '\n'){
        scanf("%100s", command);
        int asd = run_commands(command);

        if (asd == -1){
            return 0;
        }
        if (asd == 0){
            printf("Command complited!\n");
        }
        else{
            printf("Thre is no such command\n");
            clean_buffer(stdin);
            ASSERT_CLEAN;            
        }
        }
    }
}

static int run_commands(char *command){
    ADD_PATH_TO_ASSERT;
    if (strcmp(command, "s") == 0){
        if (run_program()){
            printf("ERROR");
        }
        ASSERT_CLEAN;
        return 0;
    }
    if (strcmp(command, "tc") == 0){
        run_unit_tests_from_code();
        clean_buffer(stdin);
        ASSERT_CLEAN;
        return 0;
    }
    if (strcmp(command, "tf") == 0){
        char file_name[max_len] = {};
        scanf("%100s", file_name);

        test_file(file_name);
        ASSERT_CLEAN;

        clean_buffer(stdin);
        ASSERT_CLEAN;
        return 0;
    }

    if (strcmp(command, "h") == 0){
        printf("%s", help);
        clean_buffer(stdin);
        ASSERT_CLEAN;
        return 0;
    }

    if (strcmp(command, "e") == 0){
        printf("THE END");
        return -1;
    }
    return 1;
}

int test_file(const char * file_name){
    ADD_PATH_TO_ASSERT;
    FILE * test_file = fopen(file_name, "r");

    if (test_file == NULL){
        printf("There is no file with name %s\n", file_name);
        return 0;
    }

    return !run_unit_tests_from_txt(test_file);

}

int run_program(){
    ADD_PATH_TO_ASSERT;
    Equation equation = {};
    AnsEquation ans = {
        .num_valid_ans = ZERO_ROOTS,
        .ans1 = {.Re = 0, .Im = 0},
        .ans2 = {.Re = 0, .Im = 0}
    };

    if (input_equation(&equation)){
        return 0;
    }

    if (find_ans(equation, &ans)){
        printf("ERROR");
        return 1; 
    }

    minus_zero_to_zero(&ans.ans1.Re);
    ASSERT_CLEAN;
    minus_zero_to_zero(&ans.ans2.Re);
    ASSERT_CLEAN;

    print_ans(ans);
    ASSERT_CLEAN;
    return 0;
}
