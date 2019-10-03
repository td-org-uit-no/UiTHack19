#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char flag[] = "UiTHack19{the_sphinx_is_a_meanie}";

#define BUFFER_SIZE 512
#define RIDDLE "I walk on four feet in the morning; two feet in the afternoon; and in the evening upon three. What am I?\n"
#define clear() printf("\033[H\033[J")

int main(int argc, char** argv) {
    char input[BUFFER_SIZE];

    while(1) {
        printf("Answer my riddle to find your flag\n");
        printf(RIDDLE);
        fgets(input, BUFFER_SIZE, stdin);
        clear();

        if (strcmp(input, "please\n") == 0) {
            printf("Even the magic word does not help you here!\n");
        }
        else if (strcmp(input, "quit\n") == 0) {
            printf("I see you're giving up for now, I win once again!\n");
            exit(EXIT_SUCCESS);
        }
        else if (strcmp(input, "man\n") == 0) {
            printf("Correct! But you still can't have my flag\n");
            exit(EXIT_SUCCESS);
        }
        else {
            printf("Hah! You will never get my flag!\n");
        }
    }
}