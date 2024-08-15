/*
** EPITECH PROJECT, 2020
** annoying.c
** File description:
** lib functions :)
*/

#include <unistd.h>
#include <stdio.h>

void my_putstr(char *str)
{
    for (int i = 0; str[i] != 0; i++) write(1, &str[i], 1);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != 0) i++;
    return (i);
}

void my_putnbr(int nb)
{
    if (nb < 0) my_putchar('-'), nb = -nb;
    if (nb > 9) my_putnbr(nb / 10), my_putchar((nb % 10) + 48);
    else my_putchar((nb % 10) + 48);
}

int my_getnbr(char *str)
{
    int neg = 1;
    int nb = 0;

    for (int i = 0; str[i + 1] != 0; i++) {
        if (str[i] == '-' && 48 < str[i + 1] && str[i + 1] < 58) {
            neg = -1;
            break;
        }
    }
    for (int i = 0; str[i] != 0; i++) {
        if ((48 > str[i] || str[i] > 57) && nb != 0)
            break;
        if (47 < str[i] && str[i] < 58) {
            nb *= 10, nb += str[i] - 48;
        }
    }
    return (nb * neg);
}
