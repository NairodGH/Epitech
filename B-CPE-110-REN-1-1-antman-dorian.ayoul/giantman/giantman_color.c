/*
** EPITECH PROJECT, 2020
** antman.c
** File description:
** bop
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "antman.h"

int my_strlen(char const *str)
{
    int c;

    c = 0;
    while (str[c] != '\0')
        c++;
    return (c);
}

int norme_split(int nb_color, unsigned char *str, int *i, char *color)
{
    int h = 0;

    while (str[*i] != '\n' && str[*i] != '\0') {
        nb_color = nb_color + str[*i] - '0';
        nb_color = nb_color * 10;
        (*i)++;
    }
    nb_color = nb_color / 10;
    while (h != nb_color) {
        write(1, color, my_strlen(color));
        write(1, "\n", 1);
        h++;
    }
}

int ppm1(unsigned char *str)
{
    int i = 0;
    char *color;
    int n = 0;
    int nb_color = 0;

    while (str[i] != '\0') {
        color = malloc(sizeof(char) * 3);
        while (str[i] >= '0' && str[i] <= '9')
            color[n] = str[i], n++, i++;
        if (str[i] == '\n' || str[i] == '\0')
            write(1, color, my_strlen(color)), write(1, "\n", 1);
        else i++, norme_split(nb_color, str, &i, color);
        free(color), nb_color = 0, n = 0, i++;
    }
}