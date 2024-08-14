/*
** EPITECH PROJECT, 2020
** annoying.c
** File description:
** y ofc the guy would run the program without arg even tho he's told not to..
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "include/my_runner.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void putnbr(int nb)
{
    if (nb > 9) putnbr(nb / 10), my_putchar((nb % 10) + 48);
    else my_putchar((nb % 10) + 48);
}

int error(int ac, char **av)
{
    int fd;
    char b[4096];
    int ret;

    if (ac != 2) {
        write(2, "./my_runner: bad arguments: ", 28), putnbr(ac - 1);
        write(2, " given but 1 is required\nretry with -h\n", 39);
        return (84);
    }
    if ((fd = open(av[1], O_RDONLY)) == -1) {
        write(2, "file given can't be opened\n", 27), close(fd);
        return (84);
    }
    if ((ret = read(fd, b, 4096)) == -1) {
        write(2, "file given can't be read\n", 25), close(fd);
        return (84);
    }
    return (0);
}