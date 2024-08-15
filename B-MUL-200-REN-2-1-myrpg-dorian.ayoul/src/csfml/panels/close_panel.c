/*
** EPITECH PROJECT, 2021
** close_panel.c
** File description:
** Close panel
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>
#include <objects.h>
#include <buttons.h>
#include <texts.h>
#include <sounds.h>

PRIVATE void stop_panel_sound(panel_t *panel)
{
    if (!panel || !panel->bg_sound)
        return;
    stop_sound(panel->bg_sound);
}

PRIVATE void destroy_panel_elements(panel_t *panel)
{
    if (panel == NULL)
        return;
    destroy_objects(panel->objects);
    destroy_buttons(panel->buttons);
    destroy_texts(panel->texts);
    stop_panel_sound(panel);
    if (panel->objects != NULL)
        list_free(panel->objects);
    if (panel->texts != NULL)
        list_free(panel->texts);
    if (panel->buttons != NULL)
        list_free(panel->buttons);
    panel->objects = NULL;
    panel->texts = NULL;
    panel->buttons = NULL;
}

void close_panel(engine_t *engine, game_t *game, panel_t *panel)
{
    if (engine == NULL || panel == NULL)
        return;
    set_panel_visibility(panel, false);
    panel->init = false;
    if (panel->on_destroy != NULL)
        panel->on_destroy(engine, game, panel);
    destroy_panel_elements(panel);
}