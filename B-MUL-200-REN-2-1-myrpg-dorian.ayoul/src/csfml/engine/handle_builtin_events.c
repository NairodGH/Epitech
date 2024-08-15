/*
** EPITECH PROJECT, 2021
** create_object.c
** File description:
** Create a game object
*/

#include <nep/nmem.h>
#include <rpg/rpg.h>
#include <engine.h>
#include <buttons.h>
#include <sounds.h>

PRIVATE void handle_builtin_clicks(engine_t *engine, game_t *game, sfEvent ev)
{
    sfVector2i mouse = (sfVector2i) {ev.mouseButton.x, ev.mouseButton.y};

    handle_buttons_click(engine, game, mouse);
    handle_objects_click(engine, game, mouse);
    handle_texts_click(engine, game, mouse);
}

void handle_builtin_events(engine_t *engine, game_t *game, sfEvent event)
{

    if (engine == NULL)
        return;
    if (event.type == sfEvtClosed) {
        gc_sounds(engine, true);
        destroy_engine(engine);
        return;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF2)
        take_screenshot(engine);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        remove_button_click(engine);
    if (event.type == sfEvtMouseButtonPressed)
        handle_builtin_clicks(engine, game, event);
}