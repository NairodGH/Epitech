/*
** EPITECH PROJECT, 2021
** get_text_pos.c
** File description:
** Get text position
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>

sfVector2f get_text_pos(txt_t *txt)
{
    if (txt == NULL)
        return ((sfVector2f) {0, 0});
    return (txt->pos);
}