/*
** EPITECH PROJECT, 2021
** parsing core
** File description:
** parser
*/

#include "42sh.h"

void print_fd(int fd)
{
    char *to_print = bread_fd(fd, READ_SIZE);

    if (to_print)
        printf("%s", to_print);
}
