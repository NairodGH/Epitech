/*
** EPITECH PROJECT, 2021
** str_is_positive_int.c
** File description:
** check if a string is a valid positive integer
*/

int str_is_positive_int(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57)
            return (0);
    }
    return (1);
}