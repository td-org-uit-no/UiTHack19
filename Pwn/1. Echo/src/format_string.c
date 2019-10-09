#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char buffer[256] = {0};
    char flag[] = {'U', 'i', 'T', 'H', 'a', 'c', 'k', '1', '9', '{', 'I', '_', 'h', 'e', 'a', 'r', 'd', '_', 'y', 'o', 'u', '_', 'w', 'a', 'n', 't', 'e', 'd', '_', 'a', '_', 's', 't', 'r', 'i', 'n', 'g', '}', '\0'};

    setvbuf(stdin, NULL, _IONBF, 0);
    printf("Input: ");
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        perror("fgets failure\n");
        exit(EXIT_FAILURE);
    }

    printf("Echo: ");
    printf(buffer, flag);
}