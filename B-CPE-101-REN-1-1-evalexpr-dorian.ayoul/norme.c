/*
** EPITECH PROJECT, 2020
** evalexpr
** File description:
** norme
*/

#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>

int little_getnbr(int n, char *str, int i);

int check_first(int z, int a);

int my_p(int *stockint, int s);

int check_par(int *stockint, int s);

int my_findop(char *str, int i, int *stockint, int s);

int my_calcul_par(int *stockint, int *result, int s, int a);

int my_operator(int *stockint, int s, int *result, int a);

int my_operator2(int *result)
{
    int a = 0;
    int i = 0;
    int *save = result;

    while (save[i] != 'f') {
        if (save[i] == 111111)
            result[a] = result[a] + save[i + 1];
        if (save[i] == 111112)
            result[a] = result[a] * save[i + 1];
        if (save[i] == 111113)
            result[a] = result[a] - save[i + 1];
        if (save[i] == 111114)
            result[a] = result[a] / save[i + 1];
        if (save[i] == 111115)
            result[a] = result[a] % save[i + 1];
        i++;
    }
    return (result[a]);
}

int *create_stockint(int *stockint, char *str, int i, int s)
{
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            while (str[i] >= '0' && str[i] <= '9') {
                stockint[s] = little_getnbr(stockint[s], str, i);
                i++;
            }
            s++;
        }
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '('
            || str[i] == '%' || str[i] == '/' || str[i] == ')') {
            stockint[s] = my_findop(str, i, stockint, s);
            s++;
            i++;
        }
    }
    stockint[s] = 'f';
    return (stockint);
}

int little_getnbr(int n, char *str, int i)
{
    n = str[i] + n - '0';
    n = n * 10;
    if (!(str[i + 1] >= '0' && str [i + 1] <= '9'))
        n = n / 10;
    return (n);
}

int check_rec(int *result)
{
    int a = 0;

    while (result[a] != 'f') {
        if (result[a] == 111116) {
            return (88888);
        }
        a++;
    }
    return (0);
}

int *mult_parent(int *stockint, char *str, int a, int s)
{
    int *result = malloc(sizeof(int) * (my_strlen(str) *2));
    int *me = stockint;

    while (me[s] != 'f') {
        result[a] = me[s];
        if (stockint[s] == 111116 && my_p(stockint, s) == 0) {
            s++;
            result[a] = my_calcul_par(stockint, result, s, a);
            while (stockint[s] != 111117)
                s++;
        }
        a++;
        s++;
    }
    result[a] = 'f';
    a = 0;
    s = 0;
    if (check_rec(result) == 88888)
        return (mult_parent(result, str, a, s));
    return (result);
}
