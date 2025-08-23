#include "solving.h"

int find_ans(Equation equat, AnsEquation *ans)
{
    assert(ans != NULL);

    if (is_equal(equat.a, 0)){
        linear_equation(equat, ans);
    }
    else{
        quadratic_equation(equat, ans);
    }

    return 0;
}

// TODO solve_linear_...
int linear_equation(Equation equat, AnsEquation *ans)
{
    assert(ans != NULL);

    if (is_equal(equat.b, 0))    
    {
        if (is_equal(equat.c, 0))
        {
            ans->num_valid_ans = INFINITY_ROOTS;
        }
        else 
        {
            ans->num_valid_ans = ZERO_ROOTS;
        }
    }
    else
    {
        ans->ans2 = ans->ans1 = -equat.c / equat.b;
        ans->num_valid_ans = ONE_ROOT;
        
    }

    return 0;
}

int quadratic_equation(Equation equat, AnsEquation *ans)
{
    
    double dis = equat.b * equat.b - 4 * equat.a * equat.c;

    if (is_equal(dis, 0))
    {
        ans->ans1 = ans->ans2 = (-equat.b) / 2 / equat.a; 
        ans->num_valid_ans = ONE_ROOT;
    }
    
    else if (dis < -EPS)
    {
        ans->num_valid_ans = ZERO_ROOTS;
    }

    else
    {
        ans->ans1 = (-equat.b - sqrt(dis)) / 2 / equat.a;
        ans->ans2 = (-equat.b + sqrt(dis)) / 2 / equat.a;
        ans->num_valid_ans = TWO_ROOTS;
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

int minus_zero_to_zero(double *ans)
{
    assert(ans != NULL);

    if (is_equal(*ans, 0)){
        *ans = 0;
    }

    return 0;
}