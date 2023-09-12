#include <stdio.h>
#include <stdbool.h>

void generate_lucky_numbers(int n) {
    bool num[n+1];
    for (int i = 0; i < n; i++) {
        num[i] = true;
    }

    int count = 2;
    int i = 1;
    while (count <= n) {
        for (int j = i + count; j <= n; j += count) {
            num[j] = false;
        }
        
        int next_i = i + 1;
        while (!num[next_i]) {
            next_i++;
        }
        i = next_i;
        count = num[i] ? i : i + 1;
    }

    printf("Lucky numbers up to %d: ", n);
    for (int i = 1; i <= n; i++) {
        if (num[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n = 100;
    generate_lucky_numbers(n);
    return 0;
}

