/*
** EPITECH PROJECT, 2021
** update_text.c
** File description:
** Update text information
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>

void update_text(txt_t *txt)
{
    if (txt == NULL || txt->text == NULL)
        return;
    sfText_setFont(txt->text, txt->font);
    sfText_setPosition(txt->text, txt->pos);
    sfText_setColor(txt->text, txt->color);
    sfText_setString(txt->text, txt->content);
    sfText_setCharacterSize(txt->text, txt->size);
}