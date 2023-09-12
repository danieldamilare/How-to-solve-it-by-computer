#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

double convert(char * str){
    bool is_dec = false;
    int dec_digit = 0;
    double result = 0;
    int len = strlen(str);
    for(int i = 0; i < len; i++){

        if (str[i] == '.') {
            is_dec = true; 
            continue; 
        }
        if (str[i] < '0' || str[i] > '9'){
            break;
        }

        if (is_dec){
            ++dec_digit;
            result += (str[i] - '0') / pow(10, dec_digit);
        }
        else {
            result = result * 10 + (str[i] - '0');
        }
    }
    return result;
}


int main(void){
    double num = convert("122323.55233223");
    printf("num: %lf\n", num);
}

