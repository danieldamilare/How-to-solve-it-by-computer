#ifndef __QUICKSORT_H
#define __QUICKSORT_H

void quicksort(void * arr,
        int length,
        int elem_size,
        int compare(void const*, void const *));

#endif
