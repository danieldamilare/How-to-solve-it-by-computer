//algorithm solution for the dutch national flag problem
//
#include <stdio.h>

void partition_flag(int n, int arr[n]){
    int i = 0,j = 0, k = n -1;
    int temp;
    while(j <= k){
        if (arr[j] < 1){
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++, j++;
        }
        else if(arr[j] > 1){
            temp = arr[j];
            arr[j] = arr[k];
            arr[k] = temp;
            k--;
        }
        else j++;
    }
}
int main(void){
    int carr[] = {1, 0, 0, 2, 2, 0, 1, 2, 0, 0, 1, 1, 2, 0, 2, 2, 1, 1, 0, 0};
    int n  = sizeof(carr)/sizeof(carr[1]);
    partition_flag(n, carr);
    printf("{");
    for(int i = 0; i < n; i++){
        printf("%d ", carr[i]);
    }
    printf("}\n");
}
