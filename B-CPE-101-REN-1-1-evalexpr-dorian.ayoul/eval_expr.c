/*
** EPITECH PROJECT, 2020
** eval
** File description:
** expr
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>

int little_getnbr(int n, char *str, int i);

int *mult_parent(int *stockint, char *str, int a, int s);

int *create_stockint(int *stockint, char *str, int i, int s);

int my_operator2(int *result);

int my_operator(int *stockint, int s, int *result, int a)
{
    if (stockint[s] == 111111)
        result[a] = stockint[s - 1] + stockint[s + 1];
    if (stockint[s] == 111112)
        result[a] = stockint[s - 1] * stockint[s + 1];
    if (stockint[s] == 111113)
        result[a] = stockint[s - 1] - stockint[s + 1];
    if (stockint[s] == 111114)
        result[a] = stockint[s - 1] / stockint[s + 1];
    if (stockint[s] == 111115)
        result[a] = stockint[s - 1] % stockint[s + 1];
    return (result[a]);
}

int my_findop(char *str, int i, int *stockint, int s)
{
    if (str[i] == '+')
        stockint[s] = 111111;
    if (str[i] == '*')
        stockint[s] = 111112;
    if (str[i] == '-')
        stockint[s] = 111113;
    if (str[i] == '/')
        stockint[s] = 111114;
    if (str[i] == '%')
        stockint[s] = 111115;
    if (str[i] == '(')
        stockint[s] = 111116;
    if (str[i] == ')')
        stockint[s] = 111117;
    return (stockint[s]);
}

int my_calcul(int *stockint, int *result, int s, int a)
{
    int m = 0;
    int *me = stockint;

    while (stockint[s] != 'f') {
        result[a] = me[m];
        if (stockint[s] == 111114 || stockint[s] == 111112
            || stockint[s] == 111115) {
            a--;
            stockint[s - 1] = result[a];
            result[a] = my_operator(stockint, s, result, a);
            m++;
            s++;
        }
        m++;
        a++;
        s++;
    }
    result[a] = 'f';
    result[a] = my_operator2(result);
    return (result[a]);
}

int eval_expr(char *str)
{
    int i = 0;
    int a = 0;
    int s = 0;
    int *result = malloc(sizeof(int) * (my_strlen(str)));
    int *stockint = malloc(sizeof(int) * (my_strlen(str)));

    if (str[0] == '-') {
        while (str[i] == '-' || str[i] == '+')
            i++;
        stockint[s] = little_getnbr(stockint[s], str, i);
        stockint[s] = stockint[s] * -1;
        s++;
        i++;
    }
    stockint = create_stockint(stockint, str, i, s);
    s = 0;
    a = 0;
    stockint = mult_parent(stockint, str, a, s);
    result[a] = my_calcul(stockint, result, s, a);
    return (result[a]);
}

int  main(int ac , char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return  (0);
    }
    return  (84);
}
