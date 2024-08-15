/*
** EPITECH PROJECT, 2021
** handle_object_click.c
** File description:
** Handle object click
*/

#include <nep/nmem.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>

PRIVATE void handle_object_click(ENGPANEL, obj_t *obj)
{
    sfInt64 it;

    if (obj == NULL || obj->on_click == NULL || !obj->visibility)
        return;
    it = sfClock_getElapsedTime(engine->lastclick).microseconds / 1000;
    if (it < 500)
        return;
    play_seffect(engine->game, engine, "assets/sounds/b-click.ogg");
    obj->on_click(engine, game, panel, obj);
    sfClock_restart(engine->lastclick);
}

PRIVATE bool handle_panel_objects(ENGPANEL, sfVector2i mouse)
{
    obj_t *obj;

    if (!is_panel_visible(panel) || panel->objects == NULL)
        return (false);
    list_foreach(panel->objects, obj_node) {
        obj = (obj_t *) obj_node->value;
        if (!is_obj_clicked(obj, mouse))
            continue;
        handle_object_click(engine, game, panel, obj);
        return (true);
    }
    return (false);
}

void handle_objects_click(engine_t *engine, game_t *game, sfVector2i mouse)
{
    panel_t *panel;
    bool clicked = false;

    if (engine == NULL || engine->panels == NULL)
        return;
    list_foreach(engine->panels, node) {
        panel = (panel_t *) node->value;
        if (!is_panel_visible(panel))
            continue;
        clicked = handle_panel_objects(engine, game, panel, mouse);
        if (clicked)
            return;
    }
}