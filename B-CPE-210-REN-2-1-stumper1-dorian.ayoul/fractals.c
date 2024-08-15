/*
** EPITECH PROJECT, 2021
** fractals.c
** File description:
** duo stumper
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/my.h"

int error(int ac, char **av)
{
    bool err = 0;

    if (!err && ac != 4)
        write(2, "there must be 4 args\n", 21), err = 1;
    for (int i = 1; !err && i != 4; i++)
        if (av[i][0] == '\0')
            write(2, "args must contain a value\n", 26), err = 1;
    for (int i = 0; !err && av[1][i] != '\0'; i++)
        if (av[1][i] < '0' || av[1][i] > '9')
            write(2, "arg 1 must be a positive integer\n", 33), err = 1;
    for (int i = 0; !err && av[2][i] != '\0'; i++)
        if (av[2][i] != '#' && av[2][i] != '@' && av[2][i] != '.')
            write(2, "arg 2 must contain #@. only\n", 29), err = 1;
    for (int i = 0; !err && av[3][i] != '\0'; i++)
        if (av[3][i] != '@' && av[3][i] != '.')
            write(2, "arg 3 must contain @. only\n", 28), err = 1;
    if (my_strlen(av[2]) != my_strlen(av[3]))
        write(2, "args 2 and 3 must have the same length\n", 41), err = 1; 
    if (err) return (84);
}

int error2(char **av)
{
    int *pos = malloc(sizeof(int) * my_strlen(av[2]));

    for (int i = 0; i != my_strlen(av[2]); i++) pos[i] = -1;
    for (int i = 0, j = 0; av[2][i] != '\0'; i++)
        if (av[2][i] == '@') pos[j] = i, j++;
    for (int i = 0; pos[i] != -1; i++) {
        if (av[3][pos[i]] != '@') {
            write(2, "args 2 and 3 must have the same @ positions\n", 44);
            return (84);
        }
    }
}

int main(int ac, char **av)
{
    if (error(ac, av) == 84) return (84);
    if (error2(av) == 84) return (84);
    if (av[1][0] == '0' && av[1][1] == '\0') write(1, "#\n", 2);
    return (0);
}
