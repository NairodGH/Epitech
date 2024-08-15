/*
** EPITECH PROJECT, 2021
** create_object.c
** File description:
** Create a game object
*/

#include <nep/nmem.h>
#include <buttons.h>
#include <panel.h>
#include <sounds.h>

PRIVATE void handle_button_click(ENGPANEL, button_t *btn)
{
    sfInt64 it;

    if (btn == NULL || btn->on_click == NULL || !btn->is_visible)
        return;
    it = sfClock_getElapsedTime(engine->lastclick).microseconds / 1000;
    if (it < 100)
        return;
    play_seffect(engine->game, engine, "assets/sounds/b-click.ogg");
    btn->on_click(engine, game, panel, btn);
    sfClock_restart(engine->lastclick);
}

PRIVATE bool handle_panel_buttons(ENGPANEL, sfVector2i mouse)
{
    button_t *btn;

    if (!is_panel_visible(panel) || panel->buttons == NULL)
        return (false);
    list_foreach(panel->buttons, btn_node) {
        btn = (button_t *) btn_node->value;
        if (!get_button_hovered(engine, btn, mouse)) {
            btn->is_clicked = false;
            continue;
        }
        handle_button_click(engine, game, panel, btn);
        return (true);
    }
    return (false);
}

void handle_buttons_click(engine_t *engine, game_t *game, sfVector2i mouse)
{
    panel_t *panel;
    bool clicked = false;

    if (engine == NULL || engine->panels == NULL)
        return;
    list_foreach(engine->panels, node) {
        panel = (panel_t *) node->value;
        if (!is_panel_visible(panel))
            continue;
        clicked = handle_panel_buttons(engine, game, panel, mouse);
        if (clicked)
            return;
    }
}

void remove_button_click(engine_t *engine)
{
    panel_t *panel;
    button_t *btn;

    if (engine == NULL || engine->panels == NULL)
        return;
    list_foreach(engine->panels, node) {
        panel = (panel_t *) node->value;
        if (!is_panel_visible(panel) || panel->buttons == NULL)
            continue;
        list_foreach(panel->buttons, btn_node) {
            btn = (button_t *) btn_node->value;
            btn->is_clicked = false;
        }
    }
}