/*
** EPITECH PROJECT, 2021
** trigo_square_matrix.c
** File description:
** performs a exp/sin/sinh/cos/cosh on a square matrix
*/

#include "../../../lib.h"

void initiation(double ***tmp, char *ope, int size)
{
    identity_matrix(tmp[1], size);
    if (ope[0] == 'e')
        add_square_matrices(tmp[1], tmp[0], tmp[1], size);
    if (ope[0] == 's')
        copy_square_matrix(tmp[0], tmp[1], size);
    copy_square_matrix(tmp[0], tmp[3], size);
}

void process_ope(double ***tmp, double var[3], char *ope, int size) {
    copy_square_matrix(tmp[1], tmp[4], size);
    mul_square_matrices(tmp[3], tmp[0], tmp[3], size);
    if (ope[0] == 's')
        mul_square_matrices(tmp[3], tmp[0], tmp[3], size);
    copy_square_matrix(tmp[3], tmp[2], size);
    div_square_matrix(tmp[2], var[2], tmp[2], size);
    if ((int)var[0] % 2 ||
        strings_are_identical(ope, "exp") ||
        strings_are_identical(ope, "cosh") ||
        strings_are_identical(ope, "sinh"))
        add_square_matrices(tmp[1], tmp[2], tmp[1], size);
    else
        sub_square_matrices(tmp[1], tmp[2], tmp[1], size);
    if (ope[0] == 'c')
        mul_square_matrices(tmp[3], tmp[0], tmp[3], size);
}

void trigo_square_matrix(double **mat, double **res, int size, char *ope)
{
    double ***tmp = alloc_3d_double(5, size, size);
    double var[3] = {2, ope[0] == 's' ? 3 : 2, ope[0] == 's' ? 6 : 2};

    copy_square_matrix(mat, tmp[0], size);
    copy_square_matrix(res, tmp[1], size);
    initiation(tmp, ope, size);
    for (;;) {
        process_ope(tmp, var, ope, size);
        if (ope[0] == 'e')
            var[2] *= ++var[0];
        else {
            var[0]++;
            var[2] *= ++var[1] * ++var[1];
        }
        if (square_matrices_are_identical(tmp[1], tmp[4], size)
            || square_matrix_is_null(tmp[1], size)) {
            copy_square_matrix(tmp[1], res, size);
            break;
        }
    }
}