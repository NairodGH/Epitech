/*
** EPITECH PROJECT, 2021
** create_env_key.c
** File description:
** Create environment key
*/

#include <stddef.h>
#include <stdlib.h>
#include <envdata.h>
#include <file_utils.h>

envkey_t **get_env_from_file(char *file_path)
{
    char **split;
    char *content;
    unsigned int itr;

    envkey_t **keys = NULL;
    if (file_path == NULL)
        return (NULL);
    content = read_file(file_path);
    if (content == NULL)
        return (NULL);
    split = my_strtok(content, '\n');
    keys = malloc(sizeof(envkey_t) * (my_arrcount(split) + 1));
    for (itr = 0; split[itr]; ++itr) {
        keys[itr] = parse_env(split[itr]);
    }
    keys[itr] = NULL;
    return (keys);
}