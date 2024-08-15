/*
** EPITECH PROJECT, 2021
** append_str.c
** File description:
** Append a string
*/

#include <nep/nstring.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

char *append_str(char *from, char *append)
{
    int pos = 0;
    int len = 0;
    char *res;

    if (from == NULL)
        return (append);
    len = nstrlen(from) + nstrlen(append) + 1;
    res = malloc(sizeof(char) * len);
    for (; from[pos]; res[pos] = from[pos], ++pos);
    for (int i = 0; append[i]; res[pos] = append[i], ++i, ++pos);
    res[pos] = '\0';
    return (res);
}