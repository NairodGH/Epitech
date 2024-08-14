/*
** EPITECH PROJECT, 2020
** str_functions.c
** File description:
** string-related functions for my_printf's conversion specifiers
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "include/my.h"

void my_putchar(char c, char **flags)
{
    char *res = malloc(2);

    res[0] = c;
    res[1] = '\0';
    padding(flags, res);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_revstr(char *str)
{
    int a = 0;
    int b = 0;
    int temp = 0;

    while (str[b] != '\0')
        b++;
    b--;
    while (a < b) {
        temp = str[a];
        str[a] = str[b];
        str[b] = temp;
        a++;
        b--;
    }
    return (str);
}

void my_putstr(char *str, char unprintable, char **flags)
{
    char *res = malloc(my_strlen(str) * 4);
    int j = 0;
    char temp;

    for (int k = 0; k < my_strlen(str) * 4; k++) res[k] = '\0';
    for (int i = 0; unprintable == 's' && str[i] != '\0'; i++) res[i] = str[i];
    for (int i = 0; unprintable == 'S' && str[i] != '\0'; i++) {
        if (31 < str[i] && str[i] < 127) res[j++] = str[i];
        else {
            res[j++] = '\\';
            for (int modulo = 0, temp = str[i]; temp != 0; temp /= 8)
                (modulo = temp % 8, res[j++] = modulo + 48);
            (res[j - 1] != '7') && (res[j] = '0');
            temp = res[j], res[j] = res[j - 2], res[j++ - 2] = temp;
        }
    }
    padding(flags, res);
}