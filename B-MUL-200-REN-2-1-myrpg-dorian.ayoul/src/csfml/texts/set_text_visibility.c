/*
** EPITECH PROJECT, 2021
** set_text_visibility.c
** File description:
** Set text visibility
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>

void set_text_visibility(txt_t *txt, bool visibility)
{
    if (txt == NULL)
        return;
    txt->visibility = visibility;
}