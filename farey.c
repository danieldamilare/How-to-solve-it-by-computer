#include <stdio.h>

void generate_farey_sequence(int n){
    //generate the farey sequence of order n
    int a = 0, //first term numerator
        b = 1, //first term denominator
        c = 1, //second term numerator    
        d = n; //second term denominator

    while (c <= n){
        printf("%d/%d, %d/%d, ", a, b, c, d);
        a = (int)((n +b)/d) * c -a;
        b = (int)((n + b)/d) * d - b;
        c = (int)((n + d)/b) * a - c;
        d = (int)((n + d)/b ) * b - d;
    }
    printf("%d/%d\n", a, b);

}

int main(void){
    generate_farey_sequence(5);
}
