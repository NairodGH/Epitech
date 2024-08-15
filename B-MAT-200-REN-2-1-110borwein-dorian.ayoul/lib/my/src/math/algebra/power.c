/*
** EPITECH PROJECT, 2021
** power.c
** File description:
** gets the power of a number
*/

int power(int nb, int pow)
{
    if (pow == 0)
        return (1);
    if (pow < 0)
        return (0);
    if (pow != 1)
        return (nb * power(nb, pow - 1));
}