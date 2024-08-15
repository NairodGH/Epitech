/*
** EPITECH PROJECT, 2021
** get_height.c
** File description:
** get a map's height (counts number of line breaks)
*/

#include "../../lib.h"

size_t get_height(char *str)
{
    int height = 0;

    if (str == NULL)
        return (-1);
    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            height++;
    return (height);
}