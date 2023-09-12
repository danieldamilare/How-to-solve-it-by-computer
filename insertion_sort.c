#include <stdio.h>

void insertion_sort(int arr[], int n){
    int min = arr[0], pmin = 0, i;
    for( i  = 0; i < n; i++){
        if(arr[i] < min){
            min = arr[i], pmin = i;
        }
    }
    arr[pmin] = arr[0];
    arr[0] = min;

    for(int i = 2; i < n; i++){
        int tmp = arr[i], j;
        for( j = i-1; tmp < arr[j]; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = tmp;
    }
}

void insert_sort_mod(int arr[], int n){
    int last_insertion = 1;
    for(int i = 1; i < n; i++){
        int temp = arr[i];
        int j;
        if(temp > arr[last_insertion]){
            for(j = last_insertion; temp > arr[j]; j++);
        }
        else{
            for(j = 0; temp > arr[j]; j++);
        }
        for(int k = i-1; k >= j; k--){
            arr[k+1] = arr[k];
        }
        arr[j] = temp;
        int last_insertion = j;
    }
}

void insert_sort(int arr[], int n){
    int min = arr[0],  pmin =0;
    for(int i =0; i < n; i++){
        if(arr[i] < min){
            min = arr[i];
            pmin = i;
        }
    }
    arr[pmin] = arr[0];
    arr[0] = min;
    int max = arr[0], pmax =0;
    for(int i  = 0; i < n ; i++){
         if(arr[i] > max){
            max = arr[i];
            pmax = i;
        }
    }
    arr[pmax] = arr[n-1];
    arr[n-1] = max;
 
    for(int i = 2, j = n-3; i <= n-1; i++, j-- ){
        int temp1 = arr[i], temp2,  x, y;
        for( x = i-1; temp1< arr[x]; x--){
            arr[x+1] = arr[x];
        }
        arr[x+1] = temp1;
        temp2 = arr[j];
        for(y = j+1; temp2 > arr[y]; y++){
            arr[y-1] = arr[y];
        }
        arr[y-1] = temp2;
    }
}


int main(void){
    int arr[] = {20, 35, 18, 8,  14, 41, 3, 84, 1, 92, 78, 65, 12, 19, 17, 34};
    insert_sort(arr, 16);
    printf("arr: \n");
    for(int i = 0; i < 16; i++){
        printf("%d ", arr[i]);
    }
}



