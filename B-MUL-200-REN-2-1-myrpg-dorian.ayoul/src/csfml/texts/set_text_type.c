/*
** EPITECH PROJECT, 2021
** set_text_type.c
** File description:
** Set text type
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>

void set_text_type(txt_t *txt, int type)
{
    if (txt == NULL)
        return;
    txt->type = type;
}