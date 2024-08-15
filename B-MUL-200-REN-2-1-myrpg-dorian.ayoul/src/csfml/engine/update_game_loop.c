/*
** EPITECH PROJECT, 2021
** create_object.c
** File description:
** Create a game object
*/

#include <rpg/rpg.h>
#include <nep/nmem.h>
#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>

void update_game_loop(engine_t *engine, game_t *game, sfRenderWindow *window)
{
    if (engine->end)
        return;
    if (engine->window != NULL && engine->window->destroyed)
        return;
    gc_sounds(engine, false);
    sfRenderWindow_clear(window, (sfColor){37, 19, 26, 255});
    draw_panels(engine, game);
    tick_panels(engine, game);
    handle_objects_hover(engine);
    sfRenderWindow_display(window);
    ++game->curr_fps;
    if (!engine->panel_changed)
        poll_events(engine, game, window);
    else
        engine->panel_changed = false;
}