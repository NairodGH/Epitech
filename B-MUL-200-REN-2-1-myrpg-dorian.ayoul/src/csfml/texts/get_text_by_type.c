/*
** EPITECH PROJECT, 2021
** get_text_by_type.c
** File description:
** Get first text by type
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>
#include <texts.h>

txt_t *get_text_by_type(panel_t *panel, int type)
{
    txt_t *txt;

    if (panel == NULL || panel->texts == NULL)
        return (NULL);
    list_foreach(panel->texts, node) {
        txt = (txt_t *) node->value;
        if (txt->type == type)
            return (txt);
    }
    return (NULL);
}