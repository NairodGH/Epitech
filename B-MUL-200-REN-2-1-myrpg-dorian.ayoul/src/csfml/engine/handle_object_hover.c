/*
** EPITECH PROJECT, 2021
** create_object.c
** File description:
** Create a game object
*/

#include <nep/nmem.h>
#include <buttons.h>
#include <objects.h>
#include <panel.h>
#include <sounds.h>

PRIVATE void hover_obpan(engine_t *engine, panel_t *panel, sfVector2i mouse)
{
    obj_t *obj;
    sfVector2f pos;

    if (!is_panel_visible(panel) || panel->objects == NULL)
        return;
    list_foreach(panel->objects, btn_node) {
        obj = (obj_t *) btn_node->value;
        if (!obj->tooltip || !is_obj_clicked(obj, mouse))
            continue;
        if (!obj->sprite)
            continue;
        pos = sfSprite_getPosition(obj->sprite);
        display_tooltip(engine, pos, obj->tooltip);
        return;
    }
}

void handle_objects_hover(engine_t *engine)
{
    sfVector2i mouse;
    panel_t *panel;

    if (!engine || !engine->panels)
        return;
    mouse = sfMouse_getPositionRenderWindow(engine->window->window);
    list_foreach(engine->panels, node) {
        panel = (panel_t *) node->value;
        hover_obpan(engine, panel, mouse);
    }
}