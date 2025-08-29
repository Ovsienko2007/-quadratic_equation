#include "my_assert.h"

// TODO make stack static and global

static Stack creat_stack(){
    Stack stack;

    stack.size = 0;
    stack.data = (const char **)calloc(stack.size, size_path);
    
    return stack;
}

static Stack stack = creat_stack();

int push_func(const char* str){
    const char** new_data = (const char**)realloc(stack.data, size_path * (stack.size + 1));

    MY_ASSERT(new_data != NULL, 1);

    stack.data = new_data;

    stack.data[stack.size] = str;
    stack.size++;
    return 0;
}

int print_stack(){    
    for (unsigned int i = 0; i < stack.size; i++){
        printf(" %s\n", stack.data[i]);
    }

    return 0;
}

int clean_stack(const char *func){
    bool func_in_data = false;
    unsigned int new_size = 0;
    for (new_size = 0; new_size <= stack.size; new_size++){
        if (strcmp(func, stack.data[new_size]) == 0){
            func_in_data = true;
            break;
        }
    }
    if (!func_in_data){
        return 0;
    }
    new_size++;

    const char** new_data = (const char**)realloc(stack.data, size_path * (new_size));

    MY_ASSERT(new_data != NULL, 1);

    stack.data = new_data;

    stack.size = new_size;
    return 0;
}

int stack_pop(){
    const char** new_data = (const char**)realloc(stack.data, size_path * (stack.size - 1));
    MY_ASSERT(new_data != NULL, 1);

    stack.data = new_data;
    stack.size--;
    return 0;

}
     
void print_assert(const char *file_name, const char *function_name, int expect_line_num){
    printf("Functions that were called:");
    PRINT_PATH;
    
    printf(CONSOLE_RED "\nIn function: %s\n"
                       "Assert worked %s:%d\n" CONSOLE_RESET,
          function_name, file_name,  expect_line_num);

    FILE *code_file = fopen(file_name, "r");

    char line[str_len] = {};
    
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
    fclose(code_file);
}