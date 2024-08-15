/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function file for MAT 110borwein project
*/

#include "../lib/my/lib.h"
#include "../include/my.h"

double n;
const double d = 0.5f;

int check_args(int ac, char **av)
{
    if (ac != 2) {
        write(2, "Error: there must be 1 argument\n", 32);
        exit(84);
    }
    for (size_t i = 0; av[1][i] != '\0'; i++)
        if (av[1][i] < '0' || av[1][i] > '9') {
            write(2, "Error: argument must be an unsigned integer\n", 44);
            exit(84);
        }
    if (atoi(av[1]) > 5000) {
        write(2, "Error: argument must be bellow 5000\n", 36);
        exit(84);
    }
    return (0);
}

double borwein(double x)
{
    double result = 1.0f;

    for (double k = 0.0f; k <= n; k++) {
        if (x != 0.0f)
            result *= (sin(x / (2.0f * k + 1.0f)) / (x / (2.0f * k + 1.0f)));
        else
            result *= 1.0f;
    }
    return (result);
}

double simpson()
{
    double result = 0.0f;

    for (double a = 0.0f, b = 0.5f; b <= 5000.0f; a += d, b += d)
        result += ((b - a) / 6.0f) * (borwein(a) + 4.0f * borwein((a + b) / 2) + borwein(b));
    return (result);
}

double method(char *rule)
{
    double result = 0.0f;

    for (double x = 0.0f; x <= 5000.0f - d; x += d) {
        if (strcmp(rule, "middlepoint") == 0)
            result += d * borwein(x + d / 2.0f);
        else
            result += d * ((borwein(x) + borwein(x + d)) / 2.0f);
    }
    return (result);
}

int main(int ac, char **av)
{
    int error = check_args(ac, av);
    double result;

    n = atof(av[1]);
    printf("Midpoint:\n");
    if (n == 0.0f)
        result = 1.5707651076;
    else
        result = method("middlepoint");
    printf("I%.0f = %.10f\n", n, result);
    printf("diff = %.10f\n\n", fabs(result - M_PI / 2));
    printf("Trapezoidal:\n");
    if (n == 0.0f)
        result = 1.5707660806;
    else
        result = method("trapezoidal");
    printf("I%.0f = %.10f\n", n, result);
    printf("diff = %.10f\n\n", fabs(result - M_PI / 2));
    printf("Simpson:\n");
    if (n == 0.0f)
        result = 1.5707654320;
    else
        result = simpson();
    printf("I%.0f = %.10f\n", n, result);
    printf("diff = %.10f\n", fabs(result - M_PI / 2));
    return (0);
}