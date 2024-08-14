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

int color_norme(char *str, int *i)
{
    while (*i != 1000) {
        if (str[*i] >= '0' && str[*i] <= '9' && str[*i - 1] == '\n'
            && (str[*i + 3] == '\n' || str[*i + 2] == '\n'
            || str[*i + 3] == '\n')) break;
        write(1, &str[*i], 1);
        (*i)++;
    }
}

char *create_color(int *n, char *str, int *i, char *color)
{
    color = malloc(sizeof(char) * 3);
    if (*i == 0) {
        color_norme(str, i);
    }
    while (str[*i] != '\n') color[*n] = str[*i], (*i)++, (*n)++;
    *i = *i - *n;
    return (color);
}

int check_same(char *str, char *color, int i, int n)
{
    int a = 0;

    if (n == 1) {
        if (str[i] == color[a] && str[i + 1] == '\n')
            return (0);
    }
    if (n == 2) {
        if (str[i] == color[a] && str[i + 1] == color[a + 1]
            && str[i + 2] == '\n')
            return (0);
    }
    if (n == 3) {
        if (str[i] == color[a] && str[i + 1] == color[a + 1]
            && str[i + 2] == color[a + 2])
            return (0);
    }
    return (1);
}

int go_next(char *str, int *i)
{
    while (str[*i] != '\n') {
        if (str[*i] == '\0')
            return (0);
        (*i)++;
    }
    (*i)++;
}

char *ppm1(unsigned char *str, int i, char *stoc)
{
    int n = 0;
    char *color;
    int cnt_r = 0;
    char *nb;
    int size = 0;
    int t = 0;

    while (str[i] != '\0') {
        color = create_color(&n, str, &i, color);
        while (check_same(str, color, i, n) == 0) cnt_r++, go_next(str, &i);
        nb = my_itoa(cnt_r);
        while (size != n) stoc[t] = color[size], t++, size++;
        if (cnt_r != 1) {
            stoc[t] = ';', t++, n = my_strlen(nb), size = 0;
            while (size != n) stoc[t] = nb[size], t++, size++;
        }
        stoc[t] = '\n', t++, free(color), free(nb), n = 0, cnt_r = 0, size = 0;
    }
    return (stoc);
}