/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** Reverse a String.
*/

#include "my.h"

char *my_revstr(char *str)
{
    int d = 0;
    char c;

    while (str[d] != '\0')
        d++;
    d -= 1;
    for (int i = 0; i < d; i++) {
        c = str[i];
        str[i] = str[d];
        str[d] = c;
        d--;
    }
    return (str);
}
