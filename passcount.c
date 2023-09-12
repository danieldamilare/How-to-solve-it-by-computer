#include <stdio.h>
#include <stdlib.h>
#define PASS_MARK 50

void passcount(void){
    int count = 0,          // the total number of pass mark
        current_mark,  //current mark to be processed
        num = 0;          //  the total number of mark to be processed
    printf("Enter marks to processed: \n");

    while(scanf("%d", &current_mark) != EOF){
        num++;
        if (current_mark >= PASS_MARK) count++;
    }
    float percentage = (float)count / (float)num * 100; 

    printf("\nTotal number of marks: %d"
           "\nTotal number of pass marks: %d"
           "\nPercentage: %.2f%%\n", num, count, percentage);

}  

int main(void){
    passcount();
}
