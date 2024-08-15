/*
** EPITECH PROJECT, 2020
** my_sokoban.c
** File description:
** A warehouse keeper game
*/

#include <ncurses.h>
#include <errno.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my.h"

int m(char *str, int mode)
{
    int nb = 0;

    for (int i = 0; mode == 0 && str[i] != '\0'; i++)
        if (str[i] == '\n' || str[i + 1] == '\0')
            nb++;
    while (mode == 1 && str[nb - 1] != '\n' && str[nb] != '\0')
        nb++;
    while (mode == 2 && str[nb] != '\0')
        nb++;
    for (int i = 0; mode == 3 && str[i] != 0; i++)
        if (str[i] == 'P')
            nb = i;
    for (int i = 0; mode == 4 && str[i] != 0; i++)
        if (str[i] == 'O')
            nb++;
    return (nb);
}

void start_end(boards b, int mode)
{
    if (mode == 0) {
        for (int i = 0; i != m(b.b, 2); i++) {
            b.t[i] = ' ';
            b.s[i] = b.b[i];
        }
        initscr();
        keypad(stdscr, TRUE);
    }
    if (mode == 1) {
        endwin();
        write(1, b.b, m(b.b, 2));
        free(b.b);
        free(b.t);
        free(b.s);
    }
}

int sokoban(boards b)
{
    start_end(b, 0);
    for (int r, c, p = m(b.b, 3);;) {
        getmaxyx(stdscr, r, c);
        clear();
        if (r < m(b.b, 0) || c < m(b.b, 1))
            mvprintw(r / 2, c / 2 - 5, "Too small");
        else
            printw(b.b);
        p = get_input(p, b);
        if (m(b.b, 4) == 0 && b.t[p] != 'O') break;
    }
    start_end(b, 1);
}

int check_errors(boards b)
{
    for (int i = 0, p = 0, x = 0, _o = 0; b.b[i] != 0; i++) {
        if (b.b[i] != 10 && b.b[i] != 32 && b.b[i] != 35 &&
            b.b[i] != 79 && b.b[i] != 80 && b.b[i] != 88)
            return (84);
        if (b.b[i] == 'P')
            p++;
        if (b.b[i] == 'O')
            _o++;
        if (b.b[i] == 'X')
            x++;
        if (b.b[i + 1] == 0 && (_o != x || _o == 0 || p != 1))
            return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    int fd;
    struct stat st;
    boards b;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        write(1, "USAGE\n\t./my_sokoban map\nDESCRIPTION\n\tmap file ", 46);
        write(1, "representing the warehouse map, containing '#' for ", 51);
        write(1, "walls,\n\t'P' for the player, 'X' for boxes and 'O' ", 50);
        write(1, "for storage locations.\n", 23);
        return (0);
    }
    if (ac != 2 || stat(av[1], &st) == -1 || (fd = open(av[1], O_RDONLY)) == -1
        || (!(b.b = malloc(st.st_size)) || read(fd, b.b, st.st_size) == -1))
        return (84);
    b.t = malloc(m(b.b, 2));
    b.s = malloc(m(b.b, 2));
    if (check_errors(b) == 84 || b.b[0] == 0)
        return (84);
    else
        return (sokoban(b));
}