/*
** EPITECH PROJECT, 2020
** infin_div
** File description:
** Performs infinite division
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"

char *infin_add(char *nb1, char *nb2, int i, int j);

int my_is_bigger(char *nb1, char *nb2);

char *infin_sub(char *nb1, char *nb2);

int my_neg(char *nb1, char *nb2);

void err_print(int type);

void my_special_cases(char *nb1, char *nb2)
{
    if ((nb1[0] == '0' && nb1[1] == '\0') || my_is_bigger(nb2, nb1) == 1)
        exit(0);
    else if (nb2[0] == '0' && nb2[1] == '\0')
        err_print(0);
}

void my_putneg(char *nb)
{
    my_revstr(nb);
    nb[my_strlen(nb)] = '-';
    my_revstr(nb);
}

char *my_modulo(char *nb1, char *nb2, char *res, char *i)
{
    char *modulo = malloc(sizeof(char) * (my_strlen(nb2)) + 1);

    my_putneg(nb2);
    i = infin_sub(i, nb2);
    my_putneg(i);
    modulo = infin_sub(nb1, i);
    i[0] = '-';
    i[1] = '1';
    i[2] = '\0';
    res = infin_sub(res, i);
    return (modulo);
}

char *my_res(char *nb1, char *nb2, char *res, char *i)
{
    char *modulo = malloc(sizeof(char) * (my_strlen(nb2)) + 1);

    my_putneg(nb2);
    i = infin_sub(i, nb2);
    my_putneg(i);
    modulo = infin_sub(nb1, i);
    i[0] = '-';
    i[1] = '1';
    i[2] = '\0';
    res = infin_sub(res, i);
    return (res);
}

char *infin_div(char *nb1, char *nb2, int mod)
{
    char *res = malloc(sizeof(char) * (my_strlen(nb1)) + 1);
    char *i = malloc(sizeof(char) * (my_strlen(nb1)) + 1);
    char *modulo = malloc(sizeof(char) * (my_strlen(nb2)) + 1);
    int neg = my_neg(nb1, nb2);

    my_special_cases(nb1, nb2);
    for (; my_is_bigger(nb1, i) == 1;) {
        i = infin_add(i, nb2, 0, 0);
        res = infin_add(res, "1", 0, 0);
    }
    if (my_is_bigger(i, nb1) == 1) {
        modulo = my_modulo(nb1, nb2, res, i);
        res = my_res(nb1, nb2, res, i);
    }
    else (modulo = "0");
    if (neg == 1 || neg == 2) (my_putneg(res), my_putneg(modulo));
    if (mod == 0) {return (res);}
    else {return (modulo);}
}