/*
** EPITECH PROJECT, 2021
** str_endswith.c
** File description:
** if string ends with
*/

#include <nep/nstring.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

bool str_endswith(char *str, char *check)
{
    int len_str;
    int len_check;
    int jtr = 0;

    if (str == NULL || check == NULL)
        return (false);
    len_str = nstrlen(str);
    len_check = nstrlen(check);
    if (len_str < len_check)
        return (false);
    for (unsigned int itr = len_str - len_check; str[itr]; ++itr) {
        if (check[jtr] != str[itr])
            return (false);
        ++jtr;
    }
    return (true);
}

bool str_endswith_off(char *str, int index, char *check)
{
    int len_str;
    int len_check;
    int jtr = 0;
    int start;

    if (str == NULL || check == NULL)
        return (false);
    len_str = nstrlen(str);
    len_check = nstrlen(check);
    if (len_str < len_check)
        return (false);
    start = index - len_check;
    if (start == index - 1)
        return (check[0] == str[start]);
    for (int i = start + 1; i <= index && str[i]; ++i) {
        if (check[jtr] != str[i])
            return (false);
        ++jtr;
    }
    return (true);
}