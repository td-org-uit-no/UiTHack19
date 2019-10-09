#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct user_info {
    char name[16];
    signed char age;
    bool is_admin;
}__attribute__((packed));

int main() {
    struct user_info new_user;
    new_user.is_admin = false;

    printf("Register User\nAge: ");
    scanf(" %hhd", &new_user.age);

    printf("Name: ");
    scanf(" %s", new_user.name);
    new_user.name[15] = '\0';

    printf("\nWelcome, %s\nage: %d\nadmin: %d\n", new_user.name, new_user.age, new_user.is_admin);

    if (new_user.age <= 90) {
        if(new_user.is_admin) {
            printf("\nAdmin mode unlocked\n");
            system("/bin/sh");
        }else{
            printf("\nNot much to do here without admin privileges I'm afraid\n");
        }
    }else{
        printf("You're too old to be an admin\n");
    }
}