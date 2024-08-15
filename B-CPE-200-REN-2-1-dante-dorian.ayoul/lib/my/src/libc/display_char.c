/*
** EPITECH PROJECT, 2020
** display_char.c
** File description:
** display a character
*/

#include "../../lib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}