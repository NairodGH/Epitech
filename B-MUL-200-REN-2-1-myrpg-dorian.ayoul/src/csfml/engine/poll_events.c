/*
** EPITECH PROJECT, 2021
** poll_events.c
** File description:
** Poll events (builtin & panel events)
*/

#include <nep/nmem.h>
#include <engine.h>
#include <panel.h>

void poll_events(engine_t *engine, game_t *game, sfRenderWindow *window)
{
    while (!engine->end && sfRenderWindow_pollEvent(window, &engine->event)) {
        handle_builtin_events(engine, game, engine->event);
        if (engine->end)
            return;
        call_panel_events(engine, game, engine->event);
    }
}