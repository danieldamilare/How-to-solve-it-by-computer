#include <stdio.h>

void insertion_sort(int arr[], int n){
    int inc = n;
    while(inc > 0){
        inc /=2;
        int k;
        for(int j = 0; j < inc; j++){
           k = j+inc;
           while(k < n){
               int current = arr[k];
               int l = k-inc;
               while(l >= j && current < arr[l]){
                   arr[l+inc] = arr[l];
                   l -= inc;
               }
               arr[l+inc] = current;
               k += inc;
           }
        }

    }
}

int main(void){
    int arr[] = {20, 35, 18, 8, 14, 41, 3, 39, 12, 17, 15, 54, 68};
    insertion_sort(arr, 13);
    printf("arr: \n");
    for(int i = 0; i < 13; i++) printf("%d ", arr[i]);
    printf("\n");
}
