#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copy(int b[], int c[], int j, int bn, int *k){
    int i;
    for(i = j; i < bn; i++){
        c[(*k)++] = b[i];
    }
}

void shortmerge(int a[], int b[], int c[], int m, int *j, int *k){
    int i;
    i = 0;
    while(i < m){
        if (a[i] <= b[*j]){
            c[(*k)++] = a[i++];
        }
        else{
            c[(*k)++] = b[(*j)++];
        }
    }
}

void mergecopy(int a[], int b[], int c[], int m, int n){
    int i, j, k;
    i = 0, j = 0, k =0;
    if(a[m-1] <= b[i]){
        printf("a[m]: %d\n", a[m]);
        printf("a[m-1]: %d", a[m-1]);
        copy(a, c, i, m, &k);
        copy(b, c, j, n, &k);
    }
    else {
        shortmerge(a, b, c, m, &j, &k);
        copy(b, c, j, n, &k);
    }
}

void merge(int a[], int b[], int c[], int m, int n){
    if (a[m-1] <= b[n-1]) mergecopy(a, b, c, m, n);
    else mergecopy(b, a, c, n, m);
}


int main(void){
    srand(time(NULL));
    int compare(const void *, const void *);
    int m  = 10, n = 20;
    int a[m], b[n], c[m+n];
    for(int i = 0; i < m; i++){
        a[i] = rand()%100;
        b[i] = rand()%100;
    }
    for(int i = m; i < n; i++){
        b[i] = rand()%100;
    }
    qsort(a, m, sizeof(int),compare);
    qsort(b, n, sizeof(int), compare);
    printf("Array a: \n");
    /* int m = 5, n = 7; */
    /* int a[5] = {1, 2, 3, 4, 5}; */
    /* int b[7] = {7, 9, 10, 12, 14, 15, 17}; */
    /* int c[m+n]; */
    for(int i =0; i < m; i++)printf("%d ", a[i]);
    printf("\nArray b: \n");
    for(int i = 0; i < n; i++) printf("%d ", b[i]);
    merge(a, b, c, m, n);
    printf("\nArray c: \n");
    for(int i = 0; i < m+n; i++) printf("%d ", c[i]);
    printf("\n");
}

int compare(const void * s1, const void * s2){
    return *(int *)s1 - *(int *)s2;
}
