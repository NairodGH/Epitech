/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** Guesses the language of a string
*/

#include "my.h"
#include <stdio.h>

int match(char **argv, int i, int count, int j);
void my_putfloat(int count, char **argv, int j, float *percent);
void compare(float *language, float *percent, int argc, char **argv);

void rush2(int argc, char **argv, float *language)
{
    int i = 0;
    int count = 0;
    int j = 2;
    float percent[500];

    while (j < argc) {
        while (argv[1][i] != '\0') {
            count = match(argv, i, count, j);
            i++;
        }
        my_putfloat(count, argv, j, percent);
        i = 0;
        count = 0;
        j++;
    }
    compare(language, percent, argc, argv);
}
