/*
** EPITECH PROJECT, 2021
** is_text_clicked.c
** File description:
** Is game text clicked?
*/

#include <texts.h>
#include <cmath.h>

bool is_text_clicked(txt_t *txt, sfVector2i ev)
{
    sfVector2f from;
    sfVector2f to;

    if (txt == NULL || !txt->text)
        return (false);
    from = txt->pos;
    to = get_text_endpos(txt);
    return is_in_square(from, to, (sfVector2f){ev.x, ev.y});
}