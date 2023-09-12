#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef enum boolean {
    false, true
} bool;

long long factorial(long n){
    long long result = 1;
    long counter = 0;
    for( counter = 1; counter <= n; counter++){
        result *= counter;
    }
    return result;

}

double factorial_inverse(long n) {
    long long result = factorial(n);
    return (double)1/(double)result;
}


double fact_double(long x, long n){
    long long result = pow(x, n);
    long long fact = factorial(n);
    return (double)result/(double)fact;
}

bool is_factorial(long long n){
    long long result = 1;
    int i = 0;
    while(result < n){
        result = result * ++i;
    }
    return (result == n);
}

long long largest_factorial(long long n){
    long i = 0;
    long long largest_fact = 1;
    long long fact = 1;
    while(fact < n){
        fact *= ++i;
        if (n % fact == 0) largest_fact = fact;
    }
    return largest_fact;
}

long long mult_sim(long n1, long n2){
    //Acce
    bool sign = 0;
    sign = (n1 < 0 ? n2 >= 0 : n2 < 0);
    n1 = (n1 < 0 ? -n1 : n1);
    n2 = (n2 < 0 ? -n2 : n2);
    if(!n1 || !n2) return 0;
    long long result = n1;
    long count = 1;
    for(; count < n2; count++) result += n1;
    return (sign? -result : result);
}

double combination(int n, int r) {
    long long result = 1;
    int counter = n;
    while (counter < r){
        result *= n; 
        n--;
    }
    return (double)result/( double ) (factorial(r));
}

void pascal_tri(int n){
    int pow = 0;
    for(int i = 0; i < 
}


int main(void){
    long long n = largest_factorial(10);
    printf("n is %lld\n", n);
    printf(" -100 * -200: %lld\n", mult_sim(-100, -200));
}
