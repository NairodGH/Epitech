/*
** EPITECH PROJECT, 2020
** matchstick.
** File description:
** Leave the last matchstick !
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "include/my.h"

char *player_display(int ln, int mn, char *b, int mode)
{
    size_t s = 0;

    if (mode == 0) {
        write(1, "Line: ", 6);
        getline(&b, &s, stdin);
    }
    if (mode == 1) {
        write(1, "Matches: ", 9);
        getline(&b, &s, stdin);
    }
    if (mode == 2) {
        write(1, "Player removed ", 15);
        putnbr(mn);
        write(1, " match(es) from line ", 21);
        putnbr(ln);
        write(1, "\n", 1);
    }
    return (b);
}

void map_display(map m, int ln, int mn)
{
    for (int j = m.w / 2 - 1 - ln + stat(m, ln); mn > 0; mn--, j--)
        m.m[ln][j] = ' ';
    for (int i = 0; i != m.h; i++)
        write(1, m.m[i], m.w);
    if (stat(m, 0) != 0)
        write(1, "\n", 1);
    else {
        write(1, "You lost, too bad...\n", 21);
        errno = 2;
    }
}

void player(map m, int max)
{
    char *b = NULL;
    int ln = 0;
    int mn = 0;

    for (write(1, "Your turn:\n", 11); ln == 0 || mn == 0;) {
        b = player_display(ln, mn, b, 0);
        if (l_err(b, m)) {
            ln = getnbr(b);
            if (!ln && !(errno = 0)) break;
            b = player_display(ln, mn, b, 1);
            if (m_err(b, ln, m, max)) mn = getnbr(b);
            else ln = 0;
            if (!mn && ln != 0 && !(errno = 0)) break;
        }
    }
    if (errno != 0) {
        b = player_display(ln, mn, b, 2);
        map_display(m, ln, mn);
    }
    free(b);
}

void create_map(map m)
{
    for (int i = 0; i != m.h; i++)
        m.m[i] = malloc(m.w);
    for (int i = 0; i != m.h; i++)
        for (int j = 0; j != m.w; j++)
            m.m[i][j] = '*';
    for (int i = 1; i != m.h - 1; i++)
        for (int j = 1; j != m.w - 2; j++)
            m.m[i][j] = ' ';
    for (int i = 0; i != m.h; i++)
        m.m[i][m.w - 1] = '\n';
    for (int i = 1; i != m.h - 1; i++)
        for (int j = m.w / 2 - i; j != m.w / 2 - 1 + i; j++)
            m.m[i][j] = '|';
}

int main(int ac, char **av)
{
    map m;

    if (error(ac, av) == 84)
        return (84);
    m.h = getnbr(av[1]) + 2;
    m.w = 2 + getnbr(av[1]) * 2;
    m.m = malloc(sizeof(char *) * m.h);
    create_map(m);
    for (int i = 0; i != m.h; i++)
        write(1, m.m[i], m.w);
    for (write(1, "\n", 1), errno = -1; stat(m, 0) != 0;) {
        player(m, getnbr(av[2]));
        if (stat(m, 0) == 0 || errno == 0) break;
        ai(m, getnbr(av[2]));
    }
    for (int i = 0; i != m.h; i++) free(m.m[i]);
    free(m.m);
    return (errno);
}