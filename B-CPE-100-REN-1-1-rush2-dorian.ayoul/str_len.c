/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** Guesses the language of a string
*/

#include "my.h"

int str_len(char **argv)
{
    int size = 0;

    for (int i = 0; argv[1][i] != '\0'; i++) {
        if ((argv[1][i] >= 'A' && argv[1][i] <= 'Z') || (argv[1][i] >= 'a' && argv[1][i] <= 'z')) {
            size++;
        }
    }
    return size;
}
