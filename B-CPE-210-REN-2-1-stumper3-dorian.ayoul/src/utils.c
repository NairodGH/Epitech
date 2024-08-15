/*
** EPITECH PROJECT, 2020
** annoying.c
** File description:
** lib functions :)
*/

#include "my.h"

int get_map_length(char *str)
{
    int length = 0;

    while (str[length] != '\n')
        length++;
    return (length);
}

int get_map_height(char *str)
{
    int height = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            height++;
    return (height);
}

int my_strlen(char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    return (len);
}

int my_getnbr(char *str)
{
    int neg = 1;
    int nbr = 0;

    for (int i = 0; str[i + 1] != 0; i++) {
        if (str[i] == '-' && 48 < str[i + 1] && str[i + 1] < 58) {
            neg = -1;
            break;
        }
    }
    for (int i = 0; str[i] != 0; i++) {
        if ((48 > str[i] || str[i] > 57) && nbr != 0)
            break;
        if (47 < str[i] && str[i] < 58) {
            nbr *= 10;
            nbr += str[i] - 48;
        }
    }
    return (nbr * neg);
}
