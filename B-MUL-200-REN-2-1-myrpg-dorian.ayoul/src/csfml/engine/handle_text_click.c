/*
** EPITECH PROJECT, 2021
** handle_object_click.c
** File description:
** Handle object click
*/

#include <nep/nmem.h>
#include <panel.h>
#include <texts.h>
#include <sounds.h>

PRIVATE void handle_text_click(ENGPANEL, txt_t *txt)
{
    sfInt64 it;

    if (txt == NULL || txt->on_click == NULL || !txt->visibility)
        return;
    it = sfClock_getElapsedTime(engine->lastclick).microseconds / 1000;
    if (it < 500)
        return;
    play_seffect(engine->game, engine, "assets/sounds/b-click.ogg");
    txt->on_click(engine, game, panel, txt);
    sfClock_restart(engine->lastclick);
}

PRIVATE bool handle_panel_texts(ENGPANEL, sfVector2i mouse)
{
    txt_t *txt;

    if (!is_panel_visible(panel) || panel->texts == NULL)
        return (false);
    list_foreach(panel->texts, txt_node) {
        txt = (txt_t *) txt_node->value;
        if (!is_text_clicked(txt, mouse))
            continue;
        handle_text_click(engine, game, panel, txt);
        return (true);
    }
    return (false);
}

void handle_texts_click(engine_t *engine, game_t *game, sfVector2i mouse)
{
    panel_t *panel;
    bool clicked = false;

    if (engine == NULL || engine->panels == NULL)
        return;
    list_foreach(engine->panels, node) {
        panel = (panel_t *) node->value;
        if (!is_panel_visible(panel))
            continue;
        clicked = handle_panel_texts(engine, game, panel, mouse);
        if (clicked)
            return;
    }
}