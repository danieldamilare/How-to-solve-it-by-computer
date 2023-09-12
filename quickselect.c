#include <stdio.h>

int partition(int [], int, int,  int);

int _quickselect(int arr[], int lower, int upper, int k){
    int part =  partition(arr, lower, upper,k );
    if(lower == upper)return arr[upper];
    printf("%d\n", part);
    if(part >= k){
        return _quickselect(arr, lower, part, k);
    }
    else if(part < k){
       return  _quickselect(arr, part+1, upper, k);
    }
}

int  quickselect(int arr[], int n, int k){
    return _quickselect(arr, 0, n-1, k-1);
   }

int partition(int arr[], int lower, int upper,  int k){
    //partition element by arr[k]
    int i = lower, j = upper;
    int pivot = arr[k];
    while(i < j){
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
        int temp = arr[i];
        if(i < j){
          arr[i] = arr[j];
          arr[j] = temp;
          i++, j--;
        }
    }
    return j;
}

void _quicksort(int arr[], int lower, int upper){
    if(lower < upper){
        int median = (upper+lower)/2;
        int  part = partition(arr,lower, upper, median);
        _quicksort(arr, lower, part);
        _quicksort(arr, part+1, upper);
    }
}

void quicksort(int arr[], int n){
    int lower = 0, upper = n-1;
    _quicksort(arr, lower, upper);
}

int main(void){
    int arr[] = {3, 5, 1, 12, 7, 2, 0};
    int size = sizeof(arr)/ sizeof(*arr);
    quicksort(arr, size);
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
    int j = quickselect(arr, size, 3);
    printf("%d is the smallest element\n", j);
}
