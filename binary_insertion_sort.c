#include <stdio.h>

int bsearch(int arr[], int low, int high, int x){
    while(low < high){
        int mid = (low + high)/2;
        printf("mid: %d\n", mid);
        if(x > arr[mid]) low = mid+1;
        else high = mid;

        printf("Low: %d\n", low);
        printf("High: %d\n", high);
    }
    return low;
}

void insertion_sort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int temp = arr[i];
        int find = bsearch(arr, 0, i-1, temp);
        if (temp > arr[find]){
            for(int j = i-1; j > find; j--){
                arr[j+1] = arr[j];
            }
            arr[find+1] = temp;
        }
        else {
            for(int j = i-1; j >=find; j--){
                arr[j+1] = arr[j];
            }
            arr[find] = temp;
        }
    }
}

int main(void){
    int arr[] = {17, 21, 84, 33, 27, 91, 49, 43, 22, 21, 21, 3, 3,  3, 12, 15, 4, 8, 7, 9, 11};
    int n = sizeof(arr)/ sizeof(arr[1]);
    insertion_sort(arr, n);
    printf("sorted array: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}
