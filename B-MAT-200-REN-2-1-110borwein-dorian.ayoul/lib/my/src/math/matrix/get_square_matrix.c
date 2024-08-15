/*
** EPITECH PROJECT, 2021
** get_square_matrix.c
** File description:
** get the square matrix from an av index
*/

#include <stdlib.h>

void get_square_matrix(char **av, double **mat, int k, int size)
{
    for (int i = 0; i != size; i++) {
        for (int j = 0; j != size; j++, k++) {
            mat[i][j] = atof(av[k]);
        }
    }
}