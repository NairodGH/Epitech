/*
** EPITECH PROJECT, 2021
** stumper
** File description:
** putstr
*/

#include "my.h"
#include <unistd.h>

void my_putstr(char *s)
{
    write(0, s, my_strlen(s));
}

void my_puterr(char *s)
{
    write(2, s, my_strlen(s));
}
