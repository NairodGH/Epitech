/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** Guesses the language of a string
*/

#include "my.h"

int match(char **argv, int i, int count, int j)
{
    if ((argv[1][i] >= 'A' && argv[1][i] <= 'Z') ||
    (argv[1][i] >= 'a' && argv[1][i] <= 'z'))
        if (argv[1][i] == argv[j][0] || (argv[1][i] == argv[j][0] + 32 ||
        argv[1][i] == argv[j][0] - 32))
        count++;
    return (count);
}
