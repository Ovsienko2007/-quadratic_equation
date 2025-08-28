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
static RootsCount string_to_rootscount(const char *num, bool *not_count);


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

static bool check_not_inf_nan(double x){
    if (isinf(x) || isnan(x)){
        return true;
    }

    return false;
}

static int clean_buffer(FILE *stream){
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

static RootsCount string_to_rootscount(const char *num, bool *not_count){
    if (strcmp("ONE_ROOT", num) == 0)        return ONE_ROOT;
    if (strcmp("TWO_ROOTS", num) == 0)       return TWO_ROOTS;
    if (strcmp("INFINITY_ROOTS", num) == 0)  return INFINITY_ROOTS;
    if (strcmp("ZERO_ROOTS", num) == 0)      return ZERO_ROOTS;

    *not_count  = true;
    return ZERO_ROOTS;
}