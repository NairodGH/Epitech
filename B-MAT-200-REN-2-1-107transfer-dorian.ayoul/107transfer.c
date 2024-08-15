/*
** EPITECH PROJECT, 2021
** 107transfer.c
** File description:
** Polytechnical Polynomials
*/

#include <math.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

double horner(char *av, double x)
{
    int *poly;
    int n = 1;
    double result;

    for (int i = 0; av[i] != 0; i++)
        if (av[i] == '*') n++;
    poly = malloc(sizeof(int) * n);
    for (int i = 0, j = 0, neg = 1; av[i] != 0; i++) {
        if (av[i] == '*') i++, j++;
        if (av[i] == '-') neg = -1, i++;
        poly[j] *= 10, poly[j] += av[i] - 48, poly[j] *= neg, neg = 1;
    }
    for (int i = 0, temp; i < n / 2; i++) {
        temp = poly[i];
        poly[i] = poly[n - 1 - i];
        poly[n - 1 - i] = temp;
    }
    result = poly[0];
    for (int i = 1; i < n; i++)
        result = result * x + poly[i];
    return (result);
}

int main(int ac, char **av)
{
    if (ac < 3) {
        printf("[ERROR] There must be at least 2 polynomials (currently %d)\n", ac - 1);
        return (84);
    }
    if (ac % 2 == 0) {
        printf("[ERROR] There must be an even number of polynomials (currently %d)\n", ac - 1);
        return (84);
    }
    for (int i = 1; i != ac; i++) {
        for (int j = 0; av[i][j] != 0; j++) {
            if (!(av[i][j] == '*' || av[i][j] == '-' || av[i][j] >= '0' && av[i][j] <= '9')) {
                printf("[ERROR] Polynomial %d (%s) isn't made up of only '0123456789*'\n", ac - 1, av[i]);
                return (84);
            }
            if (av[i][j] == '*' && (av[i][j + 1] == '*' || av[i][j + 1] == 0) || av[i][0] == '*') {
                printf("[ERROR] Polynomial %d (%s) syntax isn't like '0*1*2'\n", ac - 1, av[i]);
                return (84);
            }
        }
    }

    for (double x = 0.0, fx = 1.0; x < 1.001; x += 0.001, fx = 1.0) {
        for (int i = 1; i < ac; i += 2) {
            if (horner(av[i + 1], x) == 0) {
                printf("[ERROR] The polynomial denominator %s is 0 for x = %.3f\n", av[i], x);
                return (84);
            }
            fx *= horner(av[i], x) / horner(av[i + 1], x);
        }
        printf("%.3f -> %.5f\n", x, fx);
    }
    return (0);
}