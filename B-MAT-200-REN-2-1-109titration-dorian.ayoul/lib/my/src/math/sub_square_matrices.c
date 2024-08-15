/*
** EPITECH PROJECT, 2021
** sub_square_matrices.c
** File description:
** substracts 2 square matrices
*/

void sub_square_matrices(double **mat1, double **mat2, double **res, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}