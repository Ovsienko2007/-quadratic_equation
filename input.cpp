#include "input.h"

int input_equation(Equation *equation)
{
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
    } while (scanf("%lf %lf %lf", &(equation->a), &(equation->b), &(equation->c)) != 3 || 
             check_not_inf_non(equation->a) || check_not_inf_non(equation->b) || check_not_inf_non(equation->c));

    if (isalpha(getchar())){
        buffer_cleaning();
        return input_equation(equation);
    }
    return 0;
}

bool check_not_inf_non(double x){
    if (isinf(x) || isnan(x)){
        return true;
    }

    return false;
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