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

char *my_calculsub(int *tab, int *tab2);

int my_strlen3_sub(int *tab);

int *norme_tabsize_sub(int *tab, int *tab2, int a, int b);

int *check_tabsize_sub(int *tab, int *tab2, int a, int b)
{
    int c = a - b;
    int i = 0;
    int z = 0;
    int *tabg;

    if (a > b) {
        tabg = malloc(sizeof(int) * (a + 1));
        while (i < c) {
            tabg[i] = 0;
            i++;
        }
        while (tab2[z] != 'f') {
            tabg[i] = tab2[z];
            i++;
            z++;
        }
        return (tabg);
    }
    tabg = norme_tabsize_sub(tab, tab2, a, b);
    return (tabg);
}

int *norme_tabsize_sub(int *tab, int *tab2, int a, int b)
{
    int d = b - a;
    int i = 0;
    int z = 0;
    int *tabg;

    if (a < b) {
        tabg = malloc(sizeof(int) * (b + 1));
        while (i < d) {
            tabg[i] = 0;
            i++;
        }
        while (tab[z] != 'f') {
            tabg[i] = tab[z];
            i++;
            z++;
        }
        return (tabg);
    }
}

int *check_norme_sub(char *str, int *tab, int a, int b)
{
    int i = 0;

    if (a == 1) {
        while (str[i] != '\0') {
            tab[b] = str[i] - 48;
            b++;
            i++;
        }
        tab[b] = 'f';
    }
    if (a == 0) {
        while (str[i] != '\0') {
            tab[a] = str[i] - 48;
            a++;
            i++;
        }
        tab[a] = 'f';
    }
    return (tab);
}

char *sub(char *str, char *str2)
{
    int a = 1;
    int b = 0;
    int *tab = malloc(sizeof(int) * (my_strlen(str) + 2));
    int *tab2 = malloc(sizeof(int) * (my_strlen(str2) * 10));

    tab = check_norme_sub(str, tab, a, b);
    b = 2;
    a = 0;
    tab2 = check_norme_sub(str2, tab2, a, b);
    return (my_calculsub(tab, tab2));
}
