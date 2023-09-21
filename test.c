#include <stdio.h>
#include <string.h>

int main(void){
    char word[4] = "abc";
    for(int i = 0; i < 3; i++){
        for(int  j = 0; j < 3; j++){
            if(j == i) continue;
            for(int k = 0; k < 3; k++){
                if(k != j && k != i){
                    printf("%c%c%c\n", word[i], word[j], word[k]);
                }
            }
        }
    }
}


void permutation(char * word, int n){
    int len = strlen(word);
    for(int i = 0; i < len; i++){

    }
}
