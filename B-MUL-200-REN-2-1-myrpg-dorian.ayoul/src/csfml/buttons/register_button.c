/*
** EPITECH PROJECT, 2021
** register_button.c
** File description:
** Register a button
*/

#include <panel.h>
#include <objects.h>
#include <buttons.h>
#include <nep/nmem.h>
#include <nep/nctype.h>
#include <nep/nlist.h>

void register_button(panel_t *panel, button_t *btn)
{
    if (panel == NULL || btn == NULL)
        return;
    if (panel->buttons == NULL)
        panel->buttons = list_create();
    list_add(panel->buttons, btn);
}