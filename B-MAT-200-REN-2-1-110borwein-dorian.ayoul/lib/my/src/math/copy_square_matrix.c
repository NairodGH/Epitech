/*
** EPITECH PROJECT, 2021
** copy_square_matrix.c
** File description:
** copy a matrix onto another
*/

void copy_square_matrix(double **mat1, double **mat2, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mat2[i][j] = mat1[i][j];
        }
    }
}