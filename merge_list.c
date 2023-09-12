/* A program to merge two linked list   *
 * Written by Daniel                    */
#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int value;
    struct list * next;
} _list;

typedef struct llist{
    _list * llist;
    _list * end;
} LIST;

void  append(LIST *, int);
void insert(LIST *, int, int);
void delete(LIST * list, int value);
LIST * merge_list(LIST * l1, LIST * l2);

_list * create_list(int value){
    struct list * new_list = malloc(sizeof(_list));
    new_list->next = NULL;
    new_list->value = value;
    return new_list;

}

void insert(LIST * list, int value, int place){
    if(place < 0){
      append(list, value);
      return;
    }
    
    if(place == 0){
        struct list * new_list = create_list(value);
        new_list->next = list->llist;
        list->llist = new_list;
        return;
    }
    struct list * new_list = create_list(value);
    if(list->llist == NULL){
        list->llist  = new_list;
        list->end = new_list;
        return;
    }
    struct list * ptr = list->llist;
    int i;
    for(i = 1; i <(place-1) && ptr->next != NULL; i++, ptr = ptr->next){
    }
    if(ptr->next == NULL){
        ptr->next= new_list; 
        list->end = new_list;
    }
    else{
        struct list * temp = ptr->next;
        ptr->next = new_list;
        new_list->next = temp;
    }
}

void append(LIST * list, int value){
    struct list *new_list = create_list(value);
    if(list->end == NULL){
        list->llist = new_list;
        list->end = new_list;
        return;
    }
    list->end->next = new_list;
    list->end = new_list;
}

LIST * create_llist(void){
    LIST * return_list = malloc(sizeof(LIST));
    return_list->llist = return_list->end = NULL;
    return return_list;
}

void delete(LIST * list, int value){
    //remove first occurence of value;
    struct list * ptr = list->llist;
    while(ptr != NULL && ptr->next->value != value)
        ptr = ptr->next;
    if(ptr){
        struct list * temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
    }
}

 LIST * merge_list(LIST * l1, LIST * l2){
    struct list *list1 = l1->llist;
    struct list * list2 = l2->llist;
    struct list * return_list;
    struct list * merge;
    if(l1->end->value < list2->value){
        l1->end->next = list2;
        return l1;
    }
    else if(l2->end->value < list1->value){
        l2->end->next = list1;
        return l2;
    }
    else {
        if(list1->value <= list2->value){
            merge = list1;
            return_list = merge;
            list1 = list1->next;
        }
    
        else {
            merge = list2;
            return_list = merge;
            list2 = list2->next;
        }
    }
        while(list1 != NULL && list2 != NULL){
            if(list1->value <= list2->value){
                merge->next = list1;
                merge = merge->next;
                list1= list1->next;
            }
            else {
                merge->next = list2;
                list2= list2->next;
                merge = merge->next;
            }
        }
        if(list1) merge->next = list1;
        else if(list2) merge->next = list2;
        else merge->next = NULL;
        LIST * List = create_llist();
        List->llist = return_list;
        while(merge != NULL) merge = merge->next;
        List->end = merge;
        return List;
}

void print_list(LIST * ll){
    struct list *l = ll->llist;
    printf("[");
    while(l->next != NULL){
        printf("%d, ", l->value);
        l = l->next;
    }
    printf("%d]\n", l->value);
}
