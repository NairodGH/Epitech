/*
** EPITECH PROJECT, 2020
** do op
** File description:
** calcul
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "include/my.h"

char *my_calculmult1(int *tab, int *tab2);

int my_strlen3(int *tab);

int *norme_tabsize_mult(int *tab, int *tab2, int a, int b);

int *tabg_size_mult(int *tabg, int *tab2, int c)
{
    int i = 1;
    int z = 1;

    tabg[0] = 'd';
    while (i < c + 1) {
        tabg[i] = 0;
        i++;
    }
    while (tab2[z] != 'f') {
        tabg[i] = tab2[z];
        i++;
        z++;
    }
    tabg[i] = 'f';
    return (tabg);
}

int *check_tabsize_mult(int *tab, int *tab2, int a, int b)
{
    int c = a - b;
    int i = 1;
    int z = 1;
    int *tabg = malloc(sizeof(int) * (a + b));

    if (a > b) {
        tabg = tabg_size_mult(tabg, tab2, c);
        return (tabg);
    }
    tabg = norme_tabsize_mult(tab, tab2, a, b);
    return (tabg);
}

int *norme_tabsize_mult(int *tab, int *tab2, int a, int b)
{
    int d = b - a;
    int i = 1;
    int z = 1;
    int *tabg;

    if (a < b) {
        tabg = malloc(sizeof(int) * (a + b));
        tabg[0] = 'd';
        while (i < d + 1) {
            tabg[i] = 0;
            i++;
        }
        while (tab[z] != 'f') {
            tabg[i] = tab[z];
            i++;
            z++;
        }
        tabg[i] = 'f';
        return (tabg);
    }
}

int *create_multtab(char *str, int *tab, int a)
{
    int i = 0;
    int b = 2;

    while (str[i] == '-')
        i++;
    tab[0] = 'd';
    tab[1] = 0;
    while (str[i] != '\0') {
        tab[b] = str[i] - 48;
        b++;
        i++;
    }
    tab[b] = 'f';
    return (tab);
}

char *infin_mul(char *str, char *str2)
{
    int a = 1;
    int b = 2;
    char *null = "0";
    char *result;
    int *tab = malloc(sizeof(int) * (my_strlen(str) + 5));
    int *tab2 = malloc(sizeof(int) * (my_strlen(str2) + 5));

    if (str[0] == '0' && str[1] == '\0' || str2[0] == '0' && str2[1] == '\0')
        return (null);
    (tab = create_multtab(str, tab, a), a = 2);
    tab2 = create_multtab(str2, tab2, a);
    null = my_calculmult1(tab, tab2);
    (b = 0, a = 1);
    if ((str[0] == '-' || str2[0] == '-') && str[0] != str2[0]) {
        result = malloc(sizeof(char) * (my_strlen(null) + 10)), result[0] = '-';
        while (null[b] != '\0')
            result[a] = null[b], a++, b++;
        return (result);
    }
    return (null);
}
