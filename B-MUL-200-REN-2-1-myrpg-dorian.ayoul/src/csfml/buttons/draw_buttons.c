/*
** EPITECH PROJECT, 2021
** draw_buttons.c
** File description:
** Draw game buttons
*/

#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <nep/nmem.h>
#include <nep/nctype.h>
#include <nep/nlist.h>

void draw_buttons(engine_t *engine, list_t *list)
{
    button_t *btn;

    if (list == NULL)
        return;
    list_foreach(list, node) {
        btn = (button_t *) node->value;
        draw_button(engine, btn);
    }
}