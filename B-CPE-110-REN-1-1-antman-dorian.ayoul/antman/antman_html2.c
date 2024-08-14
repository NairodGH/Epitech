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
#include "name2.h"

char *more_word7(char *str, int *i, char *stock, int *c)
{
    if (str[*i] == 'e' && str[*i + 1] == 'd' && str[*i + 2] == 'g'
        && str[*i + 3] == 'e') stock[*c] = edge, *i = *i + 4, (*c)++;
    if (str[*i] == '<' && str[*i + 1] == '/')
        stock[*c] = bal, *i = *i + 2, (*c)++;
    if (str[*i] == '<' && str[*i + 1] == 'l' && str[*i + 2] == 'i')
        stock[*c] = li, *i = *i + 3, (*c)++;
    if (str[*i] == 'i' && str[*i + 1] == 'n' && str[*i + 2] == 'p'
        && str[*i + 3] == 'u' && str[*i + 4] == 't')
        stock[*c] = input, *i = *i + 5, (*c)++;
    return (stock);
}

char *more_word6(char *str, int *i, char *stock, int *c)
{
    if (str[*i] == 'r' && str[*i + 1] == 'e' && str[*i + 2] == 't'
        && str[*i + 3] == 'u' && str[*i + 4] == 'r' && str[*i + 5] == 'n')
        stock[*c] = returnc, *i = *i + 6, (*c)++;
    if (str[*i] == 'i' && str[*i + 1] == 't' && str[*i + 2] == 'e'
        && str[*i + 3] == 'm') stock[*c] = item, *i = *i + 4, (*c)++;
    if (str[*i] == '=' && str[*i + 1] == '"')
        stock[*c] = egal, *i = *i + 2, (*c)++;
    if (str[*i] == '"' && str[*i + 1] == '>')
        stock[*c] = egal2, *i = *i + 2, (*c)++;
    if (str[*i] == 'm' && str[*i + 1] == 'e' && str[*i + 2] == 'd'
        && str[*i + 3] == 'i' && str[*i + 4] == 'a')
        stock[*c] = media, *i = *i + 5, (*c)++;
    if (str[*i] == 'd' && str[*i + 1] == 'n' && str[*i + 2] == 's'
        && str[*i + 3] == '-' && str[*i + 4] == 'p' && str[*i + 5] == 'r'
        && str[*i + 6] == 'e' && str[*i + 7] == 'f' && str[*i + 8] == 'e'
        && str[*i + 9] == 't' && str[*i + 10] == 'c' && str[*i + 11] == 'h')
        stock[*c] = dns, *i = *i + 12, (*c)++;
    stock = more_word7(str, i, stock, c);
    return (stock);
}

char *more_word5(char *str, int *i, char *stock, int *c)
{
    if (str[*i] == 'n' && str[*i + 1] == 'u' && str[*i + 2] == 'l'
        && str[*i + 3] == 'l') stock[*c] = nullc, *i = *i + 4, (*c)++;
    if (str[*i] == 'i' && str[*i + 1] == 'k' && str[*i + 2] == 'i'
        && str[*i + 3] == 'p' && str[*i + 4] == 'e' && str[*i + 5] == 'd'
        && str[*i + 6] == 'i' && str[*i + 7] == 'a')
        stock[*c] = wikipedia, *i = *i + 8, (*c)++;
    if (str[*i] == 'c' && str[*i + 1] == 'r' && str[*i + 2] == 'o'
        && str[*i + 3] == 's' && str[*i + 4] == 's' && str[*i + 5] == 'o'
        && str[*i + 6] == 'r' && str[*i + 7] == 'i' && str[*i + 8] == 'g'
        && str[*i + 9] == 'i' && str[*i + 10] == 'n')
        stock[*c] = crossorigin, *i = *i + 11, (*c)++;
    if (str[*i] == 'g' && str[*i + 1] == 'i' && str[*i + 2] == 't'
        && str[*i + 3] == 'h' && str[*i + 4] == 'u' && str[*i + 5] == 'b')
        stock[*c] = github, *i = *i + 6, (*c)++;
    if (str[*i] == 'G' && str[*i + 1] == 'i' && str[*i + 2] == 't'
        && str[*i + 3] == 'H' && str[*i + 4] == 'u' && str[*i + 5] == 'b')
        stock[*c] = githubm, *i = *i + 6, (*c)++;
    stock = more_word6(str, i, stock, c);
    return (stock);
}

char *more_word4(char *str, int *i, char *stock, int *c)
{
    if (str[*i] == 'a' && str[*i + 1] == 'm' && str[*i + 2] == 'a'
        && str[*i + 3] == 'z' && str[*i + 4] == 'o' && str[*i + 5] == 'n')
        stock[*c] = amazon, *i = *i + 6, (*c)++;
    if (str[*i] == 'g' && str[*i + 1] == 'o' && str[*i + 2] == 'o'
        && str[*i + 3] == 'g' && str[*i + 4] == 'l' && str[*i + 5] == 'e')
        stock[*c] = google, *i = *i + 6, (*c)++;
    if (str[*i] == 'w' && str[*i + 1] == 'i' && str[*i + 2] == 'n'
        && str[*i + 3] == 'd' && str[*i + 4] == 'o' && str[*i + 5] == 'w')
        stock[*c] = window, *i = *i + 6, (*c)++;
    if (str[*i] == 'i' && str[*i + 1] == 'm' && str[*i + 2] == 'a'
        && str[*i + 3] == 'g' && str[*i + 4] == 'e' && str[*i + 5] == 's')
        stock[*c] = images, *i = *i + 6, (*c)++;
    if (str[*i] == 'p' && str[*i + 1] == 'r' && str[*i + 2] == 'o'
        && str[*i + 3] == 't' && str[*i + 4] == 'o' && str[*i + 5] == 't'
        && str[*i + 6] == 'y' && str[*i + 7] == 'p' && str[*i + 8] == 'e')
        stock[*c] = prototype, *i = *i + 9, (*c)++;
    stock = more_word5(str, i, stock, c);
    return (stock);
}