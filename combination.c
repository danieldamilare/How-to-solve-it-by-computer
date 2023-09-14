/*
 * Written by Daniel Joseph 
 * program to recursively generate the combination of n integers taken r
 * at a time
 */

#include <stdio.h>

//marco helepr for the generator function
#define combination(n, r) if(1){int arr[(r)] = {0};\
    gen(arr, (n), (r), 0);}

/* Print the combination of n integers taken r at a time at each point of iteration k 
 * Design to be used with the combination function header
 */
void gen(int arr[], int n, int r, int k ){
    arr[k] = (k > 0? arr[k-1] : 0); //assign the current array column to the prev value

    while(arr[k] <= (n-r)+k){ 
        arr[k]++;
        if (k < r-1)
            gen(arr, n, r, k+1);
        
        else {
            for(int i = 0; i < r; i++){
                printf("%d, ", arr[i]);
            }
            printf("\n");
        }
    }
}


int main(void){
    combination(5, 3);
    combination(8, 5);
}
