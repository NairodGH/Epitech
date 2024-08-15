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

    for (int i = 0; str[i + 1] != 0; i++) {
        if (str[i] == '-' && 48 < str[i + 1] && str[i + 1] < 58) {
            neg = -1;
            break;
        }
    }
    for (int i = 0; str[i] != 0; i++) {
        if ((48 > str[i] || str[i] > 57) && nb != 0)
            break;
        if (47 < str[i] && str[i] < 58) {
            nb *= 10;
            nb += str[i] - 48;
        }
    }
    return (nb * neg);
}