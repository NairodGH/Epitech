/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** Return whole number square root
*/

int my_compute_square_root(int nb)
{
    int a = 0;
    int i = nb;

    if (nb <= 0) {
        return (0);
    }
    if (nb == 1) {
        return (1);
    }
    while (i != a) {
        a = i;
        i = (nb/a + a) / 2;
    }
    if (a * a == nb) {
        return (a);
    }
    return (0);
}