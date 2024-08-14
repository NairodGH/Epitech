/*
** EPITECH PROJECT, 2020
** check b
** File description:
** norme
*/

#include <unistd.h>
#include "include/my.h"

int my_display(char *buff, int z);

int my_count(char *buff)
{
    int i = 0;

    while (buff[i] != '\n')
        i++;
    i--;
    return (i);
}

int my_count_large(char *buff, int z)
{
    int i = 0;
    int a = 0;

    while (buff[i] != '\0') {
        if (buff[i] == '\n')
            a++;
        i++;
    }
    i--;
    i = i - a;
    i = i / z;
    my_put_nbr(i);
    return (0);
}

int my_check_error(char *buff)
{
    int i = 0;
    int a = 0;
    int b = 0;

    i = my_count(buff);
    if (i <= 0)
        return (84);
    while (buff[b] != '\0') {
        if (buff[b] == '\n')
            a++;
        b++;
    }
    b--;
    b = b - a;
    b = b / i;
    if (b <= 0)
        return (84);
    return (0);
}

int my_display(char *buff, int z)
{
    my_putchar(' ');
    z = my_count(buff);
    my_put_nbr(z);
    my_putchar(' ');
    my_count_large(buff, z);
    return (0);
}
