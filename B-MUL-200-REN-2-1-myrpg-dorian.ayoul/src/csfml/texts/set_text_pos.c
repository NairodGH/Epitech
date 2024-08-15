/*
** EPITECH PROJECT, 2021
** set_text_pos.c
** File description:
** Set text position
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>

void set_text_pos(txt_t *txt, sfVector2f pos)
{
    if (txt == NULL)
        return;
    txt->pos = pos;
    sfText_setPosition(txt->text, txt->pos);
}