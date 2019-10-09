#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define bufferSize 32

char* name_prompt = "Username: ";
char* default_username = "admin\n";
char* pwd_prompt = "Password: ";
char* default_password = "changeThisASAP\n";
int is_username_correct(char* username);
int is_password_correct(char* pwd);


int main() {
    char flag[] = {'U', 'i', 'T', 'H', 'a', 'c', 'k', '1', '9', '{',
                    'n', 'o', 't', '_', 't', 'h', 'e', '_', 'g', 'r', 'e', 'a', 't', 'e', 's', 't', '_', 's', 'e', 'c', 'u', 'r', 'i', 't', 'y', '}', '\0'};
    char* username = malloc(bufferSize);
    if (username == NULL) {
        exit(EXIT_FAILURE);
    }

    char* password = malloc(bufferSize);
    if (password == NULL) {
        exit(EXIT_FAILURE);
    }

    printf("Welcome to the Super Secret Flag Storage\n\
----------------------------------------------------\n");

    while(1) {
        printf("%s", name_prompt);
        username = fgets(username, bufferSize, stdin);
        printf("%s", pwd_prompt);
        password = fgets(password, bufferSize, stdin);

        if( username != NULL && is_username_correct(username)
            && password != NULL && is_password_correct(password)) {
                printf("Welcome, %sHere is your flag:\n", username);
                printf("%s\n", flag);
                exit(EXIT_SUCCESS);
        }else {
            printf("Invalid username or password\n");
        }
    }
    
}

int is_username_correct(char* username) {
    return strcmp(username, default_username) == 0;
}

int is_password_correct(char* pwd) {
    return strcmp(pwd, default_password) == 0;
}
