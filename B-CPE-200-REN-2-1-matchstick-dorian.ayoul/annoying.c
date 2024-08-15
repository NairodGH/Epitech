/*
** EPITECH PROJECT, 2020
** annoying.c
** File description:
** lig functions ;p
*/

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include "include/my.h"

int stat(map m, int mode)
{
    int nb = 0;

    for (int i = 1; mode == 0 && i != m.h - 1; i++)
        for (int j = 1; j != m.w - 2; j++)
            if (m.m[i][j] == '|') nb++;
    for (int i = 1; mode > 0 && i != m.w - 2; i++)
        if (m.m[mode][i] == '|')
            nb++;
    return (nb);
}

int getnbr(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
        nb *= 10;
        nb += str[i] - 48;
    }
    return (nb);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void putnbr(int nb)
{
    if (nb > 9) {
        putnbr(nb / 10);
        my_putchar((nb % 10) + 48);
    }
    else
        my_putchar((nb % 10) + 48);
}