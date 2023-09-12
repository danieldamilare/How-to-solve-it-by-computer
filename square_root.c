#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#define error 1.0e-6

double sqrt_mod(double n){
    double initial_guess = 0;
    double new_guess = n /2;
    while (fabs(new_guess - initial_guess) > error ){
        printf("new_gues: %lf, initial_guess: %lf\n", new_guess, initial_guess);
        initial_guess = new_guess;
        new_guess = (initial_guess + n/initial_guess)/2;
    }
    return new_guess;
}

double slow_sqrt(double n){
    double initial_guess =  n/2;
    double current_step = 1;
    int greater = 1;
    while (fabs((initial_guess * initial_guess) - n) > error){

        if ((initial_guess * initial_guess) > n){
            if (!greater){
                greater = 1;
                current_step /= 10;
            }
            initial_guess -= current_step;
        }

        else if ((initial_guess * initial_guess) < n){
            if (greater){
                greater = 0;
                current_step /= 10;
            }
            initial_guess += current_step;
        }

        printf("initial_guess: %lf; current_step: %lf\n",
                initial_guess, current_step);
    }
    return initial_guess;

}
double geometric_mean(double num, ...){
    va_list arrays;
    double product = 1;
    va_start(arrays, num);

    for(int i = 0; i < num; i++){
        product *= va_arg(arrays, double);
        printf("product: %lf\n", product);
    }

    double initial_guess = 0;
    double new_guess = product/2;

    while(fabs(initial_guess - new_guess) > error){
        printf("initial_guess: %lf, new_guess: %lf\n", initial_guess, new_guess);
        initial_guess = new_guess;
        new_guess = ((num - 1) * initial_guess  + (product /pow(initial_guess, (num-1)))) / num;
    }
    return new_guess;
}

int main(void){
    double num = geometric_mean(6.0, 8.0, 10.0, 20.0, 80.0, 57.0, 72.0);
    printf("num: %lf\n", num);
}
