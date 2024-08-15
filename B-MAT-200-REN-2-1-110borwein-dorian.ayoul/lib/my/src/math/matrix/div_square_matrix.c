/*
** EPITECH PROJECT, 2021
** div_square_matrix.c
** File description:
** divide a matrix by a scalar (number)
*/

void div_square_matrix(double **mat, double div, double **res, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            res[i][j] = mat[i][j] / div;
        }
    }
}