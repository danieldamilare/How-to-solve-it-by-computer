#include <stdio.h>

void pet(int n, int r){
    void gen(int, int,  int[], int);
    //generate an unrestricted permutation of r in n
    int arr[r];
    gen(n, r, arr,0);
}


void gen(int n, int r, int arr[r], int k){
    static int total = 0;
    arr[k] = n+1;
    while(arr[k] > 1){
        arr[k]--;
        /* additional optimization here */
        if(k < r-1)
        {
            gen(n, r, arr, k+1);
        }
        else
        {
            total++;
            for(int i = 0; i < r; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }
    }
    printf("total line: %d\n", total);
}


//permutation not so efficient implementation
void perm(int n, int k){
    int arr[k];
    for(int i =  0; i < k; i++) arr[i] = 1;

    while(1){
        int flag = 1;
        for(int i = k-1; i >= 0; i--){
            if(arr[i] < n)
            {
                flag = 0;
                arr[i]++;
                for(int j = i+1; j < k; j++){
                    arr[j] = 1; 
                }
                break;
            }
        }
        for(int count  = 0; count < k; count++) printf("%d ", arr[count]);
        printf("\n");
        if(flag) break;
    }
}

int main(void){
    pet(8, 3);
}

