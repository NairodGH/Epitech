/*
** EPITECH PROJECT, 2021
** set_panel_initializer.c
** File description:
** Set panel initializer
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>

void set_panel_initializer(panel_t *panel, void (*on_init)(ENGPANEL), \
    void (*on_destroy)(ENGPANEL))
{
    if (panel == NULL)
        return;
    panel->on_init = on_init;
    panel->on_destroy = on_destroy;
}