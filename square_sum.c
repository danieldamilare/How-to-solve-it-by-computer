#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

unsigned int sum_of_squares(unsigned int n){
  int arr[n+1];
  arr[0] = 0, arr[1] = 1;
  for(int i = 2; i < n+1; i++){
    int sqrti = sqrt(i)+1;
    arr[i] = i;
    for(int j = 0; j < sqrti; j++){
        if(j * j > i) break;
        int square_sum = 1 + arr[i - (j * j)];
        arr[i] = square_sum > arr[i] ? arr[i] : square_sum;
    }
  }
  return arr[n];
}

int main(void){
    sum_of_squares(17);
}
