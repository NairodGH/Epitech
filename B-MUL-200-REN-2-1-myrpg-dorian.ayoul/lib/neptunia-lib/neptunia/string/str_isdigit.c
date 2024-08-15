/*
** EPITECH PROJECT, 2020
** LibC
** File description:
** string - nstr_isdigit.
*/

#include <nep/nctype.h>

bool nstr_isdigit(char *str)
{
    if (str == NULL)
        return (false);
    while (*str) {
        if (!nisdigit(*str++))
            return (false);
    }
    return (true);
}