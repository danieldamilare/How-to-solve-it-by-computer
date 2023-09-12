#include <stdio.h>

void exchange(int a, int b){
    //code to exchange a and b without using a temporary variable
    printf("Before Excange: a: %d, b : %d\n", a , b);
    a *= b;
    b = a/ b;
    a = a/ b;
    printf("After Exchange: a: %d, b: %d\n", a, b);
}


int main(void){
    int a  =20;
    int b = 30;
    exchange(a, b);
}
