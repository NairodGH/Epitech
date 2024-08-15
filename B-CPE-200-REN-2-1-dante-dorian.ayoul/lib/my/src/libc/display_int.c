/*
** EPITECH PROJECT, 2020
** display_int.c
** File description:
** display an int
*/

#include "../../lib.h"

void display_int(int nb)
{
    if (nb < 0) {
        display_char('-');
        nb = -nb;
    }
    if (nb > 9) {
        display_int(nb / 10);
        display_char((nb % 10) + 48);
    }
    else
        display_char((nb % 10) + 48);
}