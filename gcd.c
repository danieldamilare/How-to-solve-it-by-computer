#include <stdio.h>
#include <stdlib.h>

typedef struct frac {
    int numer;
    int denom;
} frac ;

//Design an algorithm that will find the gcd of n positive non-zero integers
int gcd_n(int n, int arr[n]){
    void sanitize(int * , int *);
    int i = 0; //counter for the element in the array
    int current_gcd = arr[i++];

    while (i < n){ //continue looping until the last element

        /* Get the next two element of the array */
        int current_element = arr[i++]; 
        printf("current_gcd: %d, current_element: %d\n", current_gcd, current_element);
        /* **************************************/

        /* find the gcd between the current gcd and the next array number */
        while(current_element > 0){
            int temp = current_element; 
            current_element = current_gcd % current_element;
            current_gcd = temp;
        }
    }
    return current_gcd;
}

int gcd(int n1, int n2){
    while(n2 > 0){
        int temp = n1 % n2;
        n1 = n2; 
        n2 = temp;
    }
    return n1;
}

int scm(int n1, int n2){
    int divisor = gcd(n1, n2);
    return (divisor * (n1/divisor) * (n2 / divisor));

}

int scd(int n1, int n2){
    int min =  (n2 < n1) ? n2 : n1;
    
    int i = 2;
    while(i <= min){
        if(((n1 % i) == 0) && ((n2 % i) == 0))
            return i;
        i++;
    }

    return 1;
}

frac * sum_frac(frac * frac1, frac * frac2){
    frac * result = malloc(sizeof(frac));
    int lcm = scm(frac1->denom, frac2->denom);
    int upper = ((lcm / frac1->denom) * frac1->numer) +
        ((lcm / frac2->denom) * frac2->numer);
    result->numer = upper;
    result->denom = lcm;
    return result;
}

int main(void){
    int n = scd( 15, 6);
    printf("%d\n", n);

    frac n1 = {.numer = 5, .denom = 8};
    frac n2 = {.numer = 3, .denom = 2};
    frac * answer = sum_frac(&n1, &n2);
    printf("The sum is %d/%d\n", answer->numer, answer->denom);
}
