/*
** EPITECH PROJECT, 2020
** flag_functions.c
** File description:
** useful flags-related functions for my_ls
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

int permissions(data_struct d, char *f, int k)
{
    d.st.st_mode & S_IFDIR ? f[k++] = 'd' : (f[k++] = '-');
    d.st.st_mode & S_IRUSR ? f[k++] = 'r' : (f[k++] = '-');
    d.st.st_mode & S_IWUSR ? f[k++] = 'w' : (f[k++] = '-');
    d.st.st_mode & S_IXUSR ? f[k++] = 'x' : (f[k++] = '-');
    d.st.st_mode & S_IRGRP ? f[k++] = 'r' : (f[k++] = '-');
    d.st.st_mode & S_IWGRP ? f[k++] = 'w' : (f[k++] = '-');
    d.st.st_mode & S_IXGRP ? f[k++] = 'x' : (f[k++] = '-');
    d.st.st_mode & S_IROTH ? f[k++] = 'r' : (f[k++] = '-');
    d.st.st_mode & S_IWOTH ? f[k++] = 'w' : (f[k++] = '-');
    d.st.st_mode & S_IXOTH ? f[k++] = 'x' : (f[k++] = '-');
    f[k++] = '.';
    f[k++] = ' ';
    k = put_in_str(f, k, "\0", d.st.st_nlink);
    f[k++] = ' ';
    return (k);
}

int get_stats(data_struct d, char **f, int i, int total)
{
    int j = 0;

    for (int k = 0; (d.sd = readdir(d.dir)) != NULL && i != 0; k = 0) {
        if (d.sd->d_name[0] != '.') {
            lstat(d.sd->d_name, &d.st), total += d.st.st_blocks;
            f[j] = malloc(29 + my_len("\0", d.st.st_nlink) +
            my_len(d.upw->pw_name, 0) + my_len(d.gpw->gr_name, 0) +
            my_len("\0", d.st.st_size) + my_len(d.sd->d_name, 0));
            k = permissions(d, f[j], k);
            k = put_in_str(f[j], k, d.upw->pw_name, 0), f[j][k++] = ' ';
            k = put_in_str(f[j], k, d.gpw->gr_name, 0), f[j][k++] = ' ';
            k = put_in_str(f[j], k, "\0", d.st.st_size);
            k = put_in_str(f[j], k, putstr(ctime(&d.st.st_mtime), 0, 't'), 0);
            k = put_in_str(f[j], k, d.sd->d_name, 0);
            j++, i--;
        }
    }
    return (total);
}

int getdate(int d[2][2], char **f, int i, char mode)
{
    bool swap = 0;

    for (int j = 0; j + 1 != i; j++) {
        d[0][0] = 0, d[0][1] = 0, d[1][0] = 0, d[1][1] = 0;
        for (int k = 0; k != (mode == 'd' ? 6 : 7); d[0][0]++)
            (f[j][d[0][0]] == ' ') && (k++);
        for (int k = 0; k != (mode == 'd' ? 6 : 7); d[1][0]++)
            (f[j + 1][d[1][0]] == ' ') && (k++);
        (mode == 'm') && (d[0][0] += 3, d[1][0] += 3);
        d[0][1] += f[j][d[0][0]] - 48, (f[j][d[0][0] + 1] != ' ') &&
        (d[0][1] *= 10, d[0][1] += f[j][d[0][0] + 1] - 48);
        d[1][1] += f[j + 1][d[1][0]] - 48,
        (f[j + 1][d[1][0] + 1] != ' ') &&
        (d[1][1] *= 10, d[1][1] += f[j + 1][d[1][0] + 1] - 48);
        (d[0][1] < d[1][1]) && (swapstr(&f[j], &f[j + 1]), swap = 1);
    }
    return (swap);
}

void getmonth(int d[2][2], char **f, int j)
{
    d[0][0] = 0, d[0][1] = 0, d[1][0] = 0, d[1][1] = 0;
    for (int k = 0; k != 5; d[0][0]++) (f[j][d[0][0]] == ' ') && (k++);
    for (int k = 0; k != 5; d[1][0]++) (f[j + 1][d[1][0]] == ' ') && (k++);
    d[0][1] = f[j][d[0][0]] == 'J' && f[j][d[0][0] + 1] == 'A' ? 1 :
    f[j][d[0][0]] == 'F' ? 2 : f[j][d[0][0]] == 'M' &&
    f[j][d[0][0] + 2] == 'R' ? 3 : f[j][d[0][0] + 1] == 'P' ? 4 :
    f[j][d[0][0] + 2] == 'Y' ? 5 : f[j][d[0][0]] == 'J' &&
    f[j][d[0][0] + 2] == 'N' ? 6 : f[j][d[0][0] + 2] == 'L' ? 7 :
    f[j][d[0][0] + 2] == 'G' ? 8 : f[j][d[0][0]] == 'S' ? 9 :
    f[j][d[0][0]] == 'O' ? 10 : f[j][d[0][0]] == 'N' ? 11 : 12;
    d[1][1] = f[j + 1][d[1][0]] == 'J' && f[j + 1][d[1][0] + 1] == 'A' ?
    1 : f[j + 1][d[1][0]] == 'F' ? 2 : f[j + 1][d[1][0]] == 'M' &&
    f[j + 1][d[1][0] + 2] == 'R' ? 3 : f[j + 1][d[1][0] + 1] == 'P' ? 4
    : f[j + 1][d[1][0] + 2] == 'Y' ? 5 : f[j + 1][d[1][0]] == 'J' &&
    f[j + 1][d[1][0] + 2] == 'N' ? 6 : f[j + 1][d[1][0] + 2] == 'L' ? 7
    : f[j + 1][d[1][0] + 2] == 'G' ? 8 : f[j + 1][d[1][0]] == 'S' ? 9 :
    f[j + 1][d[1][0]] == 'O' ? 10 : f[j + 1][d[1][0]] == 'N' ? 11 : 12;
}

void time_sorter(char **f, int i)
{
    bool swap = 1;

    for (int k = 0; k != 3; k++) {
        for (int d[2][2], swap = 1; swap != 0;)
            swap = getdate(d, f, i, (k == 0 ? 'm' : k == 1 ? 'h' : 'd'));
    }
    for (int d[2][2], swap = 1; swap != 0;) {
        swap = 0;
        for (int j = 0; j + 1 != i; j++) {getmonth(d, f, j);
            if (d[0][1] < d[1][1]) swapstr(&f[j], &f[j + 1]), swap = 1;
        }
    }
}