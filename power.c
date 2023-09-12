#include <stdio.h>

int power_2(int number,int power){
    int psequence = number;
    int product = 1;
    while(power){
        if(power & 1)
        {
            product *= psequence; 
        }
        psequence *= psequence;
        power /= 2;       
    }
    return product;

}
int power_3(int number, int power){
    int sequence = number;
    int product = 1;
    while (power){
        switch (power % 3){
            case 2:
                product *=( sequence * sequence);
                break;
            case 1:
                product *= sequence;
                break;
        }
        sequence = sequence * sequence * sequence;
        power /= 3;
    }
    return product;
}

int multiply(int number1, int  number2){
    int result = 0;
    while(number1){
        if(number1 & 1) result += number2;
        number2=number2 << 1;
        number1 = number1  >> 1;
        printf("number2, %d, number1: %d\n", number2, number1);
    }
    return result;
}

int test(int number){
    return (power_2(2, (number -1)) % number) == 1;
}

int main(void){
    printf("2 ** 8 is %d", power_3(24, 2));
    printf("20 * 123 is %d\n", multiply(180, 180));
}
