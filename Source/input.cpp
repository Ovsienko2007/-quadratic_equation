#include "input.h"

/**
 * @brief clean buffer of stream
 * 
 * @param [in] stream stream
 * 
 * @return has the input in the stream ended
*/
static int clean_buffer(FILE *stream);

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
    path_to_assert(ADD, __PRETTY_FUNCTION__);

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

bool read_test_from_file(FILE *test_file, TestEquation *test, int line){
    path_to_assert(ADD, __PRETTY_FUNCTION__);

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

static int clean_buffer(FILE *stream){
    path_to_assert(ADD, __PRETTY_FUNCTION__);
    MY_ASSERT(stream, 1);

    int c = 0;
    do{
        c = fgetc(stream);
    } while (c != '\n' && c != EOF);

    return c ==  EOF;
}

static RootsCount string_to_rootscount(const char *num){
    path_to_assert(ADD, __PRETTY_FUNCTION__);
    MY_ASSERT(num != NULL, ERROR);
 
    if (strcmp("ONE_ROOT",       num) == 0)  return ONE_ROOT;
    if (strcmp("TWO_ROOTS",      num) == 0)  return TWO_ROOTS;
    if (strcmp("INFINITY_ROOTS", num) == 0)  return INFINITY_ROOTS;
    if (strcmp("ZERO_ROOTS",     num) == 0)  return ZERO_ROOTS;

    return ERROR;
}