#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

// PascalCase
// camelCase
// snake_case
// kebab-case

// TODO color_printf(COLOR, "...", ...) (read about variadic args)

enum rootsCount
{
    ONE_ROOT,
    TWO_ROOTS,
    INFINITY_ROOTS,
    ZERO_ROOTS
};

struct Equation{
    double a;
    double b;
    double c;
};

struct Ans_equation{
    rootsCount num_valid_ans;
    double ans1;
    double ans2;
};

const double EPS = 1e-6; 

bool is_equal(double a, double b);

int buffer_cleaning();

rootsCount find_ans(struct Equation equat, struct Ans_equation *ans);
rootsCount linear_equation(struct Equation equat, struct Ans_equation *ans);
rootsCount quadratic_equation(struct Equation equat, struct Ans_equation *ans);

int minus_zero_to_zero(double *ans1);

int print_ans(struct Ans_equation ans);

// https://dhwthompson.com/2019/my-favorite-git-commit

int main()
{
    struct Equation equat = {};
    struct Ans_equation ans = {
        .num_valid_ans = ZERO_ROOTS,
        .ans1 = 0,
        .ans2 = 0
    };

    bool flag = false;

    do{
        printf("Enter the values of the coefficients a, b, c:\n");
        if (flag){
            if (buffer_cleaning())
            {
                printf("End of file");
                return 0;
            }
        }
        flag = true;
    } while (scanf("%lf %lf %lf", &equat.a, &equat.b, &equat.c) != 3);

    ans.num_valid_ans = find_ans(equat, &ans); // TODO do this assignment inside find_ans

    minus_zero_to_zero(&ans.ans1);
    minus_zero_to_zero(&ans.ans2);

    print_ans(ans);

    return 0;
}

rootsCount find_ans(Equation equat, Ans_equation *ans)
{
    assert(ans != NULL);

    if (is_equal(equat.a, 0)){
        return linear_equation(equat, ans);
    }
    else{
        return quadratic_equation(equat, ans);
    }
}

// TODO solve_linear_...
rootsCount linear_equation(Equation equat, Ans_equation *ans)
{
    assert(ans != NULL);
    // TODO remove

    if (is_equal(equat.a, 0))    
    {
        if (is_equal(equat.b, 0))
        {
            return INFINITY_ROOTS;
        }
        else // TODO else not needed
        {
            return ZERO_ROOTS;
        }
    }
    else
    {
        ans->ans2 = ans->ans1 = -equat.c / equat.b;
        return ONE_ROOT;
    }
}

rootsCount quadratic_equation(Equation equat, Ans_equation *ans)
{
    assert(ans != NULL);
    
    double dis = equat.b * equat.b - 4 * equat.a * equat.c;

    if (dis < 0) // TODO draw number axis and think about EPS
    {
        return ZERO_ROOTS;
    }
    else if (is_equal(dis, 0))
    {
        ans->ans1 = ans->ans2 = (-equat.b) / 2 / equat.a; 
        return ONE_ROOT;
    }
    else
    {
        ans->ans1 = (-equat.b + sqrt(dis)) / 2 / equat.a;
        ans->ans2 = (-equat.b - sqrt(dis)) / 2 / equat.a;
        return TWO_ROOTS;
    }
}

int print_ans(Ans_equation ans)
{
    switch (ans.num_valid_ans){
        case ZERO_ROOTS:
            printf("The sequation has %sno roots%s\n", GREEN, RESET);
            break;

        case ONE_ROOT:
            printf("There is 1 root:\n  ans = %s %0.3lf %s\n", GREEN, ans.ans1, RESET);
            break;
            
        case TWO_ROOTS:
            // TODO split into 2 lines
            printf("There are 2 roots:\n  ans1 = %s %0.4lf %s \n  ans1 = %s %0.4lf %s\n", GREEN, ans.ans1, RESET, GREEN, ans.ans2, RESET);
            break;

        case INFINITY_ROOTS:
            printf("%sInfinite%s number of roots\n", GREEN, RESET);
            break;

        default:
            printf("%sError%s\n", RED, RESET);
            break;
    }
    return 0;
}

bool is_equal(double x1, double x2){
    if (fabs(x1 - x2) < EPS){
        return true;
    } else{
        return false;
    }
}

int buffer_cleaning(){
    int c;
    do{
        c = getchar();
        if (c ==  EOF){
            return 1;
        }
    } while (c != '\n');

    return 0;
}

int minus_zero_to_zero(double * ans) // TODO remove whitespace
{
    assert(ans != NULL);

    if (is_equal(*ans, 0)){
        *ans = 0;
    }
    // TODO blank line
    return 0;
}