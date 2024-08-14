/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** Returns smallest prime number greater than/equal to number given
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int i = 0;

    while (my_is_prime(nb + i) != 1)
        i++;
    return (nb + i);
}