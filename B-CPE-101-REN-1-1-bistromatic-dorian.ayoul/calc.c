/*
** EPITECH PROJECT, 2020
** Calculation shit from NPI
** File description:
** yes
*/

#include "my.h"
#include "bistromatic.h"
#include "ops.h"

char *sub(char *str, char *str2);

static void clean_reset(char **str, int *n)
{
    int i = (*n) + 1;
    if ((*n) == 0)
        return;
    (*n) -= 1;
    for (; str[i] != 0; i++) {
        str[*n] = str[i];
        (*n)++;
    }
    str[*n] = 0;
    (*n) = 0;
}

static void factors(char **str, int *n)
{
    if (str[*n][0] == '*') {
        str[*n - 2] = infin_mul(str[*n - 2], str[*n - 1]);
        clean_reset(str, n);
    }
    else if (str[*n][0] == '/') {
        str[*n - 2] = infin_div(str[*n - 2], str[*n - 1], 0);
        clean_reset(str, n);
    }
    else if (str[*n][0] == '%') {
        str[*n - 2] = infin_div(str[*n - 2], str[*n - 1], 1);
        clean_reset(str, n);
    }
}

void calc(char **str)
{
    int n = 0;

    for (n = 0; (str[n] != 0); n++) {
        if (str[n][0] == '+') {
            str[n - 2] = infin_add(str[n - 2], str[n - 1], 0, 0);
            clean_reset(str, &n);
        }
        else if (str[n][0] == '-' && str[n][1] == 0) {
            str[n - 2] = sub(str[n - 2], str[n - 1]);
            clean_reset(str, &n);
        }
        else
            factors(str, &n);
    }
    my_putstr(str[0]);
    my_putchar('\n');
}