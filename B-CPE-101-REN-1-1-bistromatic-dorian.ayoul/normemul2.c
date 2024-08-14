/*
** EPITECH PROJECT, 2020
** swap arg
** File description:
** argv
*/

#include <stdlib.h>

int my_strlen3(int *tab);

int *check_ifzero(int *result, int z, int y);

int *my_calculmul(int *result, int a, int count);

int *equalize(int *result, int count);

int norme_e(int *resulteq, int e, int a, int count);

int *check_ret(int *result, int z);

int *mul_norme_ne(int *resulteq, int e, int a, int count);

int *tab_norme(int *tab, int *tab2, char **argv, int i)
{
    int a = my_strlen3(tab);
    int b = my_strlen3(tab2);
    int n = 0;

    if (a > b && argv[1][0] == '-' && i == 0) {
        while (tab[n] != 'f') {
            tab[n] = tab[n] * 1;
            n++;
        }
        return (tab);
    }
    if (argv[1][0] == '-' && i == 0) {
        while (tab[n] != 'f') {
            tab[n] = tab[n] * -1;
            n++;
        }
    }
    return (tab);
}

int *first_calcul(int *result, int *tab2, int *tabg, int a)
{
    int i = a;
    int c = a;
    int count = 0;
    int z = 0;
    int y = 0;

    while (tab2[i] != 'd') {count = 0;
        while (tabg[c] != 'd') {
            result[z] = result[z] + (tabg[c] * tab2[i]), result =
            check_ret(result, z), z++, c--, count++;
            if (result[z] > 9) {result[z] = 0;}
        }
        result[z] = '|', z++;
        if (tabg[i - 1] != 'd') {result = check_ifzero(result, z, y),
            ((y > 0) && (z = z + y)), z++, y++, i--, c = a;}
        else {break;}
    }
    (count = count + y, result[z] = 'f');
    (result = equalize(result, count), result = my_calculmul(result, a, count));
    return (result);
}

int *mul_calcul(int *result, int *resulteq, int count, int i)
{
    int a = 0;
    int e = 0;

    while (result[i] != 'f') {
        if (result[i] == '|') {
            resulteq = mul_norme_ne(resulteq, e, a, count);
            e = norme_e(resulteq, e, a, count);
            i++;
            a = 0;
        }
        resulteq[e] = result[i];
        e++;
        i++;
        a++;
    }
    resulteq[e] = 'f';
    return (resulteq);
}

int *mul_norme_ne(int *resulteq, int e, int a, int count)
{
    while (a != count) {
        resulteq[e] = 0;
        e++;
        a++;
    }
    return (resulteq);
}

int norme_e(int *resulteq, int e, int a, int count)
{
    while (a != count) {
        e++;
        a++;
    }
    return (e);
}
