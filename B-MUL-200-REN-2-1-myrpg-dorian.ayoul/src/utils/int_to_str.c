/*
** EPITECH PROJECT, 2021
** int_to_str.c
** File description:
** Convert integer to string
*/

#include <stdlib.h>

char *int_to_str(int nb)
{
    char *res;
    int len = 1;

    for (int tmp = nb; tmp >= 10; tmp /= 10, ++len);
    res = malloc(sizeof(char) * (1 + len));
    for (int i = len - 1; i >= 0; res[i] = 48 + (nb % 10), --i, nb /= 10);
    res[len] = '\0';
    return (res);
}