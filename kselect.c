#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

int kselect(int n, int arr[n], int k){
    int i, j, l, u, x, t;
    k--;
    l = 0, u = n -1;
    while(l < u){
        i = l;
        j = u;
        x = arr[k];
        while(i <= k && j >= k){
            while(arr[i] < x)i++;
            while(arr[j] > x) j--;
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++, j--;
        }
        printf("After partition: \n[");

        for(int i = l; i <= u; i++) printf("%d ", arr[i]);
        printf("]\n");

        if (j < k) l = i;
        if (i > k) u = j;
    }
    return arr[k];
}

void create_rand_arr(int ** arr, int *n){
    *n = rand()%40;
    *arr = malloc(*n * sizeof(int));
    for(int i = 0; i < *n; i++){
       (*arr)[i] = rand()%40;
    }
}

int main() {
    int arr[] = {3, 5, 1, 12, 7, 2, 0};
    int n = sizeof(arr)/ sizeof(*arr);
    int k = 4;
       printf("The %dk smallest value in the array: %d\n", 
                k, kselect(n, arr,  k));
        printf("\n\n");
    }


