/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** Puts a given char
*/

#include "my.h"

void my_put_nbr(int nb)
{
    int dec;
    int comm;

    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
    }
    else {
        comm = nb % 10;
        dec = nb / 10;
    if (dec != 0)
        my_put_nbr(dec);
        my_putchar(comm + '0');
    }
}
