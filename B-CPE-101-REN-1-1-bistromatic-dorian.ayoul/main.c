/*
** EPITECH PROJECT, 2020
** Bistromatic main
** File description:
** Err gestion and exec
*/

#include "my.h"
#include "bistromatic.h"
#include "ops.h"

int main(int ac, char **av)
{
    char *buff = NULL;
    int size = 0;

    err_gestion(ac, av);
    size = my_getnbr(av[3]);
    buff = malloc(sizeof(char) * (size + 1));
    read(0, buff, size);
    if (my_strlen(buff) < 3) {
        my_putchar(buff[0]);
        my_putchar('\n');
        return (0);
    }
    calc(trad(buff));
    free(buff);
    return (0);
}