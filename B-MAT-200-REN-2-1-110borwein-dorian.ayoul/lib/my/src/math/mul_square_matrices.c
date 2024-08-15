/*
** EPITECH PROJECT, 2021
** mul_square_matrices.c
** File description:
** multiplies 2 square matrices
*/

#include "../../lib.h"

void mul_square_matrices(double **mat1, double **mat2, double **res, int size)
{
    double **tmp = malloc(sizeof(double *) * size);

    for (int i = 0; i != size; i++)
        tmp[i] = malloc(sizeof(double) * size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < size; k++)
                tmp[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
    copy_square_matrix(tmp, res, size);
    for (int i = 0; i != size; i++)
        free(tmp[i]);
    free(tmp);
}