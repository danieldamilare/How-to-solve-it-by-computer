#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int b[], int c[], int m, int n){
    int i = 0, j = 0, k = 0;
    while(i < m && j < n){
        if(a[i] <= b[j]){
            c[k++] = a[i++];
        } 
        else{
            c[k++] = b[j++];
        }
    }
    if(i < m){
        printf("\nI: %d < m:%d\n", i , m);
        printf("\nj: %d < n:%d\n", j , n);
        while(i < m) c[k++] = a[i++];
    }
    else {
        while(j < n) c[k++] = b[j++];
    }

}

void merge_char(char *a, char * b, char *c){
    char * arr1 = a, *arr2 = b;
    while(*arr1 && *arr2){
        if(*arr1 < *arr2){
            *c++ = *arr1++;
        }
        else{
            *c++ = *arr2++;
        }
    }
    while(*arr1) *c++ = *arr1++;
    while(*arr2) *c++ = *arr2++;

}

void merge_three(int a[], int b[], int c[], int d[],
        int l, int m, int n){
    int i = 0, j = 0, k= 0, x = 0;

    while(i < l && j < m && k < n){
        int min = a[i];
        if(b[j]< min) min = b[j];
        if(c[k] < min) min = c[k];

        if(min == a[i]){
            d[x++] = a[i++];
        }
        else if(min == b[j]){
            d[x++] = b[j++];
        }
        else {
            d[x++] = c[k++];
        }
    }
    if(i == l){
        while(j < m && k < n){
            if(b[j] > c[k]){
                d[x++] = c[k++];
            }
            else{
                d[x++] = b[j++];
            }
        }
        while(j < m) d[x++] = b[j++];
        while(k < n) d[x++] = c[k++];
    }
    else if(j == m){
        while(i < l && k < n){
            if(a[i] > c[k]){
                d[x++] = c[k++];
            }
            else{
                d[x++] = a[i++];
            }
        }
        while(i < l) d[x++] = a[i++];
        while(k < n) d[x++] = c[k++];
    }
    else if(k == n){
        while(i < l && j < m){
            if(a[i] > b[j]){
                d[x++] = b[j++];
            }
            else{
                d[x++] = a[i++];
            }
        }
        while(i < l) d[x++] = a[i++];
        while(j < m) d[x++] = b[j++];
    }

}

void merge_3(int a[], int b[], int c[], int d[],
        int l, int m, int n){
    int arr[l+m];
    merge(a, b, arr, l, m);
    merge(arr, c, d, l+m, n);

}

int main(void){
    srand(time(NULL));
    int compare(const void *, const void *);
    int m  = 10, n = 20;
    int a[m], b[n], c[m+n];
    int d[2 * (m+n)];
    for(int i = 0; i < m; i++){
        a[i] = rand()%100;
        b[i] = rand()%100;
    }
    for(int i = m; i < n; i++){
        b[i] = rand()%100;
    }
    for(int i  = 0; i < m+n; i++) c[i] = rand()% 100;
    qsort(a, m, sizeof(int),compare);
    qsort(b, n, sizeof(int), compare);
    qsort(c, m+n, sizeof(int), compare);
    printf("Array a: \n");
    /* int m = 5, n = 7; */
    /* int a[5] = {1, 2, 3, 4, 5}; */
    /* int b[7] = {7, 9, 10, 12, 14, 15, 17}; */
    /* int c[m+n]; */
    merge_3(a, b, c, d, m, n, m+n);
    for(int i =0; i < m; i++)printf("%d ", a[i]);
    printf("\nArray b: \n");
    for(int i = 0; i < n; i++) printf("%d ", b[i]);
    printf("\nArray c: \n");
    for(int i = 0; i < m+n; i++) printf("%d ", c[i]);
    printf("\n");
    printf("\nArray d: \n");
    for(int i = 0; i < 2 * (m+n); i++){
        printf("%d ", d[i]);
    }
    printf("\n");
}

int compare(const void * s1, const void * s2){
    return *(int *)s1 - *(int *)s2;
}
