#include <stdio.h>
#include <stdlib.h>


typedef struct queue{
    struct list * rear;
    struct lsit * front;
} QUEUE;

struct list {
    int data;
    struct list * next;
}

QUEUE * create_queue(void){
    QUEUE * queue = malloc(sizeof(QUEUE));
    queue->rear = NULL;
    queue->front = NULL;
}

int insert_queue(int data, QUEUE * queue){
    
    if(queue->front == NULL && queue==NULL)

}
