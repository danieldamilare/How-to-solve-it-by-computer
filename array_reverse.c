int  duplicates(int n, int arr[n]){
    int i = 0, // array index
        j = 1; //number of unique elements

    for(int i = 0; i < n-1;){
            while(arr[i] == arr[i+1]) i++; //if not unique search for the first
            if(i < n-1)
                arr[j++] = arr[++i];        //store the unique element in the next position of unique index
    }

    return  j;
}

int dup(int n, int arr[n]){
    int i, j;
    i = 1;
    while (arr[i-1] != arr[i]) i++;
    if (arr[i-1] != arr[i]) i++;
    j = i -1;
    while (i < n){
        i++;
        if(arr[i-1] != arr[i]){
            j++;
            arr[j] = arr[i];
        }
    }
    return j;
}

int dup_k(int n, int arr[n], int k){
    //remove from arr[n] all numbers that occurs k times
    int i = 0, j = 1;
    int count = 1;
    while(i < n-1) {
        while(arr[i] == arr[i+1]){
            i++, count++;
            printf("count: %d\n", count);
        }
        if (count < k) count = 1;
        else {
            i -= count -1;
            break;
        }
        i++;
    };
    printf("i: %d, n: %d\n", i, n);
    j = i+1;
    while(i < n- 1){
        int count = 1;
        while(arr[i] == arr[i+1]){
            count++, i++;
        }
        if (count < k){
            i -=count-1;
        }
        if (i < n -1)
            arr[j++] = arr[++i];
    }
    return j;
}

int main(void){
    int arr[] =  {2, 2, 8, 15, 23, 23, 23, 23, 26, 29, 29, 29, 29,  30, 32, 32, 34, 34,34};
    int num = dup_k(sizeof(arr)/ sizeof(arr[1]), arr, 2);
    for(int i = 0; i < num; i++) printf("%d ", arr[i]);
    printf("\n");
}

