/*
** EPITECH PROJECT, 2021
** Get itr char
** File description:
** get itr char
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

char get_itc(char *str, int itr)
{
    size_t len;

    if (str == NULL)
        return (' ');
    len = nstrlen(str);
    if ((size_t) itr >= len)
        return (' ');
    return (str[len - 1]);
}