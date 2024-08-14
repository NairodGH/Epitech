/*
** EPITECH PROJECT, 2020
** utils.c
** File description:
** library who
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (++i);
}

int my_atoi(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++)
        nb *= 10, nb += str[i] - 48;
    return (nb);
}