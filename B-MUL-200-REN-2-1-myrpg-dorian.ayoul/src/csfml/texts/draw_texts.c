/*
** EPITECH PROJECT, 2021
** draw_texts.c
** File description:
** Draw texts
*/

#include <panel.h>
#include <texts.h>
#include <nep/nmem.h>
#include <nep/nctype.h>
#include <nep/nlist.h>

void draw_texts(engine_t *engine, list_t *list)
{
    txt_t *txt;

    if (engine == NULL || list == NULL)
        return;
    list_foreach(list, node) {
        txt = (txt_t *) node->value;
        draw_text(engine, txt);
    }
}