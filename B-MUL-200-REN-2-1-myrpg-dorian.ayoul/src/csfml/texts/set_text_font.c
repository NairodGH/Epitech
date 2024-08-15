/*
** EPITECH PROJECT, 2021
** set_text_font.c
** File description:
** Set text font
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>

void set_text_font(txt_t *txt, sfFont *font)
{
    if (txt == NULL || font == NULL)
        return;
    txt->font = font;
    sfText_setFont(txt->text, txt->font);
}