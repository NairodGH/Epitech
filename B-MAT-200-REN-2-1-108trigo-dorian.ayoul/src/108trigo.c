/*
** EPITECH PROJECT, 2021
** 108trigo.c
** File description:
** Further Fiddling with Fancy Fundamental Functions
*/

#include "../lib/my/lib.h"

int args_error_handling(int ac, char **av)
{
    if (ac != 3 && ac != 6 && ac != 11 && ac != 18 && ac != 27) {
        printf("Error: there aren't 1 + n² (n size of matrix) arguments (currently %d)\n", ac - 1);
        exit(84);
    }
    if (strcmp(av[1], "EXP") != 0 && strcmp(av[1], "COS") != 0 &&
        strcmp(av[1], "SIN") != 0 && strcmp(av[1], "COSH") != 0 &&
        strcmp(av[1], "SINH") != 0) {
        printf("Error: argument 1 (%s) is not EXP, COS, SIN, COSH or SINH\n", av[1]);
        exit(84);
    }
    for (int i = 2; i != ac; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] == '-' && j == 0)
                j++;
            if (av[i][j] < 48 || av[i][j] > 57) {
                printf("Error: matrix coefficient %d (%s) is not a valid integer\n", i - 1, av[i]);
                exit(84);
            }
        }
    }
    return (0);
}

void display_square_matrix(double **mat, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.2f", mat[i][j]);
            if (j != size - 1)
                printf("\t");
            else
                printf("\n");
        }
    }
}

int main(int ac, char **av)
{
    int error = args_error_handling(ac, av);
    int size = (int)sqrt(ac - 2);
    double **mat = alloc_2d_double(size, size);
    double **res = alloc_2d_double(size, size);

    get_square_matrix(av, mat, 2, size);
    if (strcmp(av[1], "EXP") == 0)
        trigo_square_matrix(mat, res, size, "exp");
    if (strcmp(av[1], "SINH") == 0)
        trigo_square_matrix(mat, res, size, "sinh");
    if (strcmp(av[1], "COSH") == 0)
        trigo_square_matrix(mat, res, size, "cosh");
    if (strcmp(av[1], "SIN") == 0)
        trigo_square_matrix(mat, res, size, "sin");
    if (strcmp(av[1], "COS") == 0)
        trigo_square_matrix(mat, res, size, "cos");
    display_square_matrix(res, size);
    return (0);
}