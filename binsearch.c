#include <stdio.h>

int bsearch(int [], int, int, int);
int binsearch(int arr[], int n, int x){
    //the function accept an integer array of size n and 
    //perform a binary search for x. return the position of the least
    //element if not found
    int low = 0; 
    int high = n-1;
    return bsearch(arr, low, high, x);
}

int  bsearch(int arr[], int low, int high, int x){
    if(low > high) return -1;
    int mid = (low+high) /2;
    if(x == arr[mid]) return mid;
    printf("********MId: %d**********\n", mid);
    printf("********high: %d**********\n", high);
    printf("********low: %d**********\n\n\n", low);
    low = (x > arr[mid]) ? mid+1 : low;
    high = (x< arr[mid]) ? mid-1: high;
    return bsearch(arr, low, high, x);
}

int bin_search(int arr[], int n, int x){
    int low  = 0; 
    int high = n-1;
    int mid;
    while(low < high){
        mid = (low+high) /2;
        if(x > arr[mid]) low = mid+1;
        else  high = mid;
    }
    return low;
}

int main(void){
    int arr[] = {10, 12, 20, 23, 27, 30, 31, 39, 42, 44, 45, 49, 57,
                 63, 70};
    int n = sizeof(arr) / sizeof(*arr);
    int i = bin_search(arr, n, 23);
    printf("13 is found at position: %d\n", i);
    int j = bin_search(arr, n, 29);
    printf("29 is found at position: %d\n", j);
    return 0;
}
