#include <stdio.h>
int random(int seed){
    static int x  = 0;
    if(!x)x = seed;
    int a, b, m;
    m = 4096;
    b = 863, a = 109;
    x = (a * x + b) % m;
    return x;
}

int main(void){
    for(int i = 0; i < 100; i++){
        int x = random(20);
        printf("random: %d\n", x);
    }
}
