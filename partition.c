#include <stdio.h>

int partition(int n, int arr[n], int x){
    //partition the arr so that the left hand side <= x and the right hand
    //size is greater than x.  return the  partition index;
    int temp, //temp variable for exchange;
        lower,  //current upper boundary for values in partition <= x
        upper;   //current lower boundary for values in partition > x
    lower = 0, upper = n -1;
    while(arr[lower] <= x) lower++;
    while(arr[upper] > x) upper--;
    while(lower < upper){
        printf("lower: %d, upper: %d\n", lower, upper);
        temp = arr[lower];
        arr[lower] = arr[upper];
        arr[upper] = temp;
        upper--, lower++;
        while(arr[lower] <= x)lower++;
        while(arr[upper] >x ) upper--;
    }
    printf("lower: %d, upper: %d\n", upper, lower);
    return lower;
}


int partition2(int n, int arr[n], int x) {
    int left = 0;
    int right = n - 1;

    while (1) {
        while (arr[left] <= x)
            left++;
        
        while (arr[right] > x)
            right--;
        
        if (left >= right)
            return right + 1;

        // Swap arr[left] and arr[right]
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

void partition3(int n, int arr[n], int part){
    int lo = -1;
    for(int j = 0; j < n; j++){
        if(arr[j] <= part){
            lo++;
            int temp = arr[lo];
            arr[lo] = arr[j];
            arr[j] = temp;

        }
    }

}


int main(void){
    int arr[] ={5, 6, 7, 15, 18,  2, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[1]);
    partition(n, arr, 5);
    printf("{");
    for(int i = 0; i< n; i++){
        printf("%d ", arr[i]);
    }
    printf("}\n");
}
