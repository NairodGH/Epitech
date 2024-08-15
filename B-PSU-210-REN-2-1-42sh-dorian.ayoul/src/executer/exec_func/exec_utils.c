/*
** EPITECH PROJECT, 2021
** utilitary funcs for execs
** File description:
** exec_utils
*/

#include "42sh.h"

bool contain_equal(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] == '=')
            return true;
    return false;
}

bool equal_is_next(char *str)
{
    if (!str)
        return false;
    if (!strncmp(str, "=", 1))
        return true;
    return false;
}

int hook_set_value(char *str, variable_t *to_replace, size_t i)
{
    if (!str) {
        to_replace->value = strdup("\0");
        return i + 2;
    }
    else {
        to_replace->value = strdup(str);
        return i + 3;
    }
}

char *copy_from_to(char *str, char start, char delim)
{
    char *buffer = NULL;
    size_t start_size = 0;
    size_t size = 0;

    if (start) {
        for (; str[start_size] != start; start_size++);
        start_size++;
    }
    for (size = start_size; str[size] != delim && str[size] != '\0'; size++);
    buffer = strndup(str + start_size, size);
    return buffer;
}
