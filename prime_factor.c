#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int PRIME[100000];

void gen_prime(){
    PRIME[0] = PRIME[1] = 0;
    for(int i = 2; i < 100000; i++) PRIME[i] = 1;
    for(int i = 0;(i*i) < 100000; i++){
        if (PRIME[i]){
            for(int j = i * i; j < 100000; j += i){
                PRIME[j] = 0;
            }
        }
    }
}

int get_next_prime(int n){
    int i  = n  + 1;
    for(; PRIME[i] ==0; i++)
        ;
    return i;
}
int  prime_factor(int n, int arr[n]){
    printf("Inside prime_factor");
    int prime  = 2;
    int i = 0;
    int quotient = n /2;
    int remainder = n % 2;
    while(remainder == 0 || quotient > prime){
        printf("prime: %d\n", prime);
        if (remainder == 0){
            arr[i++] = prime;
            n = quotient;
        }
        else {
            prime = get_next_prime(prime);
        }
            quotient = n /prime;
            remainder = n % prime;
        
    }

    if (n > 1){
        arr[i++] = n;
    }
    return i;
}

int main(void){
    gen_prime();
    printf("Prime generated\n");
    int n = 1997777777;
    printf("n: %d\n", n);
    int arr[(int)sqrt(n)];
    int num = prime_factor(n, arr);
    for(int i = 0; i < num-1; i++)printf("%d X ", arr[i]);
    printf("%d\n", arr[num-1]);

}

