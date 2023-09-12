//An algorithm to generate lucky number through sieveing techniques

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void generate_lucky_num(int n){
    int lucky_number[n+1];
    for(int i = 0; i < n; i++) lucky_number[i] = 1;
    int current_count = 2;
    int i = 0;
    while(current_count < (n+1+1)/2){
        while(i < n+1){
            for(int j = 0; j < current_count && i <n+1;){
                if (lucky_number[++i] == 0 ) continue;
                else j++;
            }
            if(i < n+1)
            lucky_number[i] = 0;
        }
        i = 0;
        current_count++;
    }

    for(int i = 1; i < n+1;  i++){
        if(lucky_number[i] != 0) printf("%d ", i);
    }
    printf("\n");
}

int main(void){
    generate_lucky_num(1000);
}
