/*
** EPITECH PROJECT, 2021
** save_env_array.c
** File description:
** Save environment array in a file
*/

#include <stddef.h>
#include <stdlib.h>
#include <file_utils.h>
#include <envdata.h>

bool save_env_array(char *file_path, envkey_t **env)
{
    char *content;

    if (file_path == NULL || env == NULL)
        return (false);
    content = convert_env_to_str(env);
    if (content == NULL)
        return (false);
    return (write_file(file_path, content));
}