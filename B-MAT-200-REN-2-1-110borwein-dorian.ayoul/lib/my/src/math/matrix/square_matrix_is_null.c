/*
** EPITECH PROJECT, 2021
** square_matrix_is_null.c
** File description:
** Checks if a square matrix is null
*/

#include "../../../lib.h"

bool square_matrix_is_null(double **mat1, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (mat1[i][j] != 0.0 && mat1[i][j] != -0.0)
                return (false);
    return (true);
}