/*
** EPITECH PROJECT, 2021
** register_tooltip.c
** File description:
** Register tooltip
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>
#include <objects.h>
#include <buttons.h>
#include <stdlib.h>
#include <texts.h>

void register_tooltip(panel_t *panel, tooltip_t *tooltip)
{
    if (panel == NULL || tooltip == NULL)
        return;
    if (panel->tooltips == NULL)
        panel->tooltips = list_create();
    list_add(panel->tooltips, tooltip);
}