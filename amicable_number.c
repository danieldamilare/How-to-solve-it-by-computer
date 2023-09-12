#include <stdio.h>
#include <math.h>

int sum_divisor(int number){
    int sum = 1;
    int limit = sqrt(number) + 1;
    if ((number % 2) == 0){
        for(int i = 2; i < limit; i++)
            if (number % i == 0) {
                sum += (i + (((number/i) != i)? (number/i) : 0));
            }
    }
    else{
        for(int i = 3; i < limit; i+= 2){
            if(number  % i == 0) sum += (i + (((number/i) != i) ? (number/i) : 0));
        }
    }
    return sum;
}

int is_amicable(int n1, int n2){
    return sum_divisor(n1)  == n2 &&  sum_divisor(n2) == n1;
}
int is_perfect_number(int n1){
    return sum_divisor(n1) == n1;
}

int main(void){
    int i =sum_divisor(16);
    printf("%d\n", i);
    if(is_amicable(220, 284)) printf("Working");
}
