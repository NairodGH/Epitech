/*
** EPITECH PROJECT, 2020
** copy_string.c
** File description:
** Copy a string onto another
*/

#include "../../lib.h"

size_t copy_string(char *source, char *destination)
{
    size_t i = 0;

    for (; source[i] != '\0'; i++)
        destination[i] = source[i];
    destination[i] = '\0';
    return (i);
}