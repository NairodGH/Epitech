/*
** EPITECH PROJECT, 2021
** square_matrices_are_identical.c
** File description:
** Checks if 2 square matrices are identical
*/

#include "../../../lib.h"

bool square_matrices_are_identical(double **mat1, double **mat2, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (mat1[i][j] != mat2[i][j])
                return (false);
    return (true);
}