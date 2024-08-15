/*
** EPITECH PROJECT, 2021
** get_text_size.c
** File description:
** Get text size
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>

int get_text_size(txt_t *txt)
{
    if (txt == NULL)
        return (0);
    return (txt->size);
}