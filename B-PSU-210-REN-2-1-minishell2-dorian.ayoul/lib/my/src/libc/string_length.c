/*
** EPITECH PROJECT, 2020
** string_length.c
** File description:
** returns the length of a string
*/

#include "../../lib.h"

size_t string_length(char *str)
{
    size_t i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}