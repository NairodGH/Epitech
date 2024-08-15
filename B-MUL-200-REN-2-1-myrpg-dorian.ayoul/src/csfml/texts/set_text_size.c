/*
** EPITECH PROJECT, 2021
** set_text_size.c
** File description:
** Set text size
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>

void set_text_size(txt_t *txt, int size)
{
    if (txt == NULL)
        return;
    txt->size = size;
    sfText_setCharacterSize(txt->text, txt->size);
}