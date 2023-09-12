#include <stdio.h>
#include <stdbool.h>

int hashsearch(int table[], int position, int tablesize, int key){
    int  empty,  temp, start;
    bool found, active;
    active = true, found = false;
    start = key % tablesize;
    position = start;
    if(table[start] == key){
        active = false;
        found = true;
        temp = table[start];
    }
    else {
        temp = table[start];
        table[start] = key;
    }
    while(active){
        position = (position+1) % tablesize;
        if(table[position] == key){
            active = false;
            if(position != start) found = true;
        }
        else if (table[position] == empty) active = false;
    }
    table[start] = temp;
    return found;
}
