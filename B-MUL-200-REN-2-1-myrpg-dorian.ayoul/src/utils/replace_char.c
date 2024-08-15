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

char *replace_char(char *str, char from, char to)
{
    if (str == NULL)
        return (NULL);
    for (size_t i = 0; str[i]; ++i) {
        if (str[i] == from)
            str[i] = to;
    }
    return (str);
}