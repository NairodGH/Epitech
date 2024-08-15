/*
** EPITECH PROJECT, 2021
** 106bombyx.c
** File description:
** Bombyx booming bylaw
*/

#include <math.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    if (ac != 3 && ac != 4) {
        printf("[ERROR] There should be 2 or 3 arguments (currently %d)\n", ac - 1);
        return (84);
    }
    for (int i = 1; i != ac; i++) {
        for (int j = 0, dot = 0; av[i][j] != 0; j++) {
            if (i == 2 && ac == 3 && av[i][j] == '.' && dot == 0) j++, dot++;
            if (av[i][j] < 48 || av[i][j] > 57) {
                printf("[ERROR] The argument %d (%s) is not a valid positive number\n", i - 1, av[i]);
                return (84);
            }
        }
    }
    if (ac == 3 && (atof(av[2]) < 1 || atof(av[2]) > 4)) {
        printf("[ERROR] The growth rate (%s) must be included between 1 and 4\n", av[2]);
        return (84);
    }
    if (ac == 4 && (atoi(av[2]) <= 0 || atoi(av[3]) <= 0)) {
        printf("[ERROR] The initial and final gens (%s and %s) must be non-null positives\n", av[2], av[3]);
        return (84);
    }
    if (ac == 4 && atoi(av[2]) > atoi(av[3])) {
        printf("[ERROR] The initial gen (%s) must be smaller than the final gen (%s)\n", av[2], av[3]);
        return (84);
    }
    if (ac == 3)
        for (double i = 1, n = atof(av[1]), k = atof(av[2]); i <= 100; i++)
            printf("%.0f %.2f\n", i, n > 0 ? n : 0), n *= k * ((1000 - n) / 1000);
    if (ac == 4) {
        for (double n, k = 1; k <= 4; k += 0.01) {
            n = atof(av[1]);
            for (int i = 1; i < atoi(av[2]); i++) n = n * k * ((1000 - n) / 1000);
            for (int i = atoi(av[2]); i <= atoi(av[3]); i++)
                printf("%.2f %.2f\n", k, n > 0 ? n : 0), n = n * k * ((1000 - n) / 1000);
        }
    }
    return (0);
}