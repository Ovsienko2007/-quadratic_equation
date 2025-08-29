#include "solving.h"

/**
 * @brief solves a linear equation
 * 
 * @param [in] equation coefficents of quadratic equation
 * @param [out] ans     answer of quadratic equation
 * 
 * @return 0
 */
static int linear_equation(struct Equation equation, struct AnsEquation *ans);

/**
 * @brief solves a quadratic equation
 * 
 * @param [in] equation coefficents of quadratic equation
 * @param [out] ans     answer of quadratic equation
 * 
 * @return 0
 */
static int quadratic_equation(struct Equation equation, struct AnsEquation *ans);

int find_ans(Equation equation, AnsEquation *ans){

    ADD_PATH_TO_ASSERT;
    MY_ASSERT(ans != NULL, 1);

    if (is_equal(equation.a, 0)){
        return linear_equation(equation, ans);
    }
    else{
        return quadratic_equation(equation, ans);
    }
    
}

static int linear_equation(Equation equation, AnsEquation *ans){
    ADD_PATH_TO_ASSERT;
    MY_ASSERT(ans != NULL, 1);

    if (is_equal(equation.b, 0)){
        if (is_equal(equation.c, 0)){
            ans->num_valid_ans = INFINITY_ROOTS;
        }
        else{
            ans->num_valid_ans = ZERO_ROOTS;
        }
    }
    else{
        ans->ans2.Re = ans->ans1.Re = -equation.c / equation.b;
        ans->num_valid_ans = ONE_ROOT;
    }

    return 0;
}

static int quadratic_equation(Equation equation, AnsEquation *ans){
    ADD_PATH_TO_ASSERT;
    MY_ASSERT(ans != NULL, 1);

    double dis = equation.b * equation.b - 4 * equation.a * equation.c;

    if (is_equal(dis, 0)){
        ans->ans1.Re = ans->ans2.Re = (-equation.b) / 2 / equation.a;
        ans->num_valid_ans = ONE_ROOT;
    }

    else if (dis < 0){
        ans->ans1.Re = ans->ans2.Re = -equation.b / 2 / equation.a;

        double sqrt_dis = sqrt(-dis);

        ans->ans1.Im = -sqrt_dis / 2 / equation.a;
        ans->ans2.Im =  sqrt_dis / 2 / equation.a;
        
        ans->num_valid_ans = TWO_ROOTS;
    }

    else{
        double sqrt_dis = sqrt(dis);
        ans->ans1.Re = (-equation.b - sqrt_dis) / 2 / equation.a;
        ans->ans2.Re = (-equation.b + sqrt_dis) / 2 / equation.a;
        ans->num_valid_ans = TWO_ROOTS;
    }

    return 0;
}

bool is_equal(double x1, double x2){
    return fabs(x1 - x2) < EPS;
}

int minus_zero_to_zero(double *ans){
    MY_ASSERT(ans != NULL, 1);

    if (is_equal(*ans, 0)){
        *ans = 0;
    }

    return 0;
}