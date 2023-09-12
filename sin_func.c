#include <stdio.h>
#include <math.h>
#define error 1.0e-6

double sine (double num){
    //calculate the infinite series expansion of sine to an error accuracy of 1.0e-6
    num  = num * M_PI/180;
    int i = 1; //counter to keep track of the sequence;
    double  term = num; //each term of the sequence. first term is num;
    double result = term; //variable to hold the result of the sjne calculation
    printf("result: %lf\n", result);
    while(fabs(term) > error){
        printf("Term: %lf\n", term);
        i += 2;
        term = -term * (num *num)/(i* (i-1));
        result += term;

    }
    return result;
}


int main(void){
    double result  =  sine(30);
    printf("The sine value of 30 is %lf\n", result );
}
