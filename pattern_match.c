#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * search_replace(const char * text, const char * search, const char * replace){
    char buffer[BUFSIZ];
    int search_length = strlen(search);
    int txt_length = strlen(text);
    int repl_length = strlen(replace);
    int i = 0, j = 0, k = 0; 

    for(;i < (txt_length-search_length)+1; i++){
        if(text[i] == search[j])
            while(text[i+j] == search[j]) {
                j++;
                if(j >= search_length){
                    for(int x = 0; x < repl_length; x++){
                        buffer[k++] = replace[x];
                    }
                    i += search_length-1;
                    j = 0;
                    break;
                }
            }
        else{
            buffer[k++] = text[i];
        }
    }
    while(i < txt_length)
        buffer[k++] =  text[i++];
    buffer[k++] = '\0';
    printf("k: %d\n", k);
    char * new_str = malloc(k);
    memcpy(new_str, buffer, k);
    new_str[k-1] = '\0';
    return new_str;
}

char * search_remove(char * word, char *search){
    return search_replace(word, search, "");
}



int main(void){
    char * input_buffer = NULL; 
    char * output_buffer;
    FILE * input, *output;
    if((input = fopen("word.txt", "r")) == NULL){
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }
    if((output = fopen("new_word", "w")) == NULL){
        fprintf(stderr, "Error writing to file\n");
        exit(1);
    }

    int n = 0;
    while(getline(&input_buffer, (size_t *)&n,  input) != -1){
        output_buffer = search_replace(input_buffer, "line", "****");
        fputs(output_buffer, output);
        free(output_buffer);
    } 

}
