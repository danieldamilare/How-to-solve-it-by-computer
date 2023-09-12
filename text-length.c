/*  @ Written by Daniel Joseph
 *  28 July 2023
 *  A text length Formatter
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "word_utils.h"

void prog_usage(void);

int main(int argc, char ** argv){
    FILE * input = NULL, * output = NULL;
    int line_length = 0;

   //process command line option
    argc--;
    if (argc > 4){
        prog_usage();
        exit(EXIT_FAILURE);
    }
    
    for(int i = 1; i <= argc; i++){

        if(strncmp(argv[i], "-n", 2) == 0){
             line_length = atoi(argv[i+1]);
            if(line_length == 0){
                fprintf(stderr, "Error Number of line cannot be 0\n");
                exit(EXIT_FAILURE);
            }
            i++;
        }
        else if(!input){
            if ((input = fopen(argv[i], "r")) ==NULL){
                fprintf(stderr, "invalid input file %s\n", argv[i]);
                exit(EXIT_FAILURE);
            }
        }
        else if(!output){
            if((output = fopen(argv[i], "w")) == NULL){
                fprintf(stderr, "Invalid output file%s\n", argv[i]);
                exit(EXIT_FAILURE);
            }
        }
    }
    input = (input? input: stdin);
    output = (output? output: stdout);

    if(line_length == 0)
        line_length = DEFAULT_LINE;

    char line[line_length + 2]; 
    int word_count = 0;

    while((word_count = get_line(input, line, line_length) ) != 0){
        printf("word_count: %d\n\n", word_count);
        printf("word before justifying: %s\n", line);
        justify(line, word_count, line_length);
        fprintf(output, "%s\n", line);
    }


    if(input != stdin) fclose(input);
    if(output != stdout) fclose(output);
}

void prog_usage(void){
    char * usage = "text-length [option] [input file] [output file]\n \
                    option -n no_of_line\n";
    fprintf(stderr, "%s", usage);
}


