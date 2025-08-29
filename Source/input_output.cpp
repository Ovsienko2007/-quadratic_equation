#include "input_output.h"

/**
 * @brief check is number not inf or NaN
 * 
 * @param [in] x number
 * 
 * @return is double not inf or NaN
*/
static bool check_not_inf_nan(double x);


/**
 * @brief Transform str to RootsCount
 * 
 * @param [in]  num        str
 * @param [out] not_count  became true if num is not RootsCount
 * 
 * @return result of Transformation
*/
static RootsCount string_to_rootscount(const char *num);

// TODO assert
bool input_equation(Equation *equation){
    ADD_PATH_TO_ASSERT;
    ASSERT_CLEAN;
    bool flag = false;

    do{
        printf("Enter the values of the coefficients a, b, c:\n");

        if (flag){
            if (clean_buffer(stdin)){
                ASSERT_CLEAN;
                printf(CONSOLE_BLUE "End of file" CONSOLE_RESET);
                return true;
            }
        }

        flag = true;
    } while (scanf("%lf %lf %lf", &(equation->a), &(equation->b), &(equation->c)) != 3 ||
             check_not_inf_nan(equation->a) || check_not_inf_nan(equation->b) || check_not_inf_nan(equation->c));

    if (isalpha(getchar())){
        clean_buffer(stdin);
        ASSERT_CLEAN;
        return input_equation(equation);
    }
    return false;
    
}

bool read_test_from_file(FILE *test_file, TestEquation *test, int line){
    ADD_PATH_TO_ASSERT;
    MY_ASSERT(test_file != NULL, 1);
    if (fscanf(test_file, "%lf %lf %lf", &(test->equat.a), &(test->equat.b), &(test->equat.c)) != 3){
        if (fgetc(test_file) != EOF){
            printf(CONSOLE_RED "Incorrect data entry line %d\n" CONSOLE_RED, line);
        }
        return  clean_buffer(test_file);
    }

    char num_str_root_count[41] = {};

    fscanf(test_file, "%40s", num_str_root_count);

    test->ans.num_valid_ans = string_to_rootscount(num_str_root_count);
    ASSERT_CLEAN;

    if (test->ans.num_valid_ans == ERROR
        || fscanf(test_file, "%lf %lf", &(test->ans.ans1), &(test->ans.ans2)) != 2){
        
        printf(CONSOLE_RED "Incorrect data entry line %d\n" CONSOLE_RED, line);
        return clean_buffer(test_file);
    }

    return false;
}

static bool check_not_inf_nan(double x){
    return isinf(x) || isnan(x);
}

int clean_buffer(FILE *stream){
    ADD_PATH_TO_ASSERT;
    MY_ASSERT(stream, 1);

    int c = 0;
    do{
        c = fgetc(stream);
    } while (c != '\n' && c != EOF);

    return c ==  EOF;
}

static RootsCount string_to_rootscount(const char *num){
    ADD_PATH_TO_ASSERT;
    MY_ASSERT(num != NULL, ERROR);
 
    if (strcmp("ONE_ROOT",       num) == 0)  return ONE_ROOT;
    if (strcmp("TWO_ROOTS",      num) == 0)  return TWO_ROOTS;
    if (strcmp("INFINITY_ROOTS", num) == 0)  return INFINITY_ROOTS;
    if (strcmp("ZERO_ROOTS",     num) == 0)  return ZERO_ROOTS;

    return ERROR;
}

bool print_ans(AnsEquation ans){
    ADD_PATH_TO_ASSERT;
    switch (ans.num_valid_ans){
        case ZERO_ROOTS:
            printf("The sequation has " CONSOLE_RED "no roots" CONSOLE_RESET "\n");
            break;

        case ONE_ROOT:
            printf("There is 1 root:\n"
                   "   ans = " CONSOLE_GREEN "%0.3lf" CONSOLE_RESET "\n", ans.ans1);
            break;

        case TWO_ROOTS:
            printf("There are 2 roots:\n"
                  "   ans1 = " CONSOLE_GREEN "%0.3lf" CONSOLE_RESET "\n"
                  "   ans1 = " CONSOLE_GREEN "%0.3lf" CONSOLE_RESET "\n",
                  ans.ans1, ans.ans2);
            break;

        case INFINITY_ROOTS:
            printf(CONSOLE_GREEN "Infinite" CONSOLE_RESET " number of roots\n");
            break;
        
        case ERROR:
            print_str(BOLD, RED,  YELLOW, "ERROR");
            break;
            
        default:
            print_str(BOLD, RED,  YELLOW, "ERROR");
            break;
    }

    return 0;
}
