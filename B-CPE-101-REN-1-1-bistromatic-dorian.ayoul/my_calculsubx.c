/*
** EPITECH PROJECT, 2020
** calcul pos
** File description:
** positif
*/

#include <stdlib.h>
#include "include/my.h"

int *check_tabsize_sub(int *tab, int *tab2, int a, int b);

int my_strcmp_int(int *s1, int *s2);

int *norme_equal(int * tab, int *tab2, int *result, int i);

int my_strlen3_sub(int *tab);

void my_free(int *tab, int *tab2, int *tabg, int *result);

int *check_ret_subb(int *result, int z, int *tab2, int *tabg)
{
    int a = z - 1;

    if ((tabg[z - 1] - tab2[z - 1]) < 0) {
        tabg[z - 1] = tabg[z - 1] + 10;
        result[z - 1] = result[z - 1] - 1;
        while (result[a] < 0) {
            result[a] = result[a] + 10;
            result[a - 1] = result[a - 1] - 1;
            a--;
        }
    }
    return (result);
}

int *norme1_sub(int *tab, int *tab2, int *result, int *tabg)
{
    int a = my_strlen3_sub(tab);
    int b = my_strlen3_sub(tab2);
    int i = 0;
    int z = 1;
    int *temp;

    if (b > a) {
        temp = tabg;
        tabg = tab2;
        tab2 = temp;
        result[z] = 999, z++;
        while (tabg[i] != 'f') {
            result = check_ret_subb(result, z, tab2, tabg);
            result[z] = result[z] + (tabg[i] - tab2[i]);
            i++;
            z++;
        }
        result[z] = 'f';
    }
    return (result);
}

int *norme2_sub(int *tab, int *tab2, int *result, int *tabg)
{
    int i = 0;
    int z = 1;
    int a = my_strlen3_sub(tab);
    int b = my_strlen3_sub(tab2);


    if (a > b) {
        while (tab[i] != 'f') {
            result = check_ret_subb(result, z, tabg, tab);
            result[z] = result[z] + (tab[i] - tabg[i]);
            i++;
            z++;
        }
        result[z] = 'f';
    }
    return (result);
}

int *norme3_sub(int *tab, int *tab2, int *result, int *tabg)
{
    int i = 0;
    int z = 1;
    int a = my_strlen3_sub(tab);
    int b = my_strlen3_sub(tab2);
    int *temp;

    if (b == a) {
        if (my_strcmp_int(tab, tab2) == -1) {
            temp = tab;
            tab = tab2;
            tab2 = temp;
            result[z] = 999, i++;
        }
        result = norme_equal(tab, tab2, result, i);
    }
    return (result);
}

char *my_calculsub(int *tab, int *tab2)
{
    int z = 0;
    int a = my_strlen3_sub(tab);
    int b = my_strlen3_sub(tab2);
    int *tabg = tab;
    int *result = malloc(sizeof(int) * (a + b));
    char *lastresult = malloc(sizeof(char) * 100);

    if (!(a == b))
        tabg = check_tabsize_sub(tab, tab2, a, b);
    (result[0] = 0, result = norme1_sub(tab, tab2, result, tabg));
    result = norme2_sub(tab, tab2, result, tabg);
    (result = norme3_sub(tab, tab2, result, tabg), a = 0);
    while (result[z] == 0) {
        z++;
        if (result[z] == 999)
            (lastresult[a] = '-', a++, z++);
    }
    while (result[z] != 'f')
        (lastresult[a] = result[z] + 48, z++, a++);
    return (lastresult);
}
