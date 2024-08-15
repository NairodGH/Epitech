/*
** EPITECH PROJECT, 2021
** my_arrcount.c
** File description:
** Array count
*/

#include <stdlib.h>

int my_arrcount(char **tab)
{
    unsigned int itr = 0;

    if (tab == NULL)
        return (0);
    for (; tab[itr]; ++itr);
    return (itr);
}