/*
** EPITECH PROJECT, 2020
** int_functions.c
** File description:
** integer-related functions for my_printf's conversion specifiers
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "include/my.h"

void my_putint(long nb, char **flags)
{
    long i = 1;
    char *res = malloc(12);
    int j = 0;

    for (int k = 0; k < 12; k++)
        res[k] = '\0';
    nb = signed_lengths(nb, flags);
    if (nb < 0 || flags[0][1] == ' ' || flags[0][2] == '+')
        nb = signed_interactions(nb, flags, res, j++);
    while ((nb / i) >= 10)
        i *= 10;
    for (; i > 0; j++) {
        res[j] = (nb / i) % 10 + 48;
        i /= 10;
    }
    padding(flags, res);
}

void my_putoct(unsigned long nb, char **flags)
{
    char *res = malloc(23);
    int i = 0;

    for (int k = 0; k < 23; k++)
        res[k] = '\0';
    unsigned_lengths(nb, flags, res, i);
    for (int modulo = 0; nb != 0; i++) {
        modulo = nb % 8;
        nb /= 8;
        res[i] = modulo + 48;
    }
    my_revstr(res);
    if (res[0] != 0 && flags[0][0] == '#') {
        for (i = my_strlen(res); i != 0; i--)
            res[i] = res[i - 1];
        res[0] = '0';
    }
    padding(flags, res);
}

void my_putuns(unsigned long nb, char **flags)
{
    char *res = malloc(20);
    long i = 1;
    int j = 0;

    for (int k = 0; k < 20; k++)
        res[k] = '\0';
    unsigned_lengths(nb, flags, res, j);
    while ((nb / i) >= 10)
        i *= 10;
    for (; i > 0; j++) {
        res[j] = (nb / i) % 10 + 48;
        i /= 10;
    }
    padding(flags, res);
}

void my_puthex(unsigned long nb, char cases, char **flags)
{
    int i = 0;
    char *res = malloc(18);
    int remainder = 0;

    for (int k = 0; k < 18; k++)
        res[k] = '\0';
    unsigned_lengths(nb, flags, res, i);
    for (; nb != 0; nb /= 16, i++) {
        remainder = nb % 16;
        if (remainder < 10)
            res[i] = remainder + 48;
        else if (cases == 'x' || cases == 'p')
            res[i] = remainder + 87;
        else
            res[i] = remainder + 55;
    }
    my_revstr(res);
    alternate_form(cases, flags, res);
    padding(flags, res);
}

void my_putbin(unsigned long nb, char **flags)
{
    char *res = malloc(64);
    int i = 0;

    for (int k = 0; k < 64; k++)
        res[k] = '\0';
    unsigned_lengths(nb, flags, res, i);
    for (; nb > 0; i++) {
        res[i] = (nb % 2) + 48;
        nb /= 2;
    }
    my_revstr(res);
    padding(flags, res);
}