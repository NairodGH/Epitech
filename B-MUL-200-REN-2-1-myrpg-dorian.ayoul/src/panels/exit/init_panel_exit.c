/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init exit panel
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

void init_exit_menu(engine_t *eng UNUSED, game_t *game UNUSED, panel_t *panel)
{
    sfIntRect rct = {0, 0, 960, 540};
    obj_t *b = create_object("assets/mstart/bg.png", rct, (sfVector2f){0, 0});

    register_object(panel, b);
    init_exit_text(panel);
    init_buttons_exit_yes(panel);
    init_buttons_exit_no(panel);
    set_panel_visibility(panel, true);
}

void init_panel_exit(engine_t *eng, game_t *game)
{
    panel_t *panel = create_panel(EXIT_CONFIRMATION);

    (void) game;
    set_panel_initializer(panel, &init_exit_menu, NULL);
    register_panel(eng, panel);
}