/*
** EPITECH PROJECT, 2020
** giantman.c
** File description:
** bup
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "antman.h"

char *ppm_true(unsigned char *b, struct stat st)
{
    int h = 0;
    unsigned char *s;
    unsigned char t;
    unsigned char *r;

    for (int i = 0; i != 2; h++)
        write(1, &b[h], 1), (b[h] == '\n') && (i++), (b[h + 1] == '#') && (i--);
    s = malloc((st.st_size - h) * 2), h *= 2;
    for (int i = h, j = 0; i != st.st_size * 2; i++, j++, h = 0) {
        if (i % 2 == 0)
            t = b[i / 2], b[i / 2] >>= 4, (b[i / 2] != 10) && (b[i / 2] += 48),
            s[j] = b[i / 2];
        else
            b[i / 2] = t, b[i / 2] <<= 4, b[i / 2] >>= 4,
            (b[i / 2] != 10) && (b[i / 2] += 48), s[j] = b[i / 2];
    }
    return (s);
}

int main(int ac, char **av)
{
    struct stat st;
    int fd;
    unsigned char *b;
    unsigned char *c;
    char *str;

    if (ac != 3 || stat(av[1], &st) == -1 || (fd = open(av[1], O_RDONLY)) == -1
        || !(b = malloc(st.st_size + 1)) || read(fd, b, st.st_size) == -1)
        return (84);
    if (b[0] == 0) return (0);
    b[st.st_size] = 0;
    if (av[2][0] == '2' && av[2][1] == '\0') giant_html(b);
    if (av[2][0] == '3' && av[2][1] == '\0') str = ppm_true(b, st), ppm1(str);
    close(fd), free(b);
    return (0);
}