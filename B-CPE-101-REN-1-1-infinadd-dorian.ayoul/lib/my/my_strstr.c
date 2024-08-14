/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** Searches for a string inside another
*/

#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[j])
            j++;
        else
            j = 0;
        if (to_find[j] == '\0' && j > 0)
            return (&str[i - j + 1]);
    }
    if (to_find[0] == '\0')
        return (str);
    else
        return (NULL);
}