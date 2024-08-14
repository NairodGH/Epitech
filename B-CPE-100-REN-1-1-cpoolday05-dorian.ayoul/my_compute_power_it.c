/*
** EPITECH PROJECT, 2020
** my_compute_power_it
** File description:
** Return 1rst argument raised to power p
*/

int my_compute_power_it(int nb, int p);

int my_compute_power_it(int nb, int p)
{
    int i = nb;

    if (p == 0) {
        return (1);
    }
    if ( p < 0 ) {
        return (0);
    }
    while (p != 1) {
        nb = nb * i;
        p--;
    }
    return (nb);
}