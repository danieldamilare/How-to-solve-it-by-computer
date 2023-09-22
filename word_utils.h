#ifndef WORD_UTILS_H

#define WORD_UTILS_H
#include <stdio.h>
#define MAX_LENGTH 47
#define DEFAULT_LINE 60

int getword(FILE * file, char * word, int max_length);
void justify(char * line, int word_count, int max_line);

int get_line(FILE * input, char * line, int max_line);


#endif
