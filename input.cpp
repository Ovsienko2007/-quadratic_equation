#include "input.h"

bool input_equation(Equation *equation){
    bool flag = false;

    do{
        printf("Enter the values of the coefficients a, b, c:\n");

        if (flag){
            if (clean_buffer(stdin)){
                printf(CONSOLE_BLUE "End of file" CONSOLE_RESET);
                return true;
            }
        }

        flag = true;
    } while (scanf("%lf %lf %lf", &(equation->a), &(equation->b), &(equation->c)) != 3 || 
             check_not_inf_nan(equation->a) || check_not_inf_nan(equation->b) || check_not_inf_nan(equation->c));

    if (isalpha(getchar())){
        clean_buffer(stdin);
        return input_equation(equation);
    }
    return false;
}

bool check_not_inf_nan(double x){
    if (isinf(x) || isnan(x)){
        return true;
    }

    return false;
}

int clean_buffer(FILE *stream){
    assert(stream);

    int c = NULL;
    do{
        c = fgetc(stream);
        if (c ==  EOF){   
            return 1;
        }
    } while (c != '\n');

    return 0;
}

bool read_test_from_file(FILE *test_file, TestEquation *test, int line){
    if (fscanf(test_file, "%lf %lf %lf", &(test->equat.a), &(test->equat.b), &(test->equat.c)) != 3){
        if (fgetc(test_file) != EOF){            
            printf(CONSOLE_RED "Incorrect data entry line %d\n" CONSOLE_RED, line);
            return clean_buffer(test_file);
        }
        return  clean_buffer(test_file);
    }

    char num_str_root_count[41] = {};
    bool not_count = false;

    fscanf(test_file, "%40s", num_str_root_count);

    test->ans.num_valid_ans = string_to_rootscount(num_str_root_count, &not_count);

    if (not_count || fscanf(test_file, "%lf %lf", &(test->ans.ans1), &(test->ans.ans2)) != 2){
        printf(CONSOLE_RED "Incorrect data entry line %d\n" CONSOLE_RED, line);
        return clean_buffer(test_file);
    }

    return false;
}

RootsCount string_to_rootscount(const char *num, bool *not_count){
    if (NULL != strstr("ONE_ROOT", num))        return ONE_ROOT;
    if (NULL != strstr("TWO_ROOTS", num))       return TWO_ROOTS;
    if (NULL != strstr("INFINITY_ROOTS", num))  return INFINITY_ROOTS;
    if (NULL != strstr("ZERO_ROOTS", num))      return ZERO_ROOTS;
    
    *not_count  = true;
    return ZERO_ROOTS;
}