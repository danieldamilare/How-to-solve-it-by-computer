#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "word_utils.h"

void justify(char * line, int word_count, int max_line){
    printf("in justify: \n");
    printf("Max line: %d\n", max_line);

    int start = 0;
    int line_length = strlen(line);
    int index = 0; //index for output buffer;
    int space_arr[word_count-1]; //array to hold space to justify each word;
    int extra_space; //total space left to fill in the line;
    int space; //space for individual word;
    char output[max_line+1]; //buffer to store justified line
              
    for(int i = 0; i < word_count; i++) space_arr[i] = 1;

    while(line_length-1 >= 0 && line[line_length-1] == ' ')line_length--; //remove trailing space
    printf("Removed trailing space\n");
    line[line_length-1]='\0';
    printf("line length is : %d\n", line_length);
    if (line_length > max_line){
        fprintf(stderr, "Can't justify line. Line too long\n");
        exit(EXIT_FAILURE);
    }

    while(start < line_length && line[start] == ' '){
        output[index++] = line[start++]; //preserve indentation
        printf("current output : %s\n", output);                            
    }
    extra_space = max_line - line_length;
    printf("Extrspace needed: %d\n", extra_space);
    while(extra_space > 0 && --word_count > 0){
        int pos = round((float)word_count/(float)extra_space);
        printf("Delta position: %d\n", pos);
        int next_pos;
        if(pos == 0) pos++;

        if(extra_space > word_count) space = extra_space / word_count;
        else space = 1;
        printf("space to fill in indivial space: %d\n", space);
        next_pos = (pos+1) /2;

        while(next_pos < word_count && extra_space > 0){
            space_arr[next_pos] += space; 
            next_pos += pos;
            extra_space = extra_space -space;
        }
    }
    printf("values in the space_ar: \n");
    for(int i = 0; i < word_count; i++){
        printf("space_arr[%d]: %d\n",i, space_arr[i]);
    }
    printf("\n\n\n");
    int space_index = 0;
    for(int i = start; i < max_line; i++){
        if(line[i] == ' '){
            for(int i =0; i < space_arr[space_index]; i++){
                output[index++] = ' ';
            }
            space_index++;
        }
        else{
            output[index++] = line[i];
        }
    }
    printf("output; %s\n", output);
    memcpy(line, output, max_line+1);
    line[max_line-1] = '\0';
}

int get_line(FILE *input, char * line,  int max_line){
    static int current_length;
    static char word[MAX_LENGTH];
    int len, word_count = 0;
    if(current_length){
        word_count++;
        if(word[current_length -1] == '\n'){
            word[current_length-1] = '\0';
            memcpy(line, word, strlen(word));
            line[current_length-1] = '\0';
            current_length = 0; 
            return word_count;
        }
        memcpy(line, word, strlen(word));
    }

    while((len = getword(input, word, MAX_LENGTH)) != EOF){
    
        if(current_length + len  < max_line){
            word_count++;

            if(word[len-1] == '\n'){
                word[len -1] = '\0';
                memcpy(line+current_length, word, len);
                current_length+=len;
                line[current_length-1] = '\0';
                current_length = 0;
                return word_count;
            }       
        
            memcpy(line+current_length, word, len);
        }
        else{
            line[current_length-1] = '\0';
            current_length = len;
            return word_count;
        }
        current_length += len;
    }
    if(len == EOF){
        line[current_length-1] = 0;
        current_length = 0;
    }
    
    return word_count;
}


int getword(FILE * input, char * word, int max_length){
    static _Bool BOL = 1; //character to remember beginning of line in order to indent properly;
    int read_flag = 0;
    char ch;
    int count = 0;
    while((ch = fgetc(input)) != EOF && count < max_length -1){
        read_flag = 1;
        if(ch == '\t') //ignore tab;
            continue;
        else if(ch == ' ' && !BOL){
            word[count++] = ch;
            while((ch = fgetc(input)) == ' ') 
                ;
            ungetc(ch, input);
            break;
        }
        else if(ch == '\n'){
            word[count++] = ch;
            BOL = 1;
            break;
        }
        else if(ch != ' ' && BOL){
            BOL = 0;
            word[count++] = ch;

        }
        else{
            word[count++] = ch;
        }
    }
    word[count] = '\0';
    if (read_flag) return count;
    else if(ch == EOF) return EOF;
    return 0;
}

