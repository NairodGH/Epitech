/*
** EPITECH PROJECT, 2020
** my_compute_factorial_it
** File description:
** Returns factorial number given as parameter
*/

int my_compute_factorial_it(int nb);

int my_compute_factorial_it(int nb)
{
    int i = nb;

    if (nb > 12 || nb < 0) {
        return (0);
    }
    if ( nb == 0 || nb == 1 ) {
        return (1);
    }
    while ( i > 1 ) {
        nb = (i-1) * nb;
        i--;
    }
    return (nb);
}