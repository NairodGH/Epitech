/*
** EPITECH PROJECT, 2021
** ope_square_matrices.c
** File description:
** add/sub/mul/div 2 square matrices of same size
*/

#include "../../../lib.h"

void add_square_matrices(double **mat1, double **mat2, double **res, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void sub_square_matrices(double **mat1, double **mat2, double **res, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void mul_square_matrices(double **mat1, double **mat2, double **res, int size)
{
    double **tmp = alloc_2d_double(size, size);

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

double **ope_square_matrices(double **mat1, double **mat2, int size, char *ope)
{
    double **res = alloc_2d_double(size, size);

    if (strings_are_identical(ope, "add"))
        add_square_matrices(mat1, mat2, res, size);
    if (strings_are_identical(ope, "sub"))
        sub_square_matrices(mat1, mat2, res, size);
    if (strings_are_identical(ope, "mul"))
        mul_square_matrices(mat1, mat2, res, size);
    return (res);
}