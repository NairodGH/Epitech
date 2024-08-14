/*
** EPITECH PROJECT, 2020
** my_calculmult
** File description:
** norme
*/

#include <stdlib.h>

int my_norme_calculmult(int *result, int result2, int a, int z);

int norme_norme(int *result, int a , int count, int reg);

int my_strlen3(int *tab);

int *check_ret2(int *result, int i, int e)
{
    int c = 1;

    if (result[i] > 9) {
        while (result[i] > 19) {
            result[i] = result[i] - 10;
            c++;
        }
        result[i] = result[i] % 10;
        result[i + 1] = result[i + 1] + c;
    }
    return (result);
}

int *my_swapint(int *result2, int a)
{
    int temp;
    int z = my_strlen3(result2) - 1;
    int i = 0;
    int e = z / 2;

    while (z != e) {
        temp = result2[i];
        result2[i] = result2[z];
        result2[z] = temp;
        z--;
        i++;
    }
    return (result2);
}

int *my_calculmul(int *result, int a, int count)
{
    int *result2 = malloc(sizeof(int) * (my_strlen3(result) * 10));
    int i = 0;
    int z = 0;
    int reg = 0;

    while (z != count) {
        result2[i] = result2[i] + result[z];
        reg = count + z;
        result2[i] = result2[i] + norme_norme(result, a , count, reg);
        result2 = check_ret2(result2, i, a);
        z++;
        i++;
    }
    if (result2[i] != 0)
        i++;
    result2[i] = 'f';
    result2 = my_swapint(result2, a);
    return (result2);
}
