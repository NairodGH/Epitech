/*
** EPITECH PROJECT, 2020
** calcul pos
** File description:
** positif
*/

#include <stdlib.h>
#include "include/my.h"
#include <stdio.h>

int *check_tabsize_mult(int *tab, int *tab2, int a, int b);

int *my_calculmul(int *result, int a, int count);

int my_strlen3(int *tab);

int *first_calcul(int *result, int *tab2, int *tabg, int a);

int *check_ret(int *result, int z)
{
    int c = 1;

    if (result[z] > 9) {
        while (result[z] > 19) {
            result[z] = result[z] - 10;
            c++;
        }
        result[z] = result[z] % 10;
        result[z + 1] = 0 + c;
    }
    return (result);
}

int *norme3(int *tab, int *tab2, int *result, int *tabg)
{
    int a = my_strlen3(tabg) - 1;
    int b = my_strlen3(tab2) - 1;
    int e = my_strlen3(tab) - 1;

    if (e > b)
        tab2 = tab;
    if (a == 1 && b == 1) {
        result[0] = tab2[1] * tabg[1];
        result[1] = 'f';
        return (result);
    }
    result = first_calcul(result, tab2, tabg, a);
    return (result);
}

char *my_calculmult1(int *tab, int *tab2)
{
    int z = 0;
    int *tabg = tab;
    int a = my_strlen3(tab);
    int b = my_strlen3(tab2);
    int *result = malloc(sizeof(int) * (a + b) + 10);
    char *lastresult = malloc(sizeof(char) * ((a + b) * (a + b)) * 5);
    int c = 0;

    result[0] = 0;
    if (!(a == b))
        tabg = check_tabsize_mult(tab, tab2, a, b);
    result = norme3(tab, tab2, result, tabg);
    while (result[z] == 0)
        z++;
    while (result[z] != 'f')
        (lastresult[c] = result[z] + 48, z++, c++);
    if (lastresult[c] == '|')
        lastresult[c] = '\0';
    free(result);
    return (lastresult);
}

int my_strlen3(int *tab)
{
    int i = 0;

    while (tab[i] != 'f')
        i++;
    return (i);
}
