#include "solving.h"

int find_ans(Equation equation, AnsEquation *ans){
    assert(ans != NULL);

    if (is_equal(equation.a, 0)){
        linear_equation(equation, ans);
    }
    else{
        quadratic_equation(equation, ans);
    }

    return 0;
}

int linear_equation(Equation equation, AnsEquation *ans){
    assert(ans != NULL);

    if (is_equal(equation.b, 0)){
        if (is_equal(equation.c, 0)){
            ans->num_valid_ans = INFINITY_ROOTS;
        }
        else{
            ans->num_valid_ans = ZERO_ROOTS;
        }
    }
    else{
        ans->ans2 = ans->ans1 = -equation.c / equation.b;
        ans->num_valid_ans = ONE_ROOT;
        
    }

    return 0;
}

int quadratic_equation(Equation equation, AnsEquation *ans){    
    double dis = equation.b * equation.b - 4 * equation.a * equation.c;

    if (is_equal(dis, 0)){
        ans->ans1 = ans->ans2 = (-equation.b) / 2 / equation.a; 
        ans->num_valid_ans = ONE_ROOT;
    }
    
    else if (dis < -EPS){
        ans->num_valid_ans = ZERO_ROOTS;
    }

    else{
        ans->ans1 = (-equation.b - sqrt(dis)) / 2 / equation.a;
        ans->ans2 = (-equation.b + sqrt(dis)) / 2 / equation.a;
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

int minus_zero_to_zero(double *ans){
    assert(ans != NULL);

    if (is_equal(*ans, 0)){
        *ans = 0;
    }

    return 0;
}