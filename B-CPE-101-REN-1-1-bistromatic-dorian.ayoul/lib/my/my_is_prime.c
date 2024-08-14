/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** Task 06 Day 05
*/

#include<unistd.h>

int my_is_prime(int nb)
{
    int i = 2;

    if (nb <= 1)
        return (0);
    else if (nb <= 3)
        return (1);

    while (i <= nb / i) {
        if (nb % i == 0)
            return (0);
        i++;
    }
    return (1);
}