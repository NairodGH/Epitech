/*
** EPITECH PROJECT, 2021
** register_panel.c
** File description:
** Register panel
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <nep/nlist.h>
#include <engine.h>
#include <panel.h>

void register_panel(engine_t *engine, panel_t *panel)
{
    if (engine == NULL || panel == NULL)
        return;
    if (engine->panels == NULL)
        engine->panels = list_create();
    list_add(engine->panels, panel);
}