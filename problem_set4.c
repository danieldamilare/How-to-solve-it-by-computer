#include <stdio.h>


void gen_lucas_sequence(int n){
    int a = 1; //first term in the sequence
    int b = 3; // second term in the sequence
    int i = 2; // number of term currently generated

    while (i < n){
        printf("%d, %d, ", a, b);
        a += b, b+= a;
        i +=2;
    }
    (i == n)? printf("%d, %d\n", a, b) : printf("%d\n", a);

}

void gen_tribonacci_sequence(int n){
    int a = 0, // first number in the sequence
        b = 1, // second number in the sequence
        c = 1; // third number in the sequence
    int i = 3; //current number of term generated;
    while(i < n){
        printf("%d, %d, %d,", a, b, c);
        a += (b+c);
        b += (a+c);
        c += (a+b);
    }
    if (n % 3 == 0) printf("%d, %d, %d\n", a, b, c);
    else if (n % 3 == 2) printf("%d, %d\n", a, b);
    else printf("%d\n", a);
}

void confirm_fib(int n1, int n2){
    //function to confirm if n1 and n2 are consecutive fibonacci sequence
    int a = 0, //first element in the fib sequence;
        b =1; //seond element in the fib sequence;
    while (a < n1 && b < n1){
        a+= b, b+= a;
        printf("a: %d, b: %d\n", a, b);
    }
    if (a == n1 && b == n2) printf("consecutive fib sequence\n");
    else if (b == n1 && b+a == n2) printf("consecutive fib sequence\n");
    else printf("Non consecutive fib sequence\n");
}

void generate_fact_sequence(int n){
    /* Generate a sequence where each member is the sum of adjacent factorials
     */
    int current = 2; // current term in the sequence calculated as 
    int a = 1; //current factorial term to be added
    int i = 2; //current number of term in the progression to be generated
    for(; i <=n; i++){
        printf("%d,", current);
        current = a * i + a;
        a *= i;
    }
    printf("%d\n", current);
}

int main(void){
    confirm_fib(13, 21);
    confirm_fib(14, 15);
    generate_fact_sequence(5);

}


