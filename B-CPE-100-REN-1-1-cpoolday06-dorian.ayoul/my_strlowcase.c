/*
** EPITECH PROJECT, 2020
** my_strlowcase
** File description:
** Puts every letter of a string in lower case
*/

char *my_strlowcase (char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ('A' <= str[i] && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    return (str);
}