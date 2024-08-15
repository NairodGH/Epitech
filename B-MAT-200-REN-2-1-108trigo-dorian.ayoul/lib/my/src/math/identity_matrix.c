/*
** EPITECH PROJECT, 2021
** identity_matrix.c
** File description:
** set a matrix to an identity matrix
*/

void identity_matrix(double **mat, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j)
                mat[i][j] = 1;
            else
                mat[i][j] = 0;
        }
    }
}