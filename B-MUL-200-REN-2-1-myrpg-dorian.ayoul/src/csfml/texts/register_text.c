/*
** EPITECH PROJECT, 2021
** register_text.c
** File description:
** Register a text
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>
#include <texts.h>

void register_text(panel_t *panel, txt_t *txt)
{
    if (panel == NULL || txt == NULL)
        return;
    if (panel->texts == NULL)
        panel->texts = list_create();
    list_add(panel->texts, txt);
}