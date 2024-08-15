/*
** EPITECH PROJECT, 2021
** file_exists.c
** File description:
** File exists
*/

#include <file_utils.h>

bool file_exists(const char *filepath)
{
    int st_call;
    struct stat st;

    st_call = stat(filepath, &st);
    if (st_call < 0)
        return false;
    return true;
}