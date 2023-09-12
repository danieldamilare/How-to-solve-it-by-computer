#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* #define tolower(x) \ */
    /* (((x) >= 'A' && (x) <= 'Z')? ((x) | 0x20): (x)) */
/* #define isalpha(x) ((tolower((x))) >= 'a' && (tolower(x)) <= 'z') */

int text_search(const char * text, const char *search){
    /* return the number of occurence of search in the the text array */
    char pre = ' '; //variable to store the preceding and post character after each search occurence
                    //used to confirm if the word is a standalone word
    int index = 0;       //index of the search array;
    int nmatch = 0;
    int text_len = strlen(text);  //index of the text array
    int search_len = strlen(search);
    for(int i = 0; i < text_len; i++){
        if(text[i] == search[index] && !isalpha(pre)){
            index++;
            if(index == search_len){
                //print word that has match as prefix;
                int j = i - (search_len-1);
                int k = i;

                while(isalpha(text[++k]))
                    ;
                for(; j < k; j++)printf("%c", text[j]);

                if(!isalpha(text[i+1])){
                    nmatch++;
                }
                index = 0;
                pre = text[i];
            }
        }
        else{
            pre = text[i];
        }
    }
    return nmatch;
}


int main(void){
    char * word = "Who is the man, is the the father of the boy who is dancing whose whot, whom";
    int occurence = text_search(word, "who");
    printf("is occured %d times\n", occurence);
    printf("is space an alpha %d", isalpha(' '));
}
