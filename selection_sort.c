#include <stdio.h>

void selection_sort(int arr[], int n){
    for(int i  = 0; i < n-1; i++){
        int min = arr[i], p = i;
        int sort = 1;
        for(int j = i+1; j < n; j++){
            if(arr[j] < min){
                sort = 0;
                min = arr[j];
                p = j;
            }
        }
        if(sort) return;
         arr[p] = arr[i];
         arr[i] = min;
    }
}

void sort_selection(int arr[], int n){
    int i, j;
    for(i  = 0, j = n-1; i < j; i++, j--){
        int max = arr[j],  min = arr[i], pmax = j, pmin =i;
        for(int k = i; k <=j; k++){
            if(arr[k] < min){
                min = arr[k];
                pmin = k;
            }
            else if(arr[k] > max){
                max = arr[k];
                pmax = k;
            }
        }
        if(pmin == j && pmax == i){
            arr[j] = max;
            arr[i] = min;
        }
        else{
            if(pmin == j && pmax != i){
                arr[pmin] = arr[i];
                arr[i] = min;
                int temp = arr[j];
                arr[j] = arr[pmax];
                arr[pmax] = temp;
            }
            else if( (pmax == i) && (pmin != j)){
                int temp = arr[j];
                arr[j] = arr[pmax];
                arr[pmax] = temp;

                temp = arr[i];
                arr[i] = arr[pmin];
                arr[min] = temp;
            }
            else {
                if(pmin != i){
                    int temp = arr[i];
                    arr[i] = arr[pmin];
                    arr[pmin]= temp;
                }
                else if(pmax != j){
                    int temp = arr[j];
                    arr[j] = arr[pmax];
                    arr[pmax] = temp;
                }
            }
        }
    }
}

int main(void){
    int arr[] = {20, 35, 18, 8, 14, 41, 3};
    sort_selection(arr, 7);
    for(int i  = 0; i < 7; i++)
        printf("%d ", arr[i]);
}
