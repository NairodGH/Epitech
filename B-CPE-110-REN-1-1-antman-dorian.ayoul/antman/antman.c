/*
** EPITECH PROJECT, 2020
** antman.c
** File description:
** bop
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

void ppm(struct stat st, unsigned char *r)
{
    int h = my_strlen(r) / 2;
    int i = 0;
    int j = 0;
    unsigned char *s;
    s = malloc(sizeof(unsigned char) *st.st_size);
    while (r[i] != '\0') {
        i % 2 == 0 ? r[i] <<= 4 :
        (r[i] <<= 4, r[i] >>= 4, r[i] |= r[i - 1], s[j++] = r[i]);
        i++;
    }
    write(1, s, h), free(r), free(s);
}

int main(int ac, char **av)
{
    struct stat st;
    int ret = stat(av[1], &st);
    int fd = open(av[1], O_RDONLY);
    unsigned char *b;
    int err;
    unsigned char *str;

    if (ret == -1 || fd == -1) return (84);
    if (!(b = malloc(sizeof(unsigned char) * st.st_size))) return (84);
    if (!(str = malloc(sizeof(unsigned char) * st.st_size))) return (84);
    if (ac != 3) return (84);
    err = read(fd, b, st.st_size);
    if (err == -1) return (84);
    if (err == 0) return (0);
    if (av[2][0] == '3' && av[2][1] == '\0') {
        str = ppm1(b, 0, str), ppm(st, str);
        return (0); }
    if (av[2][0] == '2' && av[2][1] == '\0') html(b, str);
    close(fd), free(b), free(str);
    return (0);
}