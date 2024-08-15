/*
** EPITECH PROJECT, 2021
** create_env_key.c
** File description:
** Create environment key
*/

#include <stddef.h>
#include <stdlib.h>
#include <envdata.h>

envkey_t *parse_env(char *str)
{
    char **split;
    int occ = 0;

    if (str == NULL)
        return (NULL);
    for (unsigned int itr = 0; str[itr]; ++itr)
        if (str[itr] == '=')
            ++occ;
    if (occ != 1)
        return (NULL);
    split = my_strtok(str, '=');
    if (split == NULL || my_arrcount(split) != 2)
        return (NULL);
    return (create_env_key(split[0], split[1]));
}