//iterative implementation of binary tree inorder traversal
//
#include <stdio.h>
#include <stdlib.h>

struct bin_tree{
    char value;
    struct bin_tree * left;
    struct bin_tree * right;
};

struct stack {
    struct bin_tree * arr[BUFSIZ];
    int count;
    int size;
};

typedef struct bin_tree bin_tree;
typedef struct stack stack;

void push( stack * sl, bin_tree * node ){
    if(sl->count == sl->size){
        fprintf(stderr, "stack full\n");
        return;
    }
    sl->arr[sl->count++] = node;
}

bin_tree * pop(stack *sl){
    if (sl->count == 0){
        fprintf(stderr, "stack empty\n");
        return NULL;
    }
    return sl->arr[--sl->count];
}

stack * create_stack(void){
    stack * sl = malloc(sizeof(*sl));
    sl->size = BUFSIZ;
    sl->count = 0;
    return sl;
}


void traverse_inorder(bin_tree * node){
    stack * temp = create_stack();
    if(node == NULL) return; 
    push(temp, node);
    bin_tree * temp_node = node;
    bin_tree * left = temp_node->left;
    while(temp->count > 0 || left != NULL){
        while(left != NULL){
            push(temp, left);
            left = left->left;
        }
        temp_node = pop(temp);
        printf("%c ", temp_node->value);
        left = temp_node->right;
    }
}


int main(void){
    bin_tree t1 = {'2', NULL, NULL};
    bin_tree t2 = {'3', NULL, NULL};
    bin_tree t3 = {'*', &t1, &t2};
    bin_tree t4 = {'8', NULL, NULL};
    bin_tree t5 = {'7', NULL, NULL};
    bin_tree t6 = {'/', &t4, &t5};
    bin_tree t7 = {'5', NULL, NULL};
    bin_tree t8 = {'*', &t7, &t6};

    bin_tree node = {'+', &t3, &t8};
    traverse_inorder(&node);
}
