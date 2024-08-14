/*
** EPITECH PROJECT, 2020
** infin_sub
** File description:
** Performs infinite subtraction
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

char *infin_add(char *nb1, char *nb2, int i, int j);

void my_putneg(char *nb);

int my_neg(char *nb1, char *nb2, int i)
{
    if (nb1[0] == '-' && nb2[0] == '-') {
        for (i = 0; nb1[i + 1] != '\0'; i++) nb1[i] = nb1[i + 1];
        nb1[i] = '\0';
        for (i = 0; nb2[i + 1] != '\0'; i++) nb2[i] = nb2[i + 1];
        nb2[i] = '\0';
        return (3);
    }
    else if (nb1[0] == '-') {
        for (i = 0; nb1[i + 1] != '\0'; i++) nb1[i] = nb1[i + 1];
        nb1[i] = '\0';
        return (1);
    }
    else if (nb2[0] == '-') {
        for (i = 0; nb2[i + 1] != '\0'; i++) nb2[i] = nb2[i + 1];
        nb2[i] = '\0';
        return (2);
    }
    return (0);
}

int my_is_bigger(char *nb1, char *nb2)
{
    if (my_strlen(nb1) > my_strlen(nb2))
        return (1);
    if (my_strlen(nb1) < my_strlen(nb2))
        return (-1);
    if (my_strlen(nb1) == my_strlen(nb2)) {
        if (my_strcmp(nb1, nb2) > 0)
            return (1);
        if (my_strcmp(nb1, nb2) == 0)
            return (0);
        if (my_strcmp(nb1, nb2) < 0)
            return (-1);
    }
}

char *my_sub_by_add(char *res, int i, char *nb1, char *nb2)
{
    for (; nb2[i] != '\0'; i++)
        res[i] = nb2[i];
    my_revstr(res);
    for (i = 0; res[i] == '0';)
        i++;
    res[i] = (10 - (res[i] - 48)) + 48;
    for (i++; res[i] != '\0'; i++) {
        res[i] = (9 - (res[i] - 48)) + 48;
    }
    for (; my_strlen(nb1) > my_strlen(res); i++) {
        res[i] = '9';
        res[i + 1] = '\0';
    }
    my_revstr(res);
    res = infin_add(nb1, res, 0, 0);
    return (res);
}

char *my_suppr_first(char *res, int i, int neg)
{
    while (res[1] == '0') {
        for (i = 1; res[i + 1] != '\0'; i++)
            res[i] = res[i + 1];
        res[i] = '\0';
    }
    if (neg == 4)
        res[0] = '-';
    else {
        for (i = 0; res[i + 1] != '\0'; i++)
            res[i] = res[i + 1];
        res[i] = '\0';
    }
    return (res);
}

char *infin_sub(char *nb1, char *nb2)
{
    int i = 0;
    int neg = my_neg(nb1, nb2, 0);
    char *temp = nb1;
    char *res = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2)));

    if (neg == 3) return (infin_add(nb1, nb2, 3, 0));
    if (my_is_bigger(nb1, nb2) == -1) {
        if (neg == 2)
            neg = 4;
        nb1 = nb2, nb2 = temp;
    }
    else if (my_is_bigger(nb1, nb2) == 0) return ("0");
    else if (neg == 1)
        neg = 4;
    res = my_sub_by_add(res, i, nb1, nb2);
    res = my_suppr_first(res, i, neg);
    if (neg == 3) {my_putneg(nb1), my_putneg(nb2);}
    else if (neg == 1) {my_putneg(nb1);}
    else if (neg == 2) {my_putneg(nb2);}
    return (res);
}