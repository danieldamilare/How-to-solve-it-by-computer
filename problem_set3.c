#include <stdio.h>
#include <math.h>
#define error 1.0e-6
//Design an algorithm  to find the sum of the first n term of the series
// fn = 0! + 1! + 2! + ... + n!;

long long factorial_sum(long n){
    //assert n >= 0;
    long long result =1;
    long long current_term = 1;
    int counter = 0; //variable to keep track of the position of the term
    while (counter < n){
        counter++;
        current_term *= counter;
        printf("current_term: %lld\n", current_term);
        result += current_term;
    }
    return result;
}

double euler_sum(int n){
    //compute the e to the n terms
    double current_term = 1;
    int counter = 0;
    double result = 1;
    while (counter < n){
        counter++;
        current_term /= counter;
        result += current_term;
    }
    return result;
}

double cosine(double n){
    int counter = 0; //variable to hold the position of the terms;
    double current_term  = 1;
    double result =current_term;
    double n2 = n * n;
    while(fabs(current_term) > error){
        counter += 2;
        current_term =  -current_term * n2 / (counter * (counter-1));
        result += current_term;
    }
    return result;
}

int main(void){
    printf("factorial sum 4: %lld\n", factorial_sum(4));
    printf("euler_sum: %lf\n", euler_sum(1000));
    printf("cos 0.5: original: %lf\n artificial: %lf\n", cos(0.5), cosine(0.5));
}


