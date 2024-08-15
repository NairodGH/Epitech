/*
** EPITECH PROJECT, 2021
** get_text_color.c
** File description:
** Get text color
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>

sfColor get_text_color(txt_t *txt)
{
    if (txt == NULL)
        return (sfWhite);
    return (txt->color);
}