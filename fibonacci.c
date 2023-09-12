#include <stdio.h>
#include <math.h>

void generate_fib(int n){
    //generate the fibonnaci sequence up to the n term using iterative construct
    int a  = 0, //first term of fibonnaci by definition 
        b = 1; //second term of fibonacci by definition;
    int i = 2; //current element of the progression
    
    while(i < n){
        printf("%d, %d, ", a, b);
        i +=2 ;
        a += b;
        b += a;
    }
    printf("%d, %d",a , b);
    printf("\n");

}

void gen_fib_math(int n){
    //generate the fibonnaci sequence up to the n term mathematically
    double term_coefficent = sqrt(5)/5;
    double pos_coefficient = (1 + sqrt(5))/2;
    double neg_coefficient = (1 - sqrt(5))/2;

    for(int i = 0; i < n; i++){
        int a  = term_coefficent * pow(pos_coefficient, i) - term_coefficent * pow(neg_coefficient, i);
        printf("%d, ", a);
    }
    printf("\n");
}

int main(void){
    gen_fib_math(120);
    generate_fib(120);
}
