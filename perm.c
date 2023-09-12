#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 10

typedef struct {
    int arr[MAX_SIZE];
    int size;
} Stack;

void initStack(Stack *s) {
    s->size = 0;
}

void push(Stack *s, int val) {
    if (s->size < MAX_SIZE) {
        s->arr[s->size++] = val;
    }
}

int pop(Stack *s) {
    if (s->size > 0) {
        return s->arr[--s->size];
    }
    return -1; // Return a sentinel value if stack is empty
}

bool isComplete(int arr[], int size, int k) {
    return size == k;
}

void printPermutation(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generatePermutations(int n, int k) {
    Stack stack;
    initStack(&stack);
    
    push(&stack, 1);
    
    while (stack.size > 0) {
        int partial[k];
        int partialSize = 0;
        
        int val = pop(&stack);
        
        while (val != -1) {
            partial[partialSize++] = val;
            
            if (isComplete(partial, partialSize, k)) {
                printPermutation(partial, partialSize);
            } else {
                for (int i = 1; i <= n; i++) {
                    bool isPresent = false;
                    for (int j = 0; j < partialSize; j++) {
                        if (partial[j] == i) {
                            isPresent = true;
                            break;
                        }
                    }
                    if (!isPresent) {
                        push(&stack, i);
                    }
                }
            }
            
            val = pop(&stack);
        }
    }
}

int main(void) {
    generatePermutations(5, 3);
    return 0;
}

