/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** ls -l bash command recoded
*/

#include <sys/sysmacros.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "include/my.h"

int args_parser(int ac, char **av, char **a)
{
    int i = 1;
    int j = 1;
    bool fa = 0;

    a[0] = malloc(6);
    for (int k = 0; k != 6; k++) a[0][k] = '\0';
    for (; i < ac && av[i][0] == '-'; i++) {
        for (int k = 1; av[i][k] != '\0'; k++) {
            (av[i][k] == 'l') && (a[0][0] = 'l');
            (av[i][k] == 'd') && (a[0][1] = 'd', a[0][3] = 'N', a[0][4] = 'N');
            (av[i][k] == 't' && a[0][3] != 'N') && (a[0][3] = 't');
            (av[i][k] == 'r' && a[0][4] != 'N') && (a[0][4] = 'r');
        }
    }
    for (; i < ac; i++, j++) {
        a[j] = malloc(my_len(av[i], 0));
        for (int k = 0; av[i][k] != '\0'; k++) a[j][k] = av[i][k];
        fa = 1;
    }
    return (fa);
}

void normal_print(char **f, int i, char mode)
{
    if (mode == 'n') {
        for (int k = 0; k != i; k++) {
            putstr(f[k], 0, 'n');
            (k + 1 != i) && (write(1, "  ", 2));
        }
        write(1, "\n", 1);
    }
    if (mode == 'r') {
        for (int k = --i; k != -1; k--) {
            putstr(f[k], 0, 'n');
            (k - 1 != -1) && (write(1, "  ", 2));
        }
        write(1, "\n", 1);
    }
}

int normal_form(char **a, char **f, int i)
{
    if (a[0][1] == 'd') write(1, ".\n", 2), exit(0);
    if (a[0][3] == 't') {
        if (a[0][4] == 'r') {
            time_sorter(f, i);
            normal_print(f, i, 'r');
            exit(0);
        }
        else {
            time_sorter(f, i);
            normal_print(f, i, 'n');
            exit(0);
        }
    }
    if (a[0][4] == 'r') {
        normal_print(f, i, 'r');
        exit(0);
    }
    normal_print(f, i, 'n');
}

int listing_form(char **a, char **f, int i, int total)
{
    write(1, "total ", 7), putstr("0", total / 2, 'i'), write(1, "\n", 1);
    if (a[0][3] == 't') {
        if (a[0][4] == 'r') {
            time_sorter(f, i);
            for (int k = --i; k != -1; k--) putstr(f[k], 0, 's');
            exit(0);
        }
        else {
            time_sorter(f, i);
            for (int k = 0; k != i; k++) putstr(f[k], 0, 's');
            exit(0);
        }
    }
    if (a[0][4] == 'r') {
        for (int k = --i; k != -1; k--) putstr(f[k], 0, 's');
        exit(0);
    }
    for (int k = 0; k != i; k++) putstr(f[k], 0, 's');
}

int main(int ac, char **av)
{
    char **a = malloc(sizeof(char *) * ac);
    data_struct d;
    char **f;
    int total = 0;
    bool fa = args_parser(ac, av, a);
    int i = 0;

    lstat((fa == 0) ? "." : a[1], &d.st), d.upw = getpwuid(d.st.st_uid),
    d.gpw = getgrgid(d.st.st_gid), d.dir = opendir((fa == 0) ? "." : a[1]);
    while ((d.sd = readdir(d.dir)) != NULL) if (d.sd->d_name[0] != '.') i++;
    f = malloc(sizeof(char *) * i), closedir(d.dir);
    d.dir = opendir((fa == 0) ? "." : a[1]);
    total = get_stats(d, f, i, total);
    if (a[0][0] != 'l') normal_form(a, f, i);
    else listing_form(a, f, i, total);
    for (int k = 0; k != i; k++) free(f[k]);
    free(f);
    for (int k = 0; k != ac - 1; k++) free(a[k]);
    free(a);
    return (0);
}