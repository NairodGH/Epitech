/*
** EPITECH PROJECT, 2021
** is_in_square.c
** File description:
** Check if a point "pos" is in a rectangle defined by "from" & "to"
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

bool is_in_square(sfVector2f from, sfVector2f to, sfVector2f pos)
{
    if (pos.x < from.x || pos.y < from.y)
        return (false);
    return pos.x <= to.x && pos.y <= to.y;
}