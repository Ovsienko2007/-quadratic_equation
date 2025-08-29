#include "my_assert.h"

/**
 * @brief add name of function in stack
 * 
 * @param [in] stack  path to assert
 * @param [in] str     new file
 * 
 * @return 0
 */
static int add_funk(Stack *stack, const char* str){
    const char** new_data = (const char**)realloc(stack->data, stack->size * (stack->n + 1));

    MY_ASSERT(new_data != NULL, 1);

    stack->data = new_data;

    stack->data[stack->n] = str;
    stack->n++;
    return 0;
}

/**
 * @brief print path to assert
 * 
 * @param [in] stack    path to asxsert
 * 
 * @return 0
 */
static int print_stack(Stack stack){    
    for (unsigned int i = 0; i < stack.n; i++){
        printf(" %s\n", stack.data[i]);
    }

    return 0;
}

/**
 * @brief delite the last elem of path
 * 
 * @param [in] stack    path to assert
 * 
 * @return 0
 */
static int stack_pop(Stack *stack){
    const char** new_data = (const char**)realloc(stack->data, stack->size * (stack->n - 1));
    MY_ASSERT(new_data != NULL, 1);

    stack->data = new_data;
    stack->n--;
    return 0;

}
     
void print_assert(const char *file_name, const char *function_name, int expect_line_num){
    printf("Functions that were called:");
    path_to_assert(PRINT);
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
}

void path_to_assert(COMMAND_STACK command, ...){
    static Stack stack;
    switch (command){
        case CREAT:
            stack.n = 0;
            stack.size = sizeof(char**);
            stack.data = (const char **)calloc(stack.n, stack.size);
            break;
        case POP:
            stack_pop(&stack);
            break;
        case PRINT:
            print_stack(stack);
            break;
        case ADD:
            va_list args;
            va_start(args, command);
            
            for (int i = 0; i < 1; i++) {
                const char* str = va_arg(args, const char*);
                add_funk(&stack, str);
            }

            va_end(args);
            
        default:
            break;
    }
}