/*
** EPITECH PROJECT, 2020
** infin_add
** File description:
** Performs infinite addition
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

char *get_res(char *res, int k, int ret, int neg)
{
    if (ret == 1 && neg == 3) {
        res[k] = '1';
        res[k + 1] = '-';
    }
    else if (ret == 1)
        res[k] = '1';
    else if (neg == 3)
        res[k] = '-';
    return (my_revstr(res));
}

char *infin_add(char *nb1, char *nb2, int i, int j)
{
    int k = 0;
    int neg = i;
    int ret = 0;
    char *res = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2)));

    my_revstr(nb1);
    my_revstr(nb2);
    for (i = 0; nb1[i] != '\0' && nb2[j] != '\0'; i++, j++, k++)
        ((((nb1[i] + nb2[j]) - 48) + ret) > '9') ?
        (res[k] = ((((nb1[i] + nb2[j]) - 96) + ret) % 10) + 48, ret = 1)
    : (res[k] = ((nb1[i] + nb2[j]) - 48) + ret, ret = 0);
    for (; nb1[i] == '\0' && nb2[j] != '\0'; j++, k++)
        ((nb2[j] - 48) + ret > 9) ? (res[k] = (((nb2[j] - 48) + ret) % 10) + 48
    , ret = 1) : (res[k] = ((nb2[j] - 48) + ret) + 48, ret = 0);
    for (; nb1[i] != '\0' && nb2[j] == '\0'; i++, k++)
        ((nb1[i] - 48) + ret > 9) ? (res[k] = (((nb1[i] - 48) + ret) % 10) + 48
    , ret = 1) : (res[k] = ((nb1[i] - 48) + ret) + 48, ret = 0);
    my_revstr(nb1);
    my_revstr(nb2);
    return (get_res(res, k, ret, neg));
}