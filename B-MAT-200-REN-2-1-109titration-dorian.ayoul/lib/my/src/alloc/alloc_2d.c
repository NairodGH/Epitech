/*
** EPITECH PROJECT, 2021
** alloc_2d.c
** File description:
** allocates a 2d array with his 1d array(s)
*/

#include "../../lib.h"

double **alloc_2d_double(int size_2d, int size_1d)
{
    double **alloc = malloc(sizeof(double *) * size_2d);

    if (alloc == NULL)
        return (NULL);
    for (int i = 0; i != size_2d; i++) {
        alloc[i] = malloc(sizeof(double) * size_1d);
        if (alloc[i] == NULL)
            return (NULL);
    }
    return (alloc);
}