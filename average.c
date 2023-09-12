//Algorithm to compute the average of n numbers
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void average(void){
    int num = 0, //total number entered``
        current, //current number being processed
        sum  = 0; //sum of all the numbers
    float average = 0;
    printf("Enter numbers to find the average: \n");
    while(scanf("%d", &current) != EOF){
        sum += current;
        num++;
    }
    average = (num > 0) ? (float) sum /(float) num : 0;
    printf("\nTotal sum: %d"
           "\nTotal number: %d"
           "\nAverage: %f\n", sum, num, average);
}

void square_sum(void){
    int sum = 0;
    int current = 0;
    printf("Enter numbers: \n");
    while (scanf("%d", &current) != EOF)
        sum += (current * current);
    printf("sum of square: %d\n", sum);
}

void harmonic_mean(void){
    float  mean = 0;
    float sum = 0;
    float current ;
    int num = 0;

    printf("Enter number: \n");
    while (scanf("%f", &current) != EOF)
        num++, sum += (1/current);
    mean = (float) num / sum;
    printf("mean: %f", mean);
    
}

int sum_of_n_numbers(int n){
    return n*(n+1)/2;
}
int sum_of_n_odd_numbers(int n){
    return n*n;
}

int sum_of_n_even_numbers(int n){
    return  n * (n+ 1);
}

int sum_of_n_divisor(int n){
    int sum = 0;
    for(int i = 1; i <=n; i++){
        sum += (1/i);
    }
    return sum;
}

float sum_of_n_gp_from_one(int n, float diff){
    return  (pow(diff, (float)n) - 1)/ diff - 1;
}

int sum_of_n_neg_pos_value(int n){
    return (n & 1)? 1 : 0;
}
 
int main(void){
    harmonic_mean();
}
