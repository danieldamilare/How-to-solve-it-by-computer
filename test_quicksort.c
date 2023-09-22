#include <stdio.h>
#include <setjmp.h>
#include <stdbool.h>
#include <signal.h>
#include <time.h> 
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "tester.h"
#include  "quicksort.h"

#define PRINT_TYPE(type, alias, type_str) \
    void print_##alias##_arr(void * arr, int size) { \
        type * ex_arr = arr; \
        for(int i = 0; i < size; i++) \
            printf("%" #type_str " ", ex_arr[i]); \
        printf("\n"); \
    }

#define CMP_TYPE(type, alias) \
   int cmp_##alias(void const * elem1,  void const * elem2){ \
       type e1 = * (type *) elem1; \
       type e2 = * (type * ) elem2; \
       if(e1 > e2) return 1; \
       else if(e1 < e2) return -1; \
       else return 0; \
   }

#define GEN_ARR_TYPE(type, func, alias) \
    type * gen_##alias##_arr(int length, int range1, int range2){\
        type * arr = malloc(length * sizeof(type)); \
        for(int i = 0; i < length; i++) \
            arr[i] = func(range1, range2); \
       return arr; \
    }

char * generate_random_string(int min, int max);
double generate_randnum(double range1, double range2);
int generate_randint(int range1, int range2);   
bool is_sorted(void * arr, int size, int elem_size, int cmp(void const *, void const * ));
long long generate_randlong(int, int);

CMP_TYPE(int, int)
CMP_TYPE(double, db)
CMP_TYPE(long, ld)

PRINT_TYPE(int, int, d)
PRINT_TYPE(double, db, lf)
PRINT_TYPE(long, ld, ld)
PRINT_TYPE(char *, str, s)

GEN_ARR_TYPE(char *, generate_random_string, str)        
GEN_ARR_TYPE(int, generate_randint, int)
GEN_ARR_TYPE(double, generate_randint, db)
GEN_ARR_TYPE(long long, generate_randlong, long)




int cmp_str(const void * elem1, const void * elem2){
    char * str1 = * (char **) elem1; 
    char * str2 = * (char **) elem2; 
    return strcmp(str1, str2);

}

double generate_randnum(double range1, double range2){
    /* generate random integers betwween range 1 - range2*/
    double diff = range2 -range1;
    double randnum = range1+((double)rand() /((double) RAND_MAX/diff));
    return randnum;
}

int generate_randint(int range1, int range2){
    return (int) generate_randnum(range1, range2);
}

long long generate_randlong(int min, int max){
    long long random =
  (((long long) rand() <<  0) & 0x000000000000FFFFull) |
  (((long long) rand() << 16) & 0x00000000FFFF0000ull) |
  (((long long) rand() << 32) & 0x0000FFFF00000000ull) |
  (((long long) rand() << 48) & 0xFFFF000000000000ull);
    return random;

}

char * generate_random_string(int min, int max ){
    int length = generate_randint(min, max);
    char * new_str = malloc(length + 1);
    for(int i = 0; i < length; i++){
        new_str[i] = 'a'+ generate_randint(0, 26);
    }
    return new_str;
}




bool is_sorted(void * arr, int size, int elem_size, int cmp(void const *, void const * )){
    char * ch_arr = arr;
    for(int i = 0; i < size-1; i++){
        int j = i+1;
        if(cmp(&ch_arr[i*elem_size], &ch_arr[j*elem_size]) > 0)
            return false;
    }
    return true;
}



int main(int argc, char *argv[]){
    srand(time(NULL));
    int test_stress;

    if(argc > 1)
        test_stress = atoi(argv[1]);
    else
        test_stress = 100;


    bool int_arr[test_stress];
    bool char_arr[test_stress];
    bool long_arr[test_stress];
    bool db_arr[test_stress];
    TRY{
        for(int i = 0, length =10; i < test_stress; i++, length += 5){

            char ** word;
            int * int_num;
            double * db_num; 
            long long * lg_num;
            word = gen_str_arr(length, 5, 30);


            quicksort(word, length, sizeof(char *), cmp_str);
            char_arr[i] = is_sorted(word, length, sizeof(char *), cmp_str);

            for(int i = 0; i < length; i++ ){
                free(word[i]);
            }
            free(word);

            int_num = gen_int_arr(length, 50, 10000);
            quicksort(int_num, length, sizeof(int), cmp_int);

            int_arr[i] = is_sorted(int_num, length, sizeof(int), cmp_int);

            free(int_num);

            db_num = gen_db_arr(length, 10, 10000);
            quicksort(db_num, length, sizeof(double), cmp_db);
            db_arr[i] = is_sorted(db_num, length, sizeof(double), cmp_db); 


            free(db_num);

            lg_num = gen_long_arr(length, 0, 0);

            quicksort(lg_num, length, sizeof(long long), cmp_ld);
            long_arr[i] = is_sorted(lg_num, length, sizeof(long long), cmp_ld); 


            free(lg_num);
        }
    } ENDTRY;

    TRY{
        for(int i = 0; i < test_stress; i++){
            TEST(int_arr[i], 1);
            TEST(db_arr[i], 1);
            TEST(long_arr[i], 1);
            TEST(char_arr[i], 1);
        }
    }ENDTRY;
    testerReport(stdout, argv[0]);
    return testerResult();
} 
