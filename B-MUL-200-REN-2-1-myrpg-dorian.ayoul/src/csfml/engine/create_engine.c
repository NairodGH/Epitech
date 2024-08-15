/*
** EPITECH PROJECT, 2021
** create_object.c
** File description:
** Create a game object
*/

#include <nep/nmem.h>
#include <engine.h>

engine_t *create_engine(window_t *window, game_t *game, list_t *panels)
{
    engine_t *engine;

    if (window == NULL)
        return (NULL);
    engine = ncalloc(1, sizeof(engine_t));
    engine->window = window;
    engine->panels = panels;
    engine->game = game;
    engine->panel_changed = false;
    engine->sounds = NULL;
    engine->last_panel = NULL;
    engine->end = false;
    engine->lastclick = sfClock_create();
    return (engine);
}