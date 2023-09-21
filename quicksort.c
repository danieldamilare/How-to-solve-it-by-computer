#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


void print_arr(void * arr, int size){
    int * r_arr = arr;
    for(int i =0; i < size; i++ ){
        printf("%d ", r_arr[i]);
    }
    printf("\n");
}

void print_chr_arr(void * arr, int size){
    char ** carr = arr;
    for(int i = 0; i < size; i++){
        printf("%s ", carr[i]);
    }
    printf("\n");
}



int swap(void * elem1, void * elem2, int elem_size){
    printf("swapping: %s and %s\n",  *(char **)elem1, *(char **)elem2);

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

int cmp(const void * elem1, const void * elem2){
    int i  = *(int *) elem1,
        j = * (int *) elem2;
    /* printf("in compare:i:  %d, j: %d\n", i, j); */
    if(i > j) return 1;
    else if (i < j) return -1;
    else return 0;
}

int cmp_str(const void * elem1, const void * elem2){
    char * str1 = * (char **) elem1; 
    char * str2 = * (char **) elem2; 
    printf("in compare function\n");
    printf("str1: %s, str2: %s\n", str1, str2);
    return strcmp(str1, str2);

}

void quicksort(void * arr, int length, int elem_size, int compare(const void * , const void *)) {
    print_chr_arr(arr, length);
    char * chr_arr = arr;
    if(length <= 1) return;
    int pivot = partition(arr, length, elem_size, compare);
    print_chr_arr(arr, length);
    printf("pivoit: %d, length: %d\n ", pivot, length);
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

// Function to run comprehensive tests on quicksort
void test_quicksort_comprehensive() {
    int unsorted_arr[] = {5, 6, 7, 15, 18, 2, 8, 9, 10};
    int n = sizeof(unsorted_arr) / sizeof(unsorted_arr[0]);

    // Test 1: Sort an unsorted array
    printf("Test 1: Sort an unsorted array\n");
    printf("Before sorting: ");
    print_arr(unsorted_arr, n);
    quicksort(unsorted_arr, n, sizeof(int), cmp);
    printf("After sorting: ");
    print_arr(unsorted_arr, n);

    // Test 2: Sort an already sorted array
    printf("\nTest 2: Sort an already sorted array\n");
    printf("Before sorting: ");
    print_arr(unsorted_arr, n);
    quicksort(unsorted_arr, n, sizeof(int), cmp);
    printf("After sorting: ");
    print_arr(unsorted_arr, n);

    // Test 3: Sort a reverse-sorted array
    printf("\nTest 3: Sort a reverse-sorted array\n");
    int reverse_sorted_arr[n];
    generate_reverse_sorted(reverse_sorted_arr, n);
    printf("Before sorting: ");
    print_arr(reverse_sorted_arr, n);
    quicksort(reverse_sorted_arr, n, sizeof(int), cmp);
    printf("After sorting: ");
    print_arr(reverse_sorted_arr, n);

    // Test 4: Sort an array with duplicate elements
    printf("\nTest 4: Sort an array with duplicate elements\n");
    int arr_with_duplicates[] = {3, 1, 2, 3, 5, 4, 1, 2};
    printf("Before sorting: ");
    int arr_with_duplicates_length = sizeof(arr_with_duplicates) / sizeof(arr_with_duplicates[0]);
    print_arr(arr_with_duplicates, arr_with_duplicates_length);
    quicksort(arr_with_duplicates, arr_with_duplicates_length, sizeof(int), cmp);
    printf("After sorting: ");
    print_arr(arr_with_duplicates, arr_with_duplicates_length);

    // Test 5: Sort an array with a single element
    printf("\nTest 5: Sort an array with a single element\n");
    int single_element_arr[] = {42};
    quicksort(single_element_arr, 1, sizeof(int), cmp);
    print_arr(single_element_arr, 1);

}

int main(void){

    //testing strings
    char * name[] = {"joseph", "daniel", "omololu", "Asaolu", "Adebowale", "bolu", "victor", "Tinubu"};

    int name_size = sizeof(name)/sizeof(name[1]);
    printf("Before sorting: ");
    print_chr_arr(name, name_size);
    quicksort(name, name_size, sizeof(char *), cmp_str);
    printf("After sorting: ");
    print_chr_arr(name, name_size);
}


