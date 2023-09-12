#include <stdio.h>

int partition(int arr[], int low, int high){
    void swap(int [], int , int);
    int part = (low + high) / 2;
    int x = arr[part];
    printf("x: %d\n\n\n", x);
    int i = low, j =  high;

    while(i < j && arr[i] < x ) i++;
    while(i < j && arr[j] > x) j--;

    while(i < j){
        swap(arr, i, j);
        i++, j--;
        while(i < j && arr[i] < x) i++;
        while(i < j && arr[j] > x) j--;
    }
    return j;
}

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void qsort2(int arr[], int n){
    int left, right, middle, stacktop, stack[20];
    stacktop = 2;
    stack[0] = 0;
    stack[1] = n-1;
    while(stacktop > 0){
        right = stack[--stacktop];
        left = stack[--stacktop];

        while(left < right){
            middle = (left+ right)/2;
            int new =partition(arr, left, right);
            if(new-1 < middle ){
                stack[stacktop++] = new;
                stack[stacktop++] = right;
                right = new-1;
            }
            else {
                stack[stacktop++] = left;
                stack[stacktop++] = new-1;
                left = new;
            }
        }
    }
}

void qsort(int arr[],int  left, int right){
    if(left <= right){
        int pi = partition(arr, left, right);
        qsort(arr, left, pi);
        qsort(arr, pi+1, right);
    }
}


int main(void){
    int arr[] = {2, 3, 5, 12, 10,  17, 8, 15, 4, 3, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    qsort(arr,0, n-1);
    for(int i =0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
