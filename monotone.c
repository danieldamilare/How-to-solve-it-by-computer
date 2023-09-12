#include <stdio.h>
int  monotone(int arr[], int n){
    void print_sequence(int [], int [], int n, int );
    int index[n], i, j, maxj, pmax;
    int current, max_length;

    index[0] = 1;
    pmax = 0;
    max_length = 1;
    for(i = 1; i < n; i++){
        current = arr[i];
        if(current < arr[pmax]){
            maxj = 1;
            for(j = 1; j < i; j++){
                if(arr[j] < current){
                    if(maxj < index[j]) maxj = index[j];
                }
            }
            index[i] = maxj+1;
            if(index[i] > max_length){
                max_length = max_length + 1;
                pmax = i;
            }
        }
        else{
            max_length++;
            index[i] = max_length;
            pmax = i;

        }
    }
    print_sequence(index, arr, n, max_length);
    return max_length;
}

void print_sequence(int index[], int arr[], int n, int max_length){
    int longest_subsequence[max_length];
    int current_length = max_length;
    int current_index = n-1;
    for(int i = n-1; i >=0; i--){
        if(index[i] == current_length && (current_index = n-1 || arr[i] < arr[current_index])){
            longest_subsequence[--current_length] = arr[i];
            current_index =i;
        }
    }
    printf("Longest Monotone subsequence: ");
    for(int i = 0; i < max_length; i++){
        printf("%d ", longest_subsequence[i]);
    }
    printf("\n");
}

int main(void){
   monotone((int []){1, 2, 9, 4, 7, 3, 11, 8, 14, 6}, 10); 
}
