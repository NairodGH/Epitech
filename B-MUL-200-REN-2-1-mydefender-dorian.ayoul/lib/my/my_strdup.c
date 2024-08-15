/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** Allocates mem to a string to cpy another one in it.
*/
#include<stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int size = my_strlen(src);
    char *cpy = malloc(sizeof(char) * (size));

    for (int i = 0; src[i] != '\0'; i++) {
        cpy[i] = src[i];
    }
    return (cpy);
}
