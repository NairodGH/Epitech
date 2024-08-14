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

int *check_ret2(int *result, int i, int e);

int *mul_calcul(int *result, int *resulteq, int count, int i);

int *check_ret(int *result, int z);

int my_strlen3(int *tab);

int *check_ifzero(int *result, int z, int y)
{
    if (result[z] != 0) {
        result[z] = 0;
        result[z - 1] = result[z - 1] + 10;
    }
    if (y >= 1) {
        z++;
        while (y >= 0) {
            result[z] = 0;
            z++;
            y--;
        }
    }
    return (result);
}

int *equalize(int *result, int count)
{
    int i = 0;
    int ma = my_strlen3(result);
    int *resulteq = malloc(sizeof(int) * (ma + ma) * 5);

    resulteq = mul_calcul(result, resulteq, count , i);
    free(result);
    return (resulteq);
}

int norme_norme(int *result, int a , int count, int reg)
{
    int m = 1;
    int result2 = 0;

    while (m != a) {
        result2 = result2 + result[reg];
        reg = reg + count;
        m++;
    }
    return (result2);
}
