/*
** EPITECH PROJECT, 2020
** commands.c
** File description:
** commands-related functions
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

int up(int p, boards b)
{
    if (p - m(b.b, 1) > 0) {
        if (b.b[p - m(b.b, 1)] == 'X' &&
            (b.b[p - m(b.b, 1) * 2] == ' ' || b.b[p - m(b.b, 1) * 2] == 'O')) {
            b.b[p - m(b.b, 1)] = b.t[p - m(b.b, 1)];
            b.t[p - m(b.b, 1) * 2] = b.b[p - m(b.b, 1) * 2];
            b.b[p - m(b.b, 1) * 2] = 'X';
            b.b[p] = b.t[p];
            b.t[p - m(b.b, 1)] = b.b[p - m(b.b, 1)];
            b.b[p - m(b.b, 1)] = 'P';
            p -= m(b.b, 1);
        }
        if (b.b[p - m(b.b, 1)] == ' ' || b.b[p - m(b.b, 1)] == 'O') {
            b.b[p] = b.t[p];
            b.t[p - m(b.b, 1)] = b.b[p - m(b.b, 1)];
            b.b[p - m(b.b, 1)] = 'P';
            p -= m(b.b, 1);
        }
    }
    return (p);
}

int down(int p, boards b)
{
    if (p + m(b.b, 1) < m(b.b, 2)) {
        if (b.b[p + m(b.b, 1)] == 'X' &&
            (b.b[p + m(b.b, 1) * 2] == ' ' || b.b[p + m(b.b, 1) * 2] == 'O')) {
            b.b[p + m(b.b, 1)] = b.t[p + m(b.b, 1)];
            b.t[p + m(b.b, 1) * 2] = b.b[p + m(b.b, 1) * 2];
            b.b[p + m(b.b, 1) * 2] = 'X';
            b.b[p] = b.t[p];
            b.t[p + m(b.b, 1)] = b.b[p + m(b.b, 1)];
            b.b[p + m(b.b, 1)] = 'P';
            p += m(b.b, 1);
        }
        if (b.b[p + m(b.b, 1)] == ' ' || b.b[p + m(b.b, 1)] == 'O') {
            b.b[p] = b.t[p];
            b.t[p + m(b.b, 1)] = b.b[p + m(b.b, 1)];
            b.b[p + m(b.b, 1)] = 'P';
            p += m(b.b, 1);
        }
    }
    return (p);
}

int left(int p, boards b)
{
    if ((p - 1) / m(b.b, 1) == p / m(b.b, 1)) {
        if (b.b[p - 1] == 'X' && (b.b[p - 2] == ' ' || b.b[p - 2] == 'O')) {
            b.b[p - 1] = b.t[p - 1];
            b.t[p - 2] = b.b[p - 2];
            b.b[p - 2] = 'X';
            b.b[p] = b.t[p];
            b.t[p - 1] = b.b[p - 1];
            b.b[p - 1] = 'P';
            p--;
        }
        if (b.b[p - 1] == ' ' || b.b[p - 1] == 'O') {
            b.b[p] = b.t[p];
            b.t[p - 1] = b.b[p - 1];
            b.b[p - 1] = 'P';
            p--;
        }
    }
    return (p);
}

int right(int p, boards b)
{
    if ((p + 1) / m(b.b, 1) == p / m(b.b, 1)) {
        if (b.b[p + 1] == 'X' && (b.b[p + 2] == ' ' || b.b[p + 2] == 'O')) {
            b.b[p + 1] = b.t[p + 1];
            b.t[p + 2] = b.b[p + 2];
            b.b[p + 2] = 'X';
            b.b[p] = b.t[p];
            b.t[p + 1] = b.b[p + 1];
            b.b[p + 1] = 'P';
            p++;
        }
        if (b.b[p + 1] == ' ' || b.b[p + 1] == 'O') {
            b.b[p] = b.t[p];
            b.t[p + 1] = b.b[p + 1];
            b.b[p + 1] = 'P';
            p++;
        }
    }
    return (p);
}

int get_input(int p, boards b)
{
    switch (getch()) {
        case KEY_UP:
            p = up(p, b);
            break;
        case KEY_DOWN:
            p = down(p, b);
            break;
        case KEY_LEFT:
            p = left(p, b);
            break;
        case KEY_RIGHT:
            p = right(p, b);
            break;
        case ' ':
            for (int i = 0; i != m(b.b, 2); i++, p = m(b.b, 3))
                b.b[i] = b.s[i];
            break;
    }
    return (p);
}