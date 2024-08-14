/*
** EPITECH PROJECT, 2020
** my_compute_factorial_rec
** File description:
** Return factorial of number given as parameter
*/

int my_compute_factorial_rec(int nb);

int my_compute_factorial_rec(int nb)
{
    int i = nb;

    if (nb == 0 || nb == 1) {
        return (1);
    }
    if (nb < 0 ) {
        return (0);
    }
    if (nb > 12) {
        return (0);
    }
    return (nb * my_compute_factorial_rec(i - 1));
}