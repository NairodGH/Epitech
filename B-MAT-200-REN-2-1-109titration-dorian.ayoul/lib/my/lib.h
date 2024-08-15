/*
** EPITECH PROJECT, 2020
** lib.h
** File description:
** Header file for all the lib functions
*/

#ifndef LIB_H
#define LIB_H

#include <math.h>
#include <float.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

//libc
int strings_are_identical(char *str1, char *str2);
int str_is_positive_int(char *str);
int string_length(char *str);
void display_int(int nb);
void display_char(char c);
void my_putchar(char c);
int get_int(char *str);
size_t get_height(char *str);

//math
void get_square_matrix(char **av, double **mat, int k, int size);
void identity_matrix(double **mat, int size);
void copy_square_matrix(double **mat1, double **mat2, int size);
bool square_matrices_are_identical(double **mat1, double **mat2, int size);
bool square_matrix_is_null(double **mat1, int size);

double **ope_square_matrices(double **mat1, double **mat2, int size, char *ope);
void add_square_matrices(double **mat1, double **mat2, double **res, int size);
void sub_square_matrices(double **mat1, double **mat2, double **res, int size);
void mul_square_matrices(double **mat1, double **mat2, double **res, int size);

void div_square_matrix(double **mat, double div, double **res, int size);

void trigo_square_matrix(double **mat, double **res, int size, char *ope);

int power(int nb, int pow);

//alloc
double ***alloc_3d_double(int size_3d, int size_2d, int size_1d);
double **alloc_2d_double(int size_2d, int size_1d);

#endif