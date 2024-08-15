/*
** EPITECH PROJECT, 2021
** get_env_len.c
** File description:
** Get environment length
*/

#include <nep/nstring.h>
#include <stddef.h>
#include <stdlib.h>
#include <envdata.h>

int get_env_len(envkey_t **env)
{
    unsigned int len = 1;

    if (env == NULL)
        return (0);
    for (unsigned int itr = 0; env[itr]; ++itr)
        len += nstrlen(env[itr]->key) + nstrlen(env[itr]->value) + 2;
    return (len);
}