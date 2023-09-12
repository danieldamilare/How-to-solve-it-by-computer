#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void generate_prime(int n){
    int sqrtn = sqrt(n);
    int multiple[sqrtn], //array to store multiple of primes;
    prime[sqrtn];  //array to store prime less than root(n) since n has all prime factor  less than root(n)
    prime[0] = 2, prime[1] = 3, prime[2] = 5;

    int i, //index for primes save
        j,      //index for multiples and prime array
        limit,   //upper index for primes less than sqrt(n)
        limit_square, //square of largest prime included so far 
        dx,  //prime sequence step
        x;  //current element for prime test
    dx = 2, x = 5, j = i = limit = 2;
    limit_square = 25;
    _Bool isprime = 1;
    if (n < 5){
        for(j = 0; j < (n+1)/2; j++) printf("%d ", prime[j]);
    }
    else {
        for(j = 0; j <= 2; j++) printf("%d ", prime[j]);
        while (x < n){
            x += dx;
            dx = abs(dx - 6);
            if(limit <= i){
                if(x >= limit_square){
                    multiple[limit] = limit_square;
                    limit += 1;
                    if(limit <= i) limit_square = prime[limit] * prime[limit];
                }
            }
            j = 2;
            isprime = 1;
            while(isprime && j < limit){
                while(multiple[j] < x) multiple[j] += (prime[j] * 2); //multiple prime times two to skip even mulipl
                isprime = (x != multiple[j]);
                j++;
                                                                      
            }
            if (isprime){

                printf("%d ", x);
                if(x < sqrtn)
                    prime[++i] =x;
            }
        }
    }
    printf("\n");

}
int main(int argc, char ** argv){
    int nums = 0;
    if (argc == 1){
        printf("Generate prime up to: ");
        scanf("%d", &nums);
    }
    else sscanf(argv[1], "%d", &nums);
    generate_prime(nums);

}
