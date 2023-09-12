#include <stdio.h>
#include <stdlib.h>

void count(void){
    int neg_count = 0,      //count of negative number
        pos_count = 0;      //count of positive number
    int current;

    printf("Enter numbers: \n");
    while(scanf("%d", &current) != EOF)
        current >= 0 ? pos_count++ : neg_count++;
    printf("You entered: %d positive numbers and %d negative numbers\n",
            pos_count, neg_count);
}


int  main(void){
    count();
    
}
