//a pattern matching function 
#include <string.h>

void computelps(char * pattern, int arr[]){
    //accept an array arr that is of the length of pattern and fill the array
    //with the lps value for pattern
    int patlen = strlen(pattern);
    arr[0] = 0;
    int len = 0, i  = 1;
    while(i < patlen){
        if(arr[i] == arr[len])
            arr[i++] = arr[++len];
        else if(len != 0)
            len--;
        else 
            arr[i++] = 0;
        
    }
}
