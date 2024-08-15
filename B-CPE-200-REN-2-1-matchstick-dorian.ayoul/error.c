/*
** EPITECH PROJECT, 2020
** error.c
** File description:
** error-related functions
*/

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include "include/my.h"

int error(int ac, char **av)
{
    if (ac != 3) {
        write(2, "Error: there must be 2 arguments\n", 34);
        return (84);
    }
    for (int i = 0; av[1][i] != 0; i++)
        if (av[1][i] < 48 || av[1][i] > 57) {
            write(2, "Error: arg 1 must be a positive integer\n", 41);
            return (84);
        }
    for (int i = 0; av[2][i] != 0; i++)
        if (av[2][i] < 48 || av[2][i] > 57) {
            write(2, "Error: arg 2 must be a positive integer\n", 41);
            return (84);
        }
    if (av[1][0] == '0' && av[1][1] == 0 || av[2][0] == '0' && av[2][1] == 0) {
        write(2, "Error: arg 1 and 2 must be non-null\n", 37);
        return (84);
    }
    return (0);
}

int l_err(char *b, map m)
{
    if (b[0] == 0) return (1);
    for (int i = 0; b[i] != '\n'; i++)
        if (b[i] < 48 || b[i] > 57) {
            write(1, "Error: invalid input (positive number expected)\n", 48);
            return (0);
        }
    if (getnbr(b) < 1 || getnbr(b) > m.h - 2) {
        write(1, "Error: this line is out of range\n", 33);
        return (0);
    }
    if (stat(m, getnbr(b)) == 0) {
        write(1, "Error: not enough matches on this line\n", 39);
        return (0);
    }
    return (1);
}

int m_err(char *b, int ln, map m, int max)
{
    if (b[0] == 0) return (1);
    for (int i = 0; b[i] != '\n'; i++)
        if (b[i] < 48 || b[i] > 57) {
            write(1, "Error: invalid input (positive number expected)\n", 48);
            return (0);
        }
    if (getnbr(b) == 0) {
        write(1, "Error: you have to remove at least one match\n", 45);
        return (0);
    }
    if (getnbr(b) > max) {
        write(1, "Error: you cannot remove more than ", 35);
        putnbr(max), write(1, " matches per turn\n", 18);
        return (0);
    }
    if (getnbr(b) > stat(m, ln)) {
        write(1, "Error: not enough matches on this line\n", 39);
        return (0);
    }
    return (1);
}