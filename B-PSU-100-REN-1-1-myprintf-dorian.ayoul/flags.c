/*
** EPITECH PROJECT, 2020
** flags.c
** File description:
** flags-related functions for my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "include/my.h"

long signed_lengths(long nb, char **flags)
{
    if (flags[3][0] == 'h') {
        if ((nb >= 32768) && ((nb / 32768) % 2) == 1)
            nb = 32768 - (nb % 32768), nb = -nb;
        if (nb < -32768 && ((nb / 32768) % 2) == -1)
            nb = 32768 + (nb % 32768), (nb == 32768) && (nb = -nb);
        if ((nb >= 32768) || (nb < -32768) && ((nb / 32768) % 2) == 0)
            nb %= 32768;
    }
    if (flags[3][0] == '\0') {
        if ((nb >= 2147483648) && ((nb / 2147483648) % 2) == 1)
            nb = 2147483648 - (nb % 2147483648), nb = -nb;
        if (nb < -2147483648 && ((nb / 2147483648) % 2) == -1) {
            nb = 2147483648 + (nb % 2147483648);
            (nb == 2147483648) && (nb = -nb);
        }
        if ((nb >= 2147483648) || (nb < -2147483648) &&
            ((nb / 2147483648) % 2) == 0)
            nb %= 2147483648;
    }
    return (nb);
}

long signed_interactions(long nb, char **flags, char *res, int j)
{
    if (nb < 0) {
        res[j++] = '-';
        flags[0][1] = 'N';
        flags[0][2] = 'N';
        nb = -nb;
    }
    if (flags[0][1] == ' ' && flags[0][1] != 'N')
        res[j++] = ' ';
    if (flags[0][2] == '+' && flags[0][2] != 'N') {
        res[j++] = '+';
    }
    return (nb);
}

void unsigned_lengths(unsigned long nb, char **flags, char *res, int i)
{
    if (flags[3][0] == 'H') {
        if (nb >= 256)
            nb %= 256;
        if (nb == 0)
            res[i] = '0';
    }
    if (flags[3][0] == 'h') {
        if (nb >= 65536)
            nb %= 65536;
        if (nb == 0)
            res[i] = '0';
    }
    if (flags[3][0] == '\0') {
        if (nb >= 4294967296)
            nb %= 4294967296;
        if (nb == 0)
            res[i] = '0';
    }
}

void alternate_form(char cases, char **flags, char *res)
{
    if (cases == 'p' || (cases == 'x' && flags[0][0] == '#')) {
        for (int i = my_strlen(res); i != 0; i--)
            res[i] = res[i - 1];
        res[0] = '0';
        for (int i = my_strlen(res); i != 1; i--)
            res[i] = res[i - 1];
        res[1] = 'x';
    }
    if (cases == 'X' && flags[0][0] == '#') {
        for (int i = my_strlen(res); i != 0; i--)
            res[i] = res[i - 1];
        res[0] = '0';
        for (int i = my_strlen(res); i != 0; i--)
            res[i] = res[i - 1];
        res[1] = 'X';
    }
}

void padding(char **flags, char *res)
{
    int width = 0;

    for (int i = 0; flags[2][i] != '\0'; i++)
        (width *= 10, width += flags[2][i] - 48);
    width -= my_strlen(res);
    if (width < 0) width = 0;
    if (flags[1][0] != '0' && flags[1][1] != '-' && flags[1][2] != '.') {
        for (; width != 0; width--) write(1, " ", 1);
        for (int i = 0; res[i] != '\0'; i++) write(1, &res[i], 1);
    }
    if (flags[1][1] == '-') {
        for (int i = 0; res[i] != '\0'; i++) write(1, &res[i], 1);
        for (; width != 0; width--) write(1, " ", 1);
    }
    if (flags[1][0] == '0' || flags[1][2] == '.') {
        for (; width != 0; width--) write(1, "0", 1);
        for (int i = 0; res[i] != '\0'; i++) write(1, &res[i], 1);
    }
    free(res);
}