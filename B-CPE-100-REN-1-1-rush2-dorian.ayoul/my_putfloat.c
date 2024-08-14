/*
** EPITECH PROJECT, 2020
** my_putfloat
** File description:
** Display a given float
*/

#include "my.h"
#include <stdio.h>

int str_len(char **argv);

void my_putfloat(int match_nbr, char **argv, int j, float *percent)
{
    int size = str_len(argv);
    int nbr = match_nbr * 100;
    int dec = nbr / size;
    float mod = nbr % size;
    int lol = 0;

    mod = (mod * 100) / size;
    my_putchar(argv[j][0]);
    my_putchar(':');
    my_put_nbr(match_nbr);
    my_putstr(" (");
    my_put_nbr(dec);
    my_putchar('.');
    my_put_nbr(mod);
    if (mod < 10)
        my_putchar('0');
    my_putstr("%)\n");
    my_strlowcase(argv[1]);
    my_strlowcase(argv[j]);
    lol = argv[j][0] - 97;
    percent[lol] = dec + (mod / 100);
}
