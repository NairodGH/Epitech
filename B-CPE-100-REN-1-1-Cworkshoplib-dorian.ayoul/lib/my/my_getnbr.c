/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** Returns a number sent as a string (tricky cases are to be handled)
*/

#include <stddef.h>

int my_getnbr(char *str)
{
    int i;
    int nbr = 0;
    int negative = 1;

    for (i = 0; (str[i] == '+' || str[i] == '-') && str[i] != '\0'; i++) {
        if (str[i] == '-')
            negative *= -1;
    }
    for (; '0' <= str[i] && str[i] <= '9'; i++) {
        nbr *= 10;
        nbr += (str[i] - 48);
        if (nbr < 0 && (negative == 1 || nbr != -2147483648))
            return (0);
    }
    return (nbr * negative);
}