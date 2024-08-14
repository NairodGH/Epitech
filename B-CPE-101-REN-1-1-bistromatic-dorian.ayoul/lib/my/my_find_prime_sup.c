/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** Task 07 Day 05
*/

#include <unistd.h>
#include "my.h"

int my_find_prime_sup(int nb)
{
    int i = nb;

    while (i >= nb) {
        if (my_is_prime(i))
            return (i);
        i++;
    }
    return (nb);
}
