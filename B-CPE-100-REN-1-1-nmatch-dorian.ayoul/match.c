/*
** EPITECH PROJECT, 2020
** match.c
** File description:
** Find out if two strings match (asterisks can replace chars)
*/

#include <stdlib.h>

int star(char const *s1, char const *s2, int i, int j)
{
    while (s1[i] != '\0') {
        if (s1[i] == s2[j + 1])
            return (i);
        if (s2[j + 1] == '*') {
            j++;
            star(s1, s2, i, j);
        }
        i++;
    }
    return (0);
}

int match(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    while ((s1[i] != '\0') || (s2[j] != '\0')) {
        if (s1[i] == s2[j]) {
            j++;
            i++;
        }
        else if (s2[j] == '*') {
            i = star(s1, s2, i, j);
            j++;
            if (s2[j] == '\0')
                return (1);
        }
        else
            return (0);
    }
    return (1);
}