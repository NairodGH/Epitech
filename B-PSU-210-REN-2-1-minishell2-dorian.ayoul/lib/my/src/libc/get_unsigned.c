/*
** EPITECH PROJECT, 2020
** get_unsigned.c
** File description:
** Get unsigned number from string
*/

int get_unsigned(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != 0; i++) {
        if ('0' < str[i] && str[i] < '9') {
            nb *= 10;
            nb += str[i] - 48;
        }
        else
            return (-1);
    }
    return (nb);
}