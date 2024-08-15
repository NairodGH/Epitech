/*
** EPITECH PROJECT, 2021
** create_env_key.c
** File description:
** Create environment key
*/

#include <stddef.h>
#include <stdlib.h>
#include <envdata.h>
#include <stdio.h>

char *convert_env_to_str(envkey_t **env)
{
    char *str;
    unsigned int len = get_env_len(env);
    unsigned int jtr = 0;

    if (env == NULL || len == 0)
        return (NULL);
    str = malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);
    for (unsigned int itr = 0; env[itr]; ++itr) {
        for (unsigned int ptr = 0; env[itr]->key[ptr]; ++ptr, ++jtr)
            str[jtr] = env[itr]->key[ptr];
        str[jtr++] = '=';
        for (unsigned int ptr = 0; env[itr]->value[ptr]; ++ptr, ++jtr)
            str[jtr] = env[itr]->value[ptr];
        str[jtr++] = '\n';
    }
    str[jtr] = '\0';
    return (str);
}