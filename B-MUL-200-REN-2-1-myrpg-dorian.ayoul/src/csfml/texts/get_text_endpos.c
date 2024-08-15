/*
** EPITECH PROJECT, 2021
** get_text_endpos.c
** File description:
** Get text end position
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>

sfVector2f get_text_endpos(txt_t *txt)
{
    sfFloatRect rect;
    sfVector2f pos = {0, 0};

    if (txt == NULL || txt->text == NULL)
        return (pos);
    pos = txt->pos;
    rect = sfText_getGlobalBounds(txt->text);
    pos.x += rect.width;
    pos.y += rect.height;
    return (pos);
}