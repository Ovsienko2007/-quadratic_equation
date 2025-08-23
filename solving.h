#ifndef SOLVING_H_
#define SOLVING_H_

#include <assert.h>
#include <math.h>

enum RootsCount
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

struct AnsEquation{
    RootsCount num_valid_ans;
    double ans1;
    double ans2;
};

const double EPS = 1e-6; 

bool is_equal(double a, double b);

int minus_zero_to_zero(double *ans1);

int find_ans(struct Equation equat, struct AnsEquation *ans);
int linear_equation(struct Equation equat, struct AnsEquation *ans);
int quadratic_equation(struct Equation equat, struct AnsEquation *ans);

#endif