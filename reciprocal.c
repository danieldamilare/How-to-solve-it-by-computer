#include <stdio.h>
#include <math.h>
#include <stdrg.h>

#define error 1.0e-6

double reciprocal(double n) {
    double x = 1.0;
    double previous_x;
    
    do {
        previous_x = x;
        x = x * (2 - n * x);
    } while (fabs(x - previous_x) > error);
    
    return x;
}

double geometric_mean(double num, ...){
    va_list arrays;
    double product = 1;
    va_start(arrays, num);
    for(int i = 0; i < num; i++){
        product *= va_arg(arrays, float);
    }
    double initial_guess = 0;
    double new_guess = product/2;
    while(fabs(initial_guess - new_guess) > error){
        initial_guess = new_guess;
        new_guess = ((num - 1) * initial_guess  + (product / ((num - 1) * initial_guess))) / num;
    }
    return new_guess;

}

int main(void) {
    double n = 7.0;
    double reciprocal_n = reciprocal(n);
    printf("Reciprocal of %.2lf: %.6lf\n", n, reciprocal_n);
    return 0;
}
