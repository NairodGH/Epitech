/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** Counts number of chars in the string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}