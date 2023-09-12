#include <string.h>
#include <stdio.h>
#include <stdbool.h>
void gen_lps(char * pat, int n, int * lps){
    printf("pat: %s, n: %d\n", pat, n);
    int len = 0;
    lps[0] = 0;
    int i  = 1;
    while(i < n){
        if (pat[i] == pat[len]){
            printf("Match found\n");
            printf("I: %d, len: %d\n", i, len);
            lps[i++] = ++len;
        }
        else{
            if(len != 0){
                printf("Len is not = 0\n");
                printf("len is %d\n i: %d\n", len, i);
                len = lps[len-1];
                printf("len now is %d\n", len);
                
            }

            else {
                printf("len == 0, i: %d\n",i);
                lps[i++] = 0;
            }
        }
    }
}

int search_count(char * word, char * search){
    int word_len = strlen(word), search_len = strlen(search);
    int lps[search_len];
    int nmatch = 0;
    gen_lps(search, search_len, lps);
    int j = 0, i = 0;
    for(i = 0; i <(word_len - search_len) + 1;){
        if(search[j] == word[i]){
            i++;
            j++;

        }
        if(j == search_len){
            nmatch++;
            j = lps[j-1];
        }

         if(word[i] != search[j]){
             if(j != 0)
                j  = lps[j-1];
             else
                 i++;
            
        }
        }
    return nmatch;
}


void gen_table(char * search, int table[128]){
    int search_len = strlen(search);
    for(int i = 0; i < 128; i++) table[i] = search_len -1;
    for(int i = 0; i < search_len; i++){
        if(i == search_len -1){ //last character
                table[(int) search[i]] = - (search_len -i);
        }
        else
            table[(int) search[i]] = search_len-i -1;
    }
}

int fast_search(char *word, char * search){
    int nmatch = 0;
    int wordlen = strlen(word);
    int searchlen = strlen(search);
    int table[128];
    gen_table(search, table);
    int i = searchlen -1;
    while(i < wordlen){
        char nchar = word[i];
        int nxt = table[(int) nchar];
        if(nxt > 0)
            i+= nxt;
        else{
            int windex = i -1;
            int sindex = searchlen -2;
            _Bool match = true;
            while(sindex >= 0 && match == true){
                if(word[windex] == search[sindex]){
                    windex--, sindex--;
                }
                else{
                    match =  false;
                }
            }
            if(match == true){ nmatch++;
                for(int x = windex; x < i; x++) printf("%c", word[x]);
                printf("\n");
            }
            i -= nxt;
        }

    }
    return nmatch;
}

int main(int argc, char ** argv){
    char * word = "The man who is the person that beat Daniel is now the father of the same Daniel";
    int nmatch = fast_search(word, "e");
    printf("There are %d matches\n", nmatch);
}

