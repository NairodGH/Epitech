/*
** EPITECH PROJECT, 2022
** server.c
** File description:
** server
*/

#include "server.h"

static long long len(long long nb)
{
    long long len;

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

char *my_ltoa(size_t nb)
{
    char *str;
    long long n = nb;
    long long i = len(n);

    if (!(str = malloc(sizeof(char) * (i + 1))))
        return (NULL);
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
