/*
** EPITECH PROJECT, 2021
** checking.c
** File description:
** check function for error handling of MAT 109titration project
*/

#include "../lib/my/lib.h"

size_t file_syntax(char *buf, double *vol, double *ph)
{
    for (size_t i = 0, dot = 0, semi = 0; buf[i] != '\0'; i++) {
        if ((buf[i] < '0' || buf[i] > '9') && buf[i] != '.'
            && buf[i] != ';' && buf[i] != '\n')
            return (84);
        if ((i == 0 || buf[i - 1] == '\n') && (buf[i] == ';' || buf[i] == '.'))
            return (84);
        if (buf[i] == '.')
            dot++;
        if (buf[i] == ';')
            semi++;
        if (buf[i] == ';' && dot > 1)
            return (84);
        if (buf[i] == '\n' && semi != 1)
            return (84);
        if (buf[i] == '\n') {
            semi = 0;
            dot = 0;
        }
    }
    return (0);
}

size_t get_file_values(char *buf, double *vol, double *ph)
{
    for (size_t i = 0, j = 0, dot = 0, semi = 0; buf[i] != '\0'; i++) {
        if (buf[i] == '.')
            dot++;
        if (buf[i] == ';') {
            semi++;
            dot = 0;
        }
        if (buf[i] >= '0' && buf[i] <= '9' && !dot) {
            semi ? ph[j] *= 10 : (vol[j] *= 10);
            semi ? ph[j] += (buf[i] - 48) : (vol[j] += buf[i] - 48);
        }
        if (buf[i] >= '0' && buf[i] <= '9' && dot)
            semi ? ph[j] += (buf[i] - 48) / (buf[i - 1] == '.' ? 10 : 100.0f) :
            (vol[j] += (buf[i] - 48) / (buf[i - 1] == '.' ? 10 : 100.0f));
        if (buf[i] == '\n') {
            j++;
            dot = 0;
            semi = 0;
        }
    }
}