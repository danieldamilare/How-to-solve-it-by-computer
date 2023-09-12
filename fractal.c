#include <stdio.h>
#include <string.h>
#include <math.h>

#define gen_pattern(n) fractal(n, "A", 'A', (pow(2, n)-1))

void fractal(int, char *, char, int total_len);

void fractal(int n, char * cur_pattern, char cur_char, int total_len){
    if(n == 1 || cur_char == 'z'){
        printf("%s\n", cur_pattern);
        return;
    }
    else{
        int space_print = (total_len - strlen(cur_pattern))/2;
        for(int i = 0; i < space_print; i++)printf(" ");
        printf("%s\n", cur_pattern);
        int len = strlen(cur_pattern) * 2 + 2;
        char arr[len+1];
        sprintf(arr, "%s%c%s", cur_pattern, cur_char+1, cur_pattern);
        fractal(n-1, arr, cur_char+1, total_len);
    }
}

int main(void){
    gen_pattern(7);
}
