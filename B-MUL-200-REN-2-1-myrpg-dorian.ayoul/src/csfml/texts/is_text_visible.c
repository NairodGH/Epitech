/*
** EPITECH PROJECT, 2021
** is_text_visible.c
** File description:
** Is text visible
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>

bool is_text_visible(txt_t *txt)
{
    if (txt == NULL)
        return (false);
    return (txt->visibility);
}