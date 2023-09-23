#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void move_register(char *instructions, int registers[]) {
    char * instruction = strdup(instructions);
    char *tokens[3];
    int i = 0;
    char *token = strtok(instruction, " ");
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    if (isalpha(tokens[2][0])) {
        registers[tokens[1][0]] = registers[tokens[2][0]];
    } else {
        registers[tokens[1][0]] = atoi(tokens[2]);
    }
    free(instruction);
    instructions[0] = 'c';
}

void increment_register(char *instruction, int registers[]) {
    char c;
    sscanf(instruction, "%*s %c", &c);
    registers[c]++;
}

void decrement_register(char *instruction, int registers[]) {
    char c;
    sscanf(instruction, "%*s %c", &c);
    registers[c]--;
}

int jump_if_not_zero(char *instructions, int registers[]) {
    /* printf("%s\n", instructions); */
    char * instruction = strdup(instructions);
    char *tokens[3];
    int i = 0;
    char *token = strtok(instruction, " ");
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    int offset;
    if (isalpha(tokens[1][0])) {
      if (isalpha(tokens[2][0])){
        offset = registers[tokens[1][0]] != 0 ? registers[tokens[2][0]] : 1;
      }
      else offset = registers[tokens[1][0]] != 0 ? atoi(tokens[2]) : 1;
    } else {
        if (isalpha(tokens[2][0])){
        offset = tokens[1][0] == '0' ? 1 : registers[tokens[2][0]];
       }
        else  offset = tokens[1][0] == '0' ? 1 : atoi(tokens[2]);
      }
    free(instruction);
    return offset? offset : 1;
}

void simple_assembler(size_t n, char *program[], int registers[]) {
    int i = 0;
    while (i < n) {
        /* printf("registers[a]: %d [b]: %d [c]: %d [d] : %d\n", registers['a'], registers['b'], */
                /* registers['c'], registers['d']); */
        char *instruction = program[i];
        if (strncmp(instruction, "mov", 3) == 0) {
            move_register(instruction, registers);
        } else if (strncmp(instruction, "inc", 3) == 0) {
            increment_register(instruction, registers);
        } else if (strncmp(instruction, "dec", 3) == 0) {
            decrement_register(instruction, registers);
        } else if (strncmp(instruction, "jnz", 3) == 0) {
            int offset = jump_if_not_zero(instruction, registers);
            i += offset;
            continue;
        }
        i++;
    }
}


int main(void) {
    char *program[] = {"mov a 1", "mov b 1", "mov c 0", "mov d 26", "jnz c 2", "jnz 1 5", "mov c 7", "inc d", "dec c", "jnz c -2", "mov c a", "inc a", "dec b", "jnz b -2", "mov b c", "dec d", "jnz d -6", "mov c 18", "mov d 11", "inc a", "dec d", "jnz d -2", "dec c", "jnz c -5"};
    int program_size = sizeof(program) / sizeof(program[0]);
    int registers[128] = {0};
    simple_assembler(program_size, program, registers);
    if (registers['a'] == 318009 && registers['b'] == 196418 &&
        registers['c'] == 0) {
        printf("Test passed successfully!");
    }
    return 0;
}
