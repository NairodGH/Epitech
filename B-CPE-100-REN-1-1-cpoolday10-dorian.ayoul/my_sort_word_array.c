/*
** EPITECH PROJECT, 2020
** my_sort_word_array
** File description:
** Sorts words received in ascii order
*/

#include "my.h"

static void swap_p(char **tab, int i)
{
    char *tmp = my_strdup(tab[i]);
    tab[i] = tab[i + 1];
    tab[i + 1] = tmp;
}

int my_sort_word_array(char **tab)
{
    int stock = 0;

    for (int i = 0; tab[i + 1] != 0; i++) {
        stock = my_strcmp(tab[i], tab[i + 1]);
        if (stock > 0) {
            swap_p(tab, i);
            i = 0;
        }
    }
    return (0);
}