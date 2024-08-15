/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function file for MAT 109titration project
*/

#include "../lib/my/lib.h"
#include "../include/my.h"

double divide(double a, double b)
{
    if (b == 0.0f) {
        write(2, "Error: divisor happened to be 0 at some point\n", 46);
        exit(84);
    }
    return (a / b);
}

void second_derivative_estimated(double *vol, double *der2, size_t max1)
{
    double *vol2 = malloc(sizeof(double) *
    (fabs(vol[max1 + 1] - vol[max1 - 1]) * 10.0f + 3.0f));
    double *der3 = malloc(sizeof(double) *
    (fabs(vol[max1 + 1] - vol[max1 - 1]) * 10.0f + 3.0f));
    size_t max2 = 0;
    size_t i = 1;

    der3[0] = DBL_MAX;
    vol2[1] = vol[max1 - 1];
    printf("\nSecond derivative estimated:\n");
    for (double a, b; vol2[i] <= vol[max1 + 1]; i++) {
        if (vol2[i] < vol[max1]) {
            a = divide(der2[max1] - der2[max1 - 1], vol[max1] - vol[max1 - 1]);
            b = der2[max1] - a * vol[max1];
        }
        else {
            a = divide(der2[max1 + 1] - der2[max1], vol[max1 + 1] - vol[max1]);
            b = der2[max1 + 1] - a * vol[max1 + 1];
        }
        der3[i] = a * vol2[i] + b;
        if (fabs(der3[i]) < fabs(der3[max2]))
            max2 = i;
        printf("%.1f ml -> %.2f\n", vol2[i], der3[i] + 0.0001f);
        if (vol2[i] < vol[max1])
            vol2[i + 1] = vol2[i] + (vol[max1] - vol2[i] < 0.1f ? vol[max1] - vol2[i] : 0.1f);
        else
            vol2[i + 1] = vol2[i] + (vol[max1 + 1] - vol2[i] < 0.1f && vol2[i] != vol[max1 + 1]
            ? vol[max1 + 1] - vol2[i] : 0.1f);
    }
    printf("\nEquivalence point at %.1f ml\n", vol2[max2]);
}

void second_derivative(double *vol, double *der1, size_t size, size_t max1)
{
    size_t i = 2;
    double *der2 = malloc(sizeof(double) * size);

    printf("Second derivative:\n");
    for (double ratio1, ratio2, coef1, coef2; i != size - 2; i++) {
        ratio1 = divide(der1[i] - der1[i - 1], vol[i] - vol[i - 1]);
        ratio2 = divide(der1[i + 1] - der1[i], vol[i + 1] - vol[i]);
        coef1 = divide(vol[i + 1] - vol[i], vol[i + 1] - vol[i - 1]);
        coef2 = divide(vol[i] - vol[i - 1], vol[i + 1] - vol[i - 1]);
        if (coef1 + coef2 != 1)
            exit(84);
        der2[i] = coef1 * ratio1 + coef2 * ratio2;
        printf("%.1f ml -> %.2f\n", vol[i], der2[i]);
    }
    second_derivative_estimated(vol, der2, max1);
}

void first_derivative(double *vol, double *ph, size_t size)
{
    size_t i = 1;
    size_t max1 = 0;
    double *der1 = malloc(sizeof(double) * size);

    printf("Derivative:\n");
    der1[0] = DBL_MIN;
    for (double ratio1, ratio2, coef1, coef2; i != size - 1; i++) {
        ratio1 = divide(ph[i] - ph[i - 1], vol[i] - vol[i - 1]);
        ratio2 = divide(ph[i + 1] - ph[i], vol[i + 1] - vol[i]);
        coef1 = divide(vol[i + 1] - vol[i], vol[i + 1] - vol[i - 1]);
        coef2 = divide(vol[i] - vol[i - 1], vol[i + 1] - vol[i - 1]);
        der1[i] = coef1 * ratio1 + coef2 * ratio2;
        if (der1[i] > der1[max1])
            max1 = i;
        printf("%.1f ml -> %.2f\n", vol[i], der1[i] - 0.0001f);
    }
    printf("\nEquivalence point at %.1f ml\n\n", vol[max1]);
    second_derivative(vol, der1, size, max1);
}

int main(int ac, char **av)
{
    double *vol;
    double *ph;
    struct stat st;
    int fd;
    char *buf;
    size_t size = 0;

    if (ac != 2 || stat(av[1], &st) == -1 || (fd = open(av[1], O_RDONLY)) == -1
        || !(buf = malloc(st.st_size + 1)) || read(fd, buf, st.st_size) == -1
        || st.st_size == 0)
        return (84);
    buf[st.st_size] = '\0';
    size += get_height(buf);
    vol = malloc(sizeof(double) * size);
    ph = malloc(sizeof(double) * size);
    if (file_syntax(buf, vol, ph) == 84 || get_file_values(buf, vol, ph) == 84)
        return (84);
    first_derivative(vol, ph, size);
    return (0);
}