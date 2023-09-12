#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int  _base10_convert(char * str, int input_base){
    bool is_base = 1;
    int ndigit = 0;
    int npow = 0;
    int result_digit = 0;
    while(str[ndigit]){
        
        if (str[ndigit] >= '0' && str[ndigit] <= '9'){
            result_digit = result_digit * input_base + (str[ndigit] - '0') ;
            printf("result_digit: %d, str[ndigit]: %d\n", result_digit, str[ndigit] - '0');
        }

        else if (str[ndigit] < 'A' || str[ndigit] > 'Z'){
            is_base = 0;
            break;
        }
        else {
            if((str[ndigit] - 'A') + 10 >= input_base){
                is_base = 0;
                break;
            }
            result_digit =  result_digit * input_base + ((str[ndigit] - 'A') + 10);
        }
        ndigit++;
    }
    if (!is_base) return 0;
    return result_digit;
}

char * base_convert(char * input, int input_base,  int output_base){
    //accept n the integer in base input base notation to be converted into a number of base output_base
    char * reverse(char *);
    char * new_base = (char *) malloc(100);
    memset(new_base, 0, 100);
    int i = 0; //current position in the base
    int n =  _base10_convert(input, input_base); //base 10 representation of the input character
    while(n){
        int rem;
        rem = n % output_base;
        if (rem >= 10){
            new_base[i++] = '0' + rem + 7;
        }
        else {
            new_base[i++] = '0' + rem;
        }
        n /= output_base;
    }
    reverse(new_base);
    return new_base;
}

char * reverse (char * str){
    int i = 0;
    int j = strlen(str)-1;
    while (i < j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++, j--;
    }
    return str;

}

int main(void){
    char * word = strdup("Daniel Damilare\n");
    char * n_base = base_convert("A", 16, 2);
    printf("%s\n", n_base);
    
}
