/*
** EPITECH PROJECT, 2021
** ginger.c
** File description:
** duo stumper 2
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my.h"
#include "map.h"

map *parse_map(char const *fp);

void ginger(map *m);

int error(int ac, char **av)
{
    if (ac != 5) {
        write(2, "Error: 4 arguments needed\n", 26);
        return (84);
    }
    if (av[1][0] != 45 || (av[1][1] != 'f' && av[1][1] != 'm') || av[1][2] != 0
    || av[3][0] != 45 || (av[3][1] != 'f' && av[3][1] != 'm') ||
    av[3][2] != 0) {
        write(2, "Error: argument 1 and 3 must be -f or -m\n", 41);
        return (84);
    }
    for (int i = (av[1][1] == 'm' ? 2 : 4), j = 0; av[i][j] != 0; j++) {
        if (av[i][j] < 48 || av[i][j] > 57) {
            write(2, "Error: -m argument must be a positive integer\n", 46);
            return (84);
        }
    }
}

int parse_m(char **av)
{
    int e = 2;

    if (av[1][1] != 'm') {
        e = 4;
    }
    return my_getnbr(av[e]);
}

int preginger(char *fp, int n)
{
    map *m = parse_map(fp);

    if (m == NULL) {
        write(2, "invalid map!\n", 13);
        return 84;
    }
    m->moves = n;
    m->movetot = n;
    ginger(m);
    return 0;
}

int main(int ac, char **av)
{
    if (error(ac, av) == 84) return (84);
    return preginger(av[1][1] == 'f' ? av[2] : av[4], parse_m(av));
}
