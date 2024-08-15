/*
** EPITECH PROJECT, 2020
** string_length.c
** File description:
** returns the length of a string
*/

int string_length(char *str)
{
    int i = 0;

    while (str[i] != 0)
        i++;
    return (i);
}