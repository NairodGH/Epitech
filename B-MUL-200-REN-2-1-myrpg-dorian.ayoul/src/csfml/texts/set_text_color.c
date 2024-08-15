/*
** EPITECH PROJECT, 2021
** set_text_color.c
** File description:
** Set text color
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>

void set_text_color(txt_t *txt, sfColor color)
{
    if (txt == NULL)
        return;
    txt->color = color;
    sfText_setColor(txt->text, txt->color);
}