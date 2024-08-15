/*
** EPITECH PROJECT, 2021
** add_square_matrices.c
** File description:
** adds 2 square matrices
*/

void add_square_matrices(double **mat1, double **mat2, double **res, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}