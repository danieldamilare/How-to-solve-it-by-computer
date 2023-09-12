#include <stdio.h>
#include <stdarg.h>
int digit_reverse(int n){
    //accept n, integer and output a number that is the reverse of n
    int reverse= 0;
    while(n > 0){
        reverse = reverse * 10 + (n % 10);
        n /= 10;
    }
    return reverse;
}

int count_digit(int n){
    int count = 0;
    while (n > 0){
        n /=10;
        count++;
    }
    return count;
}

int add_digit(int n){
    int sum = 0;
    while (n > 0){
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

int convert_arr_num(int n, ...){
    long long output = 0;
    va_list ptr;
    va_start(ptr, n);
    for(int i = 0; i < n; i++){
        output = output * 10+ va_arg(ptr, int);
    }
    va_end(ptr);
    return output;
}




int main(void){
    printf("reverse of: 12345: %d\n", digit_reverse(12345));
}
