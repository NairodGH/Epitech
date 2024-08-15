/*
** EPITECH PROJECT, 2021
** get_text_font.c
** File description:
** Get text font
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>

sfFont *get_text_font(txt_t *txt)
{
    if (txt == NULL)
        return (NULL);
    return (txt->font);
}