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
#include "name.h"

char *more_word3(char *str, int *i, char *stock, int *c)
{
    if (str[*i] == 'i' && str[*i + 1] == 'm'
        && str[*i + 2] == 'g')
        stock[*c] = img, *i = *i + 3, (*c)++;
    if (str[*i] == 'b' && str[*i + 1] == 'o'
        && str[*i + 2] == 'd' && str[*i + 3] == 'y')
        stock[*c] = body, *i = *i + 4, (*c)++;
    if (str[*i] == 'h' && str[*i + 1] == 'e' && str[*i + 2] == 'i'
        && str[*i + 3] == 'g' && str[*i + 4] == 'h' && str[*i + 5] == 't')
        stock[*c] = height, *i = *i + 6, (*c)++;
    if (str[*i] == 'w' && str[*i + 1] == 'i' && str[*i + 2] == 'd'
        && str[*i + 3] == 't' && str[*i + 4] == 'h')
        stock[*c] = width, *i = *i + 5, (*c)++;
    if (str[*i] == 'h' && str[*i + 1] == 'e'
        && str[*i + 2] == 'a' && str[*i + 3] == 'd')
        stock[*c] = head, *i = *i + 4, (*c)++;
    if (str[*i] == 't' && str[*i + 1] == 'i' && str[*i + 2] == 't'
        && str[*i + 3] == 'l' && str[*i + 4] == 'e')
        stock[*c] = title, *i = *i + 5, (*c)++;
    stock = more_word4(str, i, stock, c);
    return (stock);
}

char *more_word_2(char *str, int *i, char *stock, int *c)
{
    if (str[*i] == 'c' && str[*i + 1] == 'o' && str[*i + 2] == 'n'
        && str[*i + 3] == 't' && str[*i + 4] == 'e' && str[*i + 5] == 'n'
        && str[*i + 6] == 't') stock[*c] = content, *i = *i + 7, (*c)++;
    if (str[*i] == 'h' && str[*i + 1] == 't' && str[*i + 2] == 't'
        && str[*i + 3] == 'p' && str[*i + 4] == 's' && str[*i + 5] == ':'
        && str[*i + 6] == '/' && str[*i + 7] == '/')
        stock[*c] = https, *i = *i + 8, (*c)++;
    if (str[*i] == 's' && str[*i + 1] == 'p'
        && str[*i + 2] == 'a' && str[*i + 3] == 'n')
        stock[*c] = span, *i = *i + 4, (*c)++;
    if (str[*i] == '.' && str[*i + 1] == 'c' && str[*i + 2] == 'o'
        && str[*i + 3] == 'm') stock[*c] = com, *i = *i + 4, (*c)++;
    if (str[*i] == 'a' && str[*i + 1] == 'r' && str[*i + 2] == 't'
        && str[*i + 3] == 'i' && str[*i + 4] == 'c' && str[*i + 5] == 'l'
        && str[*i + 6] == 'e') stock[*c] = article, *i = *i + 7, (*c)++;
    if (str[*i] == 's' && str[*i + 1] == 'c' && str[*i + 2] == 'r'
        && str[*i + 3] == 'i' && str[*i + 4] == 'p' && str[*i + 5] == 't')
        stock[*c] = script, *i = *i + 6, (*c)++;
    stock = more_word3(str, i, stock, c);
    return (stock);
}

char *more_word(char *str, int *i, char *stock, int *c)
{
    if (str[*i] == 'r' && str[*i + 1] == 'e'
        && str[*i + 2] == 'l') stock[*c] = rel, *i = *i + 3, (*c)++;
    if (str[*i] == 'd' && str[*i + 1] == 'i'
        && str[*i + 2] == 'v') stock[*c] = divc, *i = *i + 3, (*c)++;
    if (str[*i] == 'p' && str[*i + 1] == 'r' && str[*i + 2] == 'o'
        && str[*i + 3] == 'p' && str[*i + 4] == 'e' && str[*i + 5] == 'r'
        && str[*i + 6] == 't' && str[*i + 7] == 'y')
        stock[*c] = property, *i = *i + 8, (*c)++;
    if (str[*i] == 'n' && str[*i + 1] == 'a'
        && str[*i + 2] == 'm' && str[*i + 3] == 'e')
        stock[*c] = name, *i = *i + 4, (*c)++;
    if (str[*i] == 'c' && str[*i + 1] == 'l'
        && str[*i + 2] == 'a' && str[*i + 3] == 's' && str[*i + 4] == 's')
        stock[*c] = clas, *i = *i + 5, (*c)++;
    if (str[*i] == 's' && str[*i + 1] == 't'
        && str[*i + 2] == 'y' && str[*i + 3] == 'l' && str[*i + 4] == 'e')
        stock[*c] = style, *i = *i + 5, (*c)++;
    stock = more_word_2(str, i, stock, c);
    return (stock);
}

char *check_space(char *str, int *i, char *stock, int *c)
{
    int sp = 1;
    int size = 0;
    int a = 0;
    char *nb;
    while (str[*i - 1] == ' ' && str[*i] == ' ' && *i > 0) sp++, (*i)++;
    if (sp >= 2) {
        nb = my_itoa(sp), size = my_strlen(nb);
        while (a != size) stock[*c] = nb[a], a++, (*c)++;
        stock[*c] = space, (*c)++;
    }
    sp = 1, size = 0, a = 0;
    while (str[*i - 1] == '\n' && str[*i] == '\n' && *i > 0) sp++, (*i)++;
    if (sp >= 2) {
        nb = my_itoa(sp), size = my_strlen(nb);
        while (a != size) stock[*c] = nb[a], a++, (*c)++;
        stock[*c] = backl, (*c)++;
    }
    return (stock);
}

int html(char *str, char *stock)
{
    int i = 0;
    int a = 0;
    int c = 0;

    while (str[i] != '\0') { a = i, stock = check_space(str, &i, stock, &c);
        if (str[i] == 'm' && str[i + 1] == 'e' && str[i + 2] == 't'
            && str[i + 3] == 'a') stock[c] = meta, i = i + 4, c++;
        if (str[i] == 'l' && str[i + 1] == 'i' && str[i + 2] == 'n'
            && str[i + 3] == 'k') stock[c] = linkc, i = i + 4, c++;
        if (str[i] == 'h' && str[i + 1] == 'r' && str[i + 2] == 'e'
            && str[i + 3] == 'f') stock[c] = href, i = i + 4, c++;
        if (str[i] == 'f' && str[i + 1] == 'u' && str[i + 2] == 'n'
            && str[i + 3] == 'c' && str[i + 4] == 't' && str[i + 5] == 'i'
            && str[i + 6] == 'o' && str[i + 7] == 'n')
            stock[c] = fonction, i = i + 8, c++;
        stock = more_word(str, &i, stock, &c);
        if (a == i)
            stock[c] = str[i], i++, c++;
    }
    write(1, stock, my_strlen(stock));
}