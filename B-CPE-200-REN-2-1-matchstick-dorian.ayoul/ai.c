/*
** EPITECH PROJECT, 2020
** matchstick.c
** File description:
** "ai"-related functions
*/

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include "include/my.h"

void ai_display(int ln, int mn)
{
    write(1, "AI removed ", 11);
    putnbr(mn);
    write(1, " match(es) from line ", 21);
    putnbr(ln);
    write(1, "\n", 1);
}

int get_nimsum(int *n, int len)
{
    int nimsum = n[1];

    for (int i = 2; i < len; i++)
        nimsum = nimsum ^ n[i];
    return (nimsum);
}

int nimsum_not0(map m, int *n, int i, int max)
{
    int ln;
    int mn;
    int count = 0;

    for (int i = 1; i < m.h - 1; i++)
        if (n[i] > 0) count++;
    if ((n[i] ^ get_nimsum(n, m.h - 1)) < n[i]) {
        ln = i;
        mn = n[i] - (n[i] ^ get_nimsum(n, m.h - 1));
        if (!(count % 2) && stat(m, ln) - mn == 1 && stat(m, 0) <= m.h)
            mn++;
        if ((count % 2) && stat(m, ln) - mn == 0 && stat(m, 0) <= m.h && mn > 1)
            mn--;
        if (mn > max) mn = max;
        ai_display(ln, mn);
        for (int j = m.w / 2 - 1 - ln + stat(m, ln); mn > 0; mn--, j--)
            m.m[ln][j] = ' ';
        return (1);
    }
    return (0);
}

void nimsum_0(map m, int *n, int max)
{
    int *not0 = malloc(sizeof(int) * (m.h - 2));
    int count = 0;
    int ln;
    int mn;

    for (int i = 1; i < m.h - 1; i++)
        if (n[i] > 0)
            not0[count++] = i;
    ln = random() % count;
    mn = random() % n[not0[ln]];
    ln = not0[ln];
    mn++;
    if (mn > max)
        mn = max;
    ai_display(ln, mn);
    for (int j = m.w / 2 - 1 - ln + stat(m, ln); mn > 0; mn--, j--)
        m.m[ln][j] = ' ';
    free(not0);
}

void ai(map m, int max)
{
    int *n = malloc(sizeof(int) * (m.h - 1));

    write(1, "AI's turn...\n", 13);
    for (int i = 1; i < m.h - 1; i++)
        n[i] = stat(m, i);
    srandom(time(NULL));
    if (get_nimsum(n, m.h - 1) == 0)
        nimsum_0(m, n, max);
    else
        for (int i = 1; i < m.h - 1; i++)
            if (nimsum_not0(m, n, i, max)) break;
    for (int i = 0; i != m.h; i++) write(1, m.m[i], m.w);
    if (stat(m, 0) != 0)
        write(1, "\n", 1);
    else {
        write(1, "I lost... snif... but I'll get you next time!!\n", 47);
        errno = 1;
    }
    free(n);
    return;
}