#include <stdio.h>

void insertion_sort(int arr[], int n) {
    int inc = n / 2;
    while (inc > 0) {
        for (int i = inc; i < n; i++) {
            int current = arr[i];
            int j = i;
            while (j >= inc && arr[j - inc] > current) {
                arr[j] = arr[j - inc];
                j -= inc;
            }
            arr[j] = current;
        }
        inc /= 2;
    }
}

int main(void) {
    int arr[] = {20, 35, 18, 8, 14, 41, 3, 39, 12, 17, 15, 54, 68, 71, 28, 1, 17, 52, 89, 12, 19, 27, 60, 71, 32, 31, 28};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    insertion_sort(arr, n);
    
    printf("arr: \n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
