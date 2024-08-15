/*
** EPITECH PROJECT, 2021
** get_panel_by_id.c
** File description:
** Get panel by id
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>

panel_t *get_panel_by_id(engine_t *engine, int id)
{
    panel_t *panel;

    if (engine == NULL || engine->panels == NULL)
        return (NULL);
    list_foreach(engine->panels, node) {
        panel = (panel_t *) node->value;
        if (panel == NULL)
            continue;
        if (panel->id != id)
            continue;
        return (panel);
    }
    return (NULL);
}