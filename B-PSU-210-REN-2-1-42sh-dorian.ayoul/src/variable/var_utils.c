/*
** EPITECH PROJECT, 2021
** utility functions for variables
** File description:
** var_utils
*/

#include "42sh.h"

char *dup_no_junk(char *readed, size_t size)
{
    char *str = strndup(readed, size);
    if (!str)
        return NULL;
    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            str[i] = '\0';
    return str;
}
