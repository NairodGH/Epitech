/*
** EPITECH PROJECT, 2021
** get_env_valuedef.c
** File description:
** Get environement value with defaults if key doesn't exist
*/

#include <stddef.h>
#include <stdlib.h>
#include <envdata.h>

char *get_env_valuedef(envkey_t **keys, char *key_search, char *def)
{
    char *value = get_env_value(keys, key_search);

    if (value == NULL)
        return (def);
    return (value);
}