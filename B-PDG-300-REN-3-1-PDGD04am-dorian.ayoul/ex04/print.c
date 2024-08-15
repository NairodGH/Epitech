/*
** EPITECH PROJECT, 2022
** print.c
** File description:
** prints
*/

#include <stdio.h>
#include <string.h>
#include "print.h"
#include "action.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int i = strlen(str) - 1; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
}

void print_upper(const char *str)
{
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] >= 97 && str[i] <= 122)
            printf("%c", str[i] - 32);
        else
            printf("%c", str[i]);
    }
    printf("\n");
}

void print_42(const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    ptr_func[action](str);
}