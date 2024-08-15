/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init end panel
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

void init_end_menu(engine_t *eng UNUSED, game_t *game UNUSED, panel_t *panel)
{
    sfIntRect rct = {0, 0, 960, 540};
    obj_t *b = create_object("assets/end/bg.png", rct, (sfVector2f){0, 0});

    register_object(panel, b);
    init_buttons_credits(panel);
    init_buttons_home(panel);
    set_panel_visibility(panel, true);
}

void init_panel_end(engine_t *eng, game_t *game)
{
    panel_t *panel = create_panel(GAME_END);

    (void) game;
    set_panel_initializer(panel, &init_end_menu, NULL);
    register_panel(eng, panel);
}