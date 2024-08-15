/*
** EPITECH PROJECT, 2021
** create_object.c
** File description:
** Create a game object
*/

#include <rpg/rpg.h>
#include <nep/nmem.h>
#include <engine.h>
#include <sounds.h>
#include <stdio.h>

void start_engine(engine_t *engine, game_t *game)
{
    sfRenderWindow *window;

    if (engine == NULL)
        return;
    window = get_window(engine);
    if (window == NULL)
        return;
    while (!engine->end && sfRenderWindow_isOpen(window))
        update_game_loop(engine, game, window);
    gc_sounds(engine, true);
}