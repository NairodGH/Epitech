/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** Function displaying chars of a string
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    while ( str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
