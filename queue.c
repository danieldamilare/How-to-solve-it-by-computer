#include <stdio.h>
#include <stdlib.h>

#define QUEUE_LENGTH 3
struct queue{
    int arr[QUEUE_LENGTH];
    int rear;
    int front;
};

struct queue * create_queue(void){
    struct queue * nqueue = malloc(sizeof(struct queue));
    if(nqueue == NULL){
        return NULL;
    }
    nqueue->front = -1;
    nqueue->rear = -1;
    return nqueue;
}

int insert_queue(int data, struct queue * nqueue){
    printf("rear: %d\n", nqueue->rear);
    if(nqueue == NULL){
        return -1;
    }
    if(nqueue->front == -1 && nqueue->rear == -1){
        nqueue->front = 0;
        nqueue->rear =  0;
    }

    else if( ((nqueue->rear + 1) % QUEUE_LENGTH ) == nqueue->front){
        printf("Queue Full\n");
        return -1;
    }
    else{
        nqueue->rear = ((nqueue->rear + 1) % QUEUE_LENGTH );
    }
    nqueue->arr[nqueue->rear] = data;
    return 1;
}

int delete_queue(struct queue * nqueue){
    printf("front %d\n", nqueue->front);
    if(nqueue == NULL){
        return -1;
    }
    if(nqueue->front == nqueue->rear){
        printf("Queue Empty\n");
        nqueue->rear = -1;
        nqueue->front = -1;
        return -1;
    }
    else{
        nqueue->front = (nqueue->front + 1) % QUEUE_LENGTH;
    }
    return 1;
}

void list_queue(struct queue * nqueue){
    if(nqueue == NULL){
        return;
    }
    printf("[");
    int i;
    for(i = 0; i < QUEUE_LENGTH-1; i++ ){
        printf("%d, ", nqueue->arr[i]);
    }
    printf("%d]\n", nqueue->arr[i]);
}

int main(void){
    char buf[32];
    int option;
    printf("***********QUEUE PROGRAM **********\n");
    printf("Option:\n1.\tCreate Queue\n2.\tInsert to Queue\n3.\tDelete from queue\n4.\tList queue\n5.\tExit\n");
    struct queue * nqueue = NULL;
       
   do{
        printf("Enter option: ");
        fgets(buf, 32, stdin);

        if(sscanf(buf, "%d", &option) != 1){
            printf("Invalid option\n");
            continue;
        }

        int data;

        switch(option){
            case 1:
                nqueue = create_queue();
                if(nqueue == NULL){
                    printf("Error creating queue\n Exiting...\n");
                    option = 5;
                    continue;
                }
                printf("Queue created successfully\n");
                break;

            case 2:
                if(nqueue == NULL){
                    printf("You have to create a queue first before inserting\n");
                    continue;
                }
                printf("Enter value to add to queue: ");
                fgets(buf, 32, stdin);
                if(sscanf(buf, "%d", &data) != 1){
                    printf("You can only enter numeric data\n");
                }
                else{
                    if(insert_queue(data, nqueue) == 1){
                        printf("data inserted successfully\n");
                        continue;
                    }
                }
                break;

            case 3:
                if(nqueue == NULL){
                    printf("You have to create a queue first before deleting\n");
                    continue;
                }
                if(delete_queue(nqueue) == 1){
                    printf("data deleted successfully\n");
                }
                break;

            case 4:
                if(nqueue == NULL){
                    printf("You have to create a queue first before listing\n");
                    continue;
                }
                list_queue(nqueue);
                break;
            case 5:
                continue;

            default:
                printf("You entered an invalid option\n");
                continue;
        }
    } while(option != 5);
}
