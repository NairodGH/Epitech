/*
** EPITECH PROJECT, 2021
** create_env_key.c
** File description:
** Create environment key
*/

#include <stddef.h>
#include <stdlib.h>
#include <envdata.h>
#include <nep/nstring.h>

char *get_env_value(envkey_t **keys, char *key_search)
{
    unsigned int itr;

    if (keys == NULL)
        return (NULL);
    for (itr = 0; keys[itr]; ++itr) {
        if (keys[itr]->key == NULL)
            continue;
        if (nstrcmp(keys[itr]->key, key_search) == 0)
            return (keys[itr]->value);
    }
    return (NULL);
}