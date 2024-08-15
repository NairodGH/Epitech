/*
** EPITECH PROJECT, 2021
** alloc_3d.c
** File description:
** allocates a 3d array with his 1d array(s)
*/

#include "../../lib.h"

double ***alloc_3d_double(int size_3d, int size_2d, int size_1d)
{
    double ***alloc = malloc(sizeof(double **) * size_3d);

    if (alloc == NULL)
        return (NULL);
    for (int i = 0; i != size_3d; i++) {
        alloc[i] = malloc(sizeof(double *) * size_2d);
        if (alloc[i] == NULL)
            return (NULL);
        for (int j = 0; j != size_2d; j++) {
            alloc[i][j] = malloc(sizeof(double) * size_1d);
            if (alloc[i][j] == NULL)
                return (NULL);
        }
    }
    return (alloc);
}