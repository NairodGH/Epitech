/*
** EPITECH PROJECT, 2020
** get_int.c
** File description:
** Get int from string
*/

int get_int(char *str)
{
    int neg = 1;
    int nb = 0;

    if (str[0] == '-')
        neg = -1;
    for (int i = 0; str[i] != 0; i++) {
        if ((str[i] < '0' || str[i] > '9') && nb != 0)
            break;
        if ('0' < str[i] && str[i] < '9') {
            nb *= 10;
            nb += str[i] - 48;
        }
    }
    return (nb * neg);
}