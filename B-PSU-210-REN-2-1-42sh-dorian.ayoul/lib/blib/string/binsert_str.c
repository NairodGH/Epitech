/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "blib.h"

char *binsert_string(char *dest, char *src, size_t pos)
{
    size_t len = 0;
    char *result = NULL;

    if (!dest || !src || !pos)
        return NULL;
    len = bstrlen(dest) + bstrlen(src);
    result = bcalloc(sizeof(char), len + 1);
    if (!result)
        return NULL;
    result = bstrncpy(result, dest, pos);
    result = bstrcat(result, src);
    result = bstrcat(result + pos, dest);
    free(dest);
    return result;
}
