#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


int swap(void * elem1, void * elem2, int elem_size){

    void * temp  = malloc(elem_size);  
    if(temp ==NULL) return -1;
    memcpy(temp, elem1, elem_size);
    memcpy(elem1, elem2, elem_size);
    memcpy(elem2, temp, elem_size);
    free(temp);
    return 1;
}

int partition(void * arr, 
        int length,
        size_t elem_size, 
        int compare(void const * elm1, void const  * elm2)){
    assert(elem_size != 0 && length != 0);
    int mid = length/2,
       i = 0, 
       j = length -1;

    char * chr_arr; 
    void * midptr = malloc(elem_size);
    if(midptr == NULL) return -1;

    chr_arr  = arr;
    memcpy(midptr, &chr_arr[mid*elem_size], elem_size);
    while(compare(&chr_arr[i * elem_size], midptr) < 0) i++;
    while(compare(&chr_arr[j * elem_size], midptr) > 0) j--; 

    while(i < j){
        int ret =swap(&chr_arr[i*elem_size], &chr_arr[j*elem_size], elem_size);
        if(ret == -1){
            free(midptr);
            return -1;
        }

        i++, j--;
        while(compare(&chr_arr[i * elem_size], midptr) < 0) i++;
        while(compare(&chr_arr[j * elem_size], midptr) > 0) j--; 
    }

    free(midptr);
    return j;
}


void quicksort(void * arr, int length, int elem_size, int compare(const void * , const void *)) {
    char * chr_arr = arr;
    if(length <= 1) return;
    int pivot = partition(arr, length, elem_size, compare);
    if(pivot+1 == length) return; //if already sorted
    quicksort(chr_arr, pivot+1, elem_size, compare);
    quicksort(&chr_arr[(pivot+1) * elem_size], length -(pivot+1), elem_size, compare);
}

// Function to generate a reverse-sorted array
void generate_reverse_sorted(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = length - i;
    }
}

// Function to generate an array with duplicate elements
void generate_array_with_duplicates(int *arr, int length) {
    int half_length = length / 2;
    for (int i = 0; i < length; i++) {
        arr[i] = i < half_length ? i + 1 : i - half_length + 1;
    }
}
