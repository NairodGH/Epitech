/*
** EPITECH PROJECT, 2022
** array_1d_to_2d.c
** File description:
** concatenates strings
*/

#include <stdio.h>
#include <stdlib.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    size_t i = 0;

    (*res) = malloc(sizeof(int *) * height);
    for (size_t j = 0; j < height; j++) {
        (*res)[j] = malloc(sizeof(int) * width);
        for (size_t k = 0; k < width; k++)
            (*res)[j][k] = array[i++];
    }
}

void array_2d_free(int **array, size_t height, size_t width)
{
    if (height == 0 || width == 0)
        return;
    for (size_t i = 0; i < height; i++)
        free(array[i]);
    free(array);
}