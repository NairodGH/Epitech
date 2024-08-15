/*
** EPITECH PROJECT, 2020
** copy_2d.c
** File description:
** copies a 2d string array onto another
*/

#include "../../lib.h"

char **copy_2d(char **src, char **dest)
{
    size_t size = 0;

    while (src[size])
        size++;
    dest = malloc(sizeof(char *) * (size + 1));
    for (size_t i = 0; i != size; i++) {
        dest[i] = malloc(sizeof(char) * (string_length(src[i]) + 1));
        copy_string(src[i], dest[i]);
    }
    dest[size] = NULL;
    return (dest);
}