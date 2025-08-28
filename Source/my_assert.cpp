#include "my_assert.h"
     
void print_assert(const char *file_name, const char *function_name, int expect_line_num){

    printf(CONSOLE_RED "In function %s\n"
                       "Assert worked %s:%d\n" CONSOLE_RESET,
          function_name, file_name,  expect_line_num);

    FILE *code_file = fopen(file_name, "r");

    char line[str_len] = {}; // TODO dynamic allocation (calloc, free)

    // TODO scanf %ms
    
    int line_num = 0;
    while (fgets(line, str_len, code_file) != NULL ){
        line_num++;

        if (expect_line_num - 1 <= line_num && line_num <= expect_line_num + 1){
            printf("%5d: %s",line_num, line); 
        }
    }

    size_t line_len = strlen(line) / sizeof(line[0]);
    if (line[line_len] != '\n'){
        printf("\n");
    }
}