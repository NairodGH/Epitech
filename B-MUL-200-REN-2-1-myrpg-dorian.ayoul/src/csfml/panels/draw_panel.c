/*
** EPITECH PROJECT, 2021
** draw_panel.c
** File description:
** Draw a panel
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>
#include <objects.h>
#include <buttons.h>
#include <texts.h>

#include <rpg/rpg.h>

void draw_panel(engine_t *engine, game_t *game, panel_t *panel)
{
    if (engine == NULL || !is_panel_visible(panel))
        return;
    if (panel->on_render_update != NULL) {
        panel->on_render_update(engine, game, panel);
    }
    draw_objects_shaders(engine, panel->objects);
    draw_objects(engine, panel->objects);
    draw_buttons(engine, panel->buttons);
    draw_texts(engine, panel->texts);
    draw_button_tooltips(engine, panel->buttons);
}