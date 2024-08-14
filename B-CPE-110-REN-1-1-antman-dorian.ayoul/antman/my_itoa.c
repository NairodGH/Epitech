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

int my_strlen(char const *str)
{
    int c;

    c = 0;
    while (str[c] != '\0')
        c++;
    return (c);
}

int	len(long nb)
{
    int	len;

    len = 0;
    if (nb < 0) {
        nb = nb * -1;
        len++;
    }
    while (nb > 0) {
        nb = nb / 10;
        len++;
    }
    return (len);
}

char *my_itoa(int nb)
{
    char *str;
    long n = nb;
    int	i = len(n);

    if (!(str = malloc(sizeof(char) * (i + 1))))
        return (0);
    str[i--] = '\0';
    if (n == 0) {
        str[0] = 48;
        return (str);
    }
    if (n < 0) {
        str[0] = '-';
        n = n * -1;
    }
    while (n > 0) {
        str[i] = 48 + (n % 10);
        n = n / 10, i--;
    }
    return (str);
}