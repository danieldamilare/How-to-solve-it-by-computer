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


/* iterative solution for the combination algorithm
 */

void iter_combination(int n, int r){
    int arr[r];
    for(int i = 0;i < r; i++){
        arr[i] = i+1;
    }
    arr[r-1]--; 

    while(1){
        int flag = 1; 

        for(int j = r-1; j >= 0; j--){
            if(arr[j] <= n-r+j)
            {
                flag = 0;
                arr[j]++;
                for(int k =j+1; k < r; k++)
                    arr[k] = arr[k-1] + 1;
                break;
            }
        }
        for(int i = 0; i < r; i++)
            printf("%d ", arr[i]);
        printf("\n");

        if(flag) break;
    }
}


int main(void){
    /* combination(5, 3); */
    /* combination(8, 5); */
    iter_combination(5, 3);
}
