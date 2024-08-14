/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** my put nbr
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int dec;
    int comm;

    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
    }
    else {
        comm = nb % 10;
        dec = nb / 10;
    if (dec != 0)
        my_put_nbr(dec);
        my_putchar(comm + '0');
    }
}