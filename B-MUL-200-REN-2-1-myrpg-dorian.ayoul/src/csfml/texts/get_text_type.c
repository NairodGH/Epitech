/*
** EPITECH PROJECT, 2021
** get_text_type.c
** File description:
** Get text type
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>

int get_text_type(txt_t *txt)
{
    if (txt == NULL)
        return (-1);
    return (txt->type);
}