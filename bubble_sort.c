#include <stdio.h>

void bubblesort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int sorted = 1;
        for(int j = 0; j < (n - (i+1)); j++){
            if(arr[j] > arr[j+1]){
                sorted = 0;
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
        if(sorted)return;

    }
}

int main(void){
    int arr[] = {20, 35, 18, 8,  14, 41, 3, 24};
    bubblesort(arr, 8);
    printf("arr: \n");
    for(int i = 0; i < 8; i++){
        printf("%d ", arr[i]);
    }
}

