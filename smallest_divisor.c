#include <stdio.h>
#include <math.h>

int s_divisor(int n){
    if (n % 2 == 0) return 2;
    int sdivisor = 1;
    int i = 3;
    int sqrt_n = sqrt(n);
    while (n % i != 0  && i < sqrt_n + 1){
        i += 2;
    }
    if(n % i == 0 ) sdivisor = i;
    return sdivisor;
}

int main(void){
   int n =  s_divisor(49);
   printf("n: %d\n", n);
    
}
